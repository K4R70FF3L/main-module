#include "buttons.h"
#include "constants.h"
#include "display.h"
#include "state.h"
#include <Arduino.h>
#include <Wire.h>

// Variables
int state;

void setup()
{
    // Initialize LEDs
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);

    // Initialize Buttons
    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);

    // Initialize Display
    pinMode(DISPLAY_DIGIT_1, OUTPUT);
    pinMode(DISPLAY_DIGIT_2, OUTPUT);
    pinMode(DISPLAY_DIGIT_3, OUTPUT);
    pinMode(DISPLAY_DIGIT_4, OUTPUT);
    digitalWrite(DISPLAY_DIGIT_1, HIGH);
    digitalWrite(DISPLAY_DIGIT_2, HIGH);
    digitalWrite(DISPLAY_DIGIT_3, HIGH);
    digitalWrite(DISPLAY_DIGIT_4, HIGH);

    pinMode(DISPLAY_SEGMENT_A, OUTPUT);
    pinMode(DISPLAY_SEGMENT_B, OUTPUT);
    pinMode(DISPLAY_SEGMENT_C, OUTPUT);
    pinMode(DISPLAY_SEGMENT_D, OUTPUT);
    pinMode(DISPLAY_SEGMENT_E, OUTPUT);
    pinMode(DISPLAY_SEGMENT_F, OUTPUT);
    pinMode(DISPLAY_SEGMENT_G, OUTPUT);
    pinMode(DISPLAY_SEGMENT_DP, OUTPUT);
    digitalWrite(DISPLAY_SEGMENT_A, LOW);
    digitalWrite(DISPLAY_SEGMENT_B, LOW);
    digitalWrite(DISPLAY_SEGMENT_C, LOW);
    digitalWrite(DISPLAY_SEGMENT_D, LOW);
    digitalWrite(DISPLAY_SEGMENT_E, LOW);
    digitalWrite(DISPLAY_SEGMENT_F, LOW);
    digitalWrite(DISPLAY_SEGMENT_G, LOW);
    digitalWrite(DISPLAY_SEGMENT_DP, LOW);

    // Set beginning state
    state = STATE_INITIALIZE;
    Wire.begin();
}

void loop()
{
    switch (state) {
    case STATE_INITIALIZE:
        state = initialize();
        break;
    case STATE_SETUP_SEED:
        state = setupSeed();
        break;
    case STATE_SETUP_TIME:
        state = setupTime();
        break;
    case STATE_SHOW_SERIAL:
        state = showSerial();
        break;
    case STATE_READY:
        state = ready();
        break;
    case STATE_RUNNING:
        state = running();
        break;
    case STATE_FINISHED:
        state = finished();
        break;
    }
    handleButtons();
    handleDisplay();
}
