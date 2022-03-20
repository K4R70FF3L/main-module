#include "buttons.h"
#include "constants.h"
#include "display.h"
#include "serialNumber.h"
#include <Arduino.h>
#include <Wire.h>

int* serialNumber;
int strikes = 0;
int seed = 0;
byte serialFlags = 0;
unsigned long time = 300000;

int initialize()
{
    seed = (seed + 1) % 10000;
    if (buttonPressed(BUTTON_2)) {
        return STATE_SETUP_SEED;
    }
    return STATE_INITIALIZE;
}

unsigned long lastHeldIncrement = 0;

int setupSeed()
{
    if (buttonPressed(BUTTON_1)) {
        seed = (seed - 1) % 10000;
    } else if (buttonHeld(BUTTON_1)) {
        unsigned long currentMillis = millis();
        if (lastHeldIncrement + HELD_COUNT_DELAY < currentMillis) {
            lastHeldIncrement = currentMillis;
            seed = (seed - 1) % 10000;
        }
    }
    if (buttonPressed(BUTTON_3)) {
        seed = (seed + 1) % 10000;
    } else if (buttonHeld(BUTTON_3)) {
        unsigned long currentMillis = millis();
        if (lastHeldIncrement + HELD_COUNT_DELAY < currentMillis) {
            lastHeldIncrement = currentMillis;
            seed = (seed + 1) % 10000;
        }
    }
    if (buttonPressed(BUTTON_2)) {
        randomSeed(seed);
        serialFlags = generateSerialConfig();
        serialNumber = generateSerialNumber(serialFlags);
        clearDisplay();
        return STATE_SETUP_TIME;
    }
    displayNumber(seed);
    return STATE_SETUP_SEED;
}

int setupTime()
{
    if (buttonPressed(BUTTON_1)) {
        if (time > 0) {
            time -= 5000;
        }
    }
    if (buttonPressed(BUTTON_3)) {
        time += 5000;
    }
    if (buttonPressed(BUTTON_2)) {
        clearDisplay();
        return STATE_SHOW_SERIAL;
    }
    displayTime(time);
    return STATE_SETUP_TIME;
}

int serialHalfToShow = 0;

int showSerial()
{
    if (buttonPressed(BUTTON_1)) {
        serialHalfToShow = 0;
    }
    if (buttonPressed(BUTTON_3)) {
        serialHalfToShow = 4;
    }
    if (buttonPressed(BUTTON_2)) {
        clearDisplay();
        return STATE_READY;
    }
    displaySerial(&serialNumber[serialHalfToShow]);
    return STATE_SHOW_SERIAL;
}

unsigned long remainingTime = 0;
unsigned long lastCycle;
int moduleCount = 0;
bool solvedModules[MAX_MODULES] = { true, true, true, true, true, true, true, true, true, true, true };

int ready()
{
    Wire.beginTransmission(8);
    Wire.write(moduleCount + 9);
    byte transmissionStatus = Wire.endTransmission();
    if (transmissionStatus == 0) {
        do {
            Wire.beginTransmission(moduleCount + 9);
            Wire.write((byte)seed);
            Wire.write((byte)(seed >> 8));
            Wire.write(serialFlags);
            transmissionStatus = Wire.endTransmission();
        } while (transmissionStatus != 0);
        ++moduleCount;
    }

    if (buttonPressed(BUTTON_2)) {
        for (int index = 0; index < moduleCount; ++index) {
            solvedModules[index] = false;
        }
        remainingTime = time;
        lastCycle = millis();
        return STATE_RUNNING;
    }
    displayNumber(moduleCount);
    return STATE_READY;
}

bool strike()
{
    ++strikes;
    switch (strikes) {
    case 1:
        digitalWrite(LED_1, HIGH);
        return false;
        break;
    case 2:
        digitalWrite(LED_2, HIGH);
        return false;
        break;
    case 3:
        return true;
        break;
    }
}

int running()
{
    unsigned long currentCycle = millis();
    remainingTime -= currentCycle - lastCycle;
    lastCycle = currentCycle;
    bool allModulesSolved = true;

    for (int index = 0; index < moduleCount; ++index) {
        if (solvedModules[index]) {
            continue;
        }
        allModulesSolved = false;
        int bytesReceived = Wire.requestFrom(index + 9, 1);
        if (bytesReceived == 0) {
            allModulesSolved = false;
            continue;
        }
        byte moduleStatus = Wire.read();
        if ((moduleStatus & MODULE_STATUS_STRIKE) > 0) {
            if (strike()) {
                displayNumber(8888);
                return STATE_FINISHED;
            }
        }

        if ((moduleStatus & MODULE_STATUS_SOLVED) > 0) {
            solvedModules[index] = true;
            continue;
        }

        if ((moduleStatus & MODULE_STATUS_REQUEST_TIME) > 0) {
            Wire.beginTransmission(index + 9);
            Wire.write((byte)(remainingTime >> 24));
            Wire.write((byte)(remainingTime >> 16));
            Wire.write((byte)(remainingTime >> 8));
            Wire.write((byte)(remainingTime));
            Wire.endTransmission();
        }
        allModulesSolved = false;
    }

    if (allModulesSolved) {
        return STATE_FINISHED;
    }

    displayTime(remainingTime);
    if (remainingTime <= 0 || remainingTime > time) {
        displayNumber(8888);
        return STATE_FINISHED;
    }
    return STATE_RUNNING;
}

int finished() { return STATE_FINISHED; }
