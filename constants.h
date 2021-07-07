#ifndef CONSTANTS
#define CONSTANTS

// LEDs
const int LED_1 = 0;
const int LED_2 = 1;

// Buttons
const int BUTTON_1 = 2;
const int BUTTON_2 = 3;
const int BUTTON_3 = 4;

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
const int DISPLAY_DIGIT_1 = 14;
const int DISPLAY_DIGIT_2 = 15;
const int DISPLAY_DIGIT_3 = 16;
const int DISPLAY_DIGIT_4 = 17;

// Speaker
const int SPEAKER = 5;

// States
const int STATE_INITIALIZE = 1;
const int STATE_SETUP = 2;
const int STATE_READY = 3;
const int STATE_RUNNING = 4;
const int STATE_FINISHED = 5;

// Misc constants
const unsigned long DEBOUNCE_DELAY = 50;

#endif
