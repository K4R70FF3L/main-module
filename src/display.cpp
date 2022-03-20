#include "constants.h"
#include <Arduino.h>

int currentDigit = 0;

int digits[4][8] = { { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW }, { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW },
    { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW }, { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW } };

void displayNumber(int number)
{
    for (int digit = 3; digit >= 0; digit--) {
        for (int segment = 0; segment < 8; ++segment) {
            digits[digit][segment] = SEGMENT_NUMBERS[number % 10][segment];
        }
        number /= 10;
    }
}

void displayTime(unsigned long time)
{
    if (time < 10000) {
        displayNumber(time);
        digits[0][7] = HIGH;
    } else {
        time = time / 1000;
        int minutes = time / 60;
        int seconds = time % 60;
        for (int digit = 3; digit >= 2; digit--) {
            for (int segment = 0; segment < 8; ++segment) {
                digits[digit][segment] = SEGMENT_NUMBERS[seconds % 10][segment];
            }
            seconds /= 10;
        }
        for (int digit = 1; digit >= 0; digit--) {
            for (int segment = 0; segment < 8; ++segment) {
                digits[digit][segment] = SEGMENT_NUMBERS[minutes % 10][segment];
            }
            minutes /= 10;
        }
        digits[1][7] = HIGH;
    }
}

void displaySerial(int* serial)
{
    for (int digit = 0; digit < 4; ++digit) {
        for (int segment = 0; segment < 8; ++segment) {
            digits[digit][segment] = SERIAL_NUMBER_CHARACTERS_SEGMENTS[serial[digit]][segment];
        }
    }
}

void handleDisplay()
{
    digitalWrite(DIGITS[currentDigit], HIGH);
    currentDigit = ++currentDigit % 4;
    for (int segment = 0; segment < 8; ++segment) {
        digitalWrite(SEGMENTS[segment], digits[currentDigit][segment]);
    }
    digitalWrite(DIGITS[currentDigit], LOW);
}

void clearDisplay()
{
    for (int digit = 0; digit < 4; ++digit) {
        for (int segment = 0; segment < 8; ++segment) {
            digits[digit][segment] = EMPTY_DIGIT[segment];
        }
    }
}