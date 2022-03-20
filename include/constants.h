#include <Arduino.h>

#ifndef CONSTANTS
#define CONSTANTS

// LEDs
const int LED_1 = 0;
const int LED_2 = 1;

// Buttons
const int BUTTON_1 = 2;
const int BUTTON_2 = 3;
const int BUTTON_3 = 4;

const int BUTTONS[] = { BUTTON_1, BUTTON_2, BUTTON_3 };

// 4 Digit 7 Segment Display
//  ---a---
// |       |
// f       b
// |       |
//  ---g---
// |       |
// e       c
// |       |
//  ---d---  o
const int DISPLAY_SEGMENT_A = 6;
const int DISPLAY_SEGMENT_B = 7;
const int DISPLAY_SEGMENT_C = 8;
const int DISPLAY_SEGMENT_D = 9;
const int DISPLAY_SEGMENT_E = 10;
const int DISPLAY_SEGMENT_F = 11;
const int DISPLAY_SEGMENT_G = 12;
const int DISPLAY_SEGMENT_DP = 13; // DECIMAL POINT
const int SEGMENTS[] = { DISPLAY_SEGMENT_A, DISPLAY_SEGMENT_B, DISPLAY_SEGMENT_C, DISPLAY_SEGMENT_D, DISPLAY_SEGMENT_E,
    DISPLAY_SEGMENT_F, DISPLAY_SEGMENT_G, DISPLAY_SEGMENT_DP };

const int DISPLAY_DIGIT_1 = 14;
const int DISPLAY_DIGIT_2 = 15;
const int DISPLAY_DIGIT_3 = 16;
const int DISPLAY_DIGIT_4 = 17;
const int DIGITS[] = { DISPLAY_DIGIT_1, DISPLAY_DIGIT_2, DISPLAY_DIGIT_3, DISPLAY_DIGIT_4 };

// Speaker
const int SPEAKER = 5;

// States
const int STATE_INITIALIZE = 1;
const int STATE_SETUP_TIME = 2;
const int STATE_SETUP_SEED = 3;
const int STATE_SHOW_SERIAL = 7;
const int STATE_READY = 4;
const int STATE_RUNNING = 5;
const int STATE_FINISHED = 6;

// Misc constants
const unsigned long DEBOUNCE_DELAY = 50;
const unsigned long HOLD_BUTTON_DELAY = 300;
const unsigned long HELD_COUNT_DELAY = 20;

const int SERIAL_NUMBER_CHARACTERS_COUNT = 25;
const int SERIAL_NUMBER_CONSONANTS[] = { 1, 2, 4, 5, 7, 8, 10, 11, 13, 14 };
const int SERIAL_NUMBER_CONSONANTS_COUNT = 10;
const int SERIAL_NUMBER_VOWELS[] = { 0, 3, 6, 9, 12 };
const int SERIAL_NUMBER_VOWELS_COUNT = 5;
const int SERIAL_NUMBER_NUMBERS_EVEN[] = { 15, 17, 19, 21, 23 };
const int SERIAL_NUMBER_NUMBERS_EVEN_COUNT = 5;
const int SERIAL_NUMBER_NUMBERS_ODD[] = { 16, 18, 20, 22, 24 };
const int SERIAL_NUMBER_NUMBERS_ODD_COUNT = 5;
const int SERIAL_NUMBER_NUMBERS[] = { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
const int SERIAL_NUMBER_NUMBERS_COUNT = 10;
const byte SERIAL_LAST_DIGIT_ODD = 0b1;
const byte SERIAL_CONTAINS_VOWEL = 0b10;

const int MAX_STRIKES = 2;
const int MAX_MODULES = 11;

const byte MODULE_STATUS_SOLVED = 0b1;
const byte MODULE_STATUS_STRIKE = 0b10;
const byte MODULE_STATUS_REQUEST_TIME = 0b100;

// 7 Segment Symbols
const int SEGMENT_NUMBERS[10][8]
    = { { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW }, { LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW },
          { HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW }, { HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW },
          { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW }, { HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW },
          { HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW }, { HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW },
          { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW }, { HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW } };

const int SERIAL_NUMBER_CHARACTERS_SEGMENTS[25][8] = {
    // A
    { HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW },
    // B
    { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW },
    // C
    { HIGH, LOW, LOW, HIGH, HIGH, HIGH, LOW, LOW },
    // E
    { HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW },
    // F
    { HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW },
    // H
    { LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW },
    // I
    { LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW },
    // L
    { LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, LOW },
    // N
    { LOW, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW },
    // O
    { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW },
    // P
    { HIGH, HIGH, LOW, LOW, HIGH, HIGH, HIGH, LOW },
    // S
    { HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW },
    // U
    { LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW },
    // Y
    { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW },
    // Z
    { HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW },
    // 0
    { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH },
    // 1
    { LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH },
    // 2
    { HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH },
    // 3
    { HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH },
    // 4
    { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, HIGH },
    // 5
    { HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH },
    // 6
    { HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH },
    // 7
    { HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH },
    // 8
    { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH },
    // 9
    { HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH }
};

const int EMPTY_DIGIT[8] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };

#endif
