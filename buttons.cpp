#include "constants.h"
#include "stfu.h"

enum ButtonState { unpressed, held, pressed };

extern ButtonState buttonStates[] = { unpressed, unpressed, unpressed };

extern int lastReadStates[] = { HIGH, HIGH, HIGH };

extern unsigned long lastDebounceTimes[] = { 0, 0, 0 };

bool buttonPressed(int button)
{
    bool wasPressed = false;
    switch (button) {
    case BUTTON_1:
        wasPressed = buttonStates[0] == pressed;
        if (wasPressed) {
            buttonStates[0] = unpressed;
        }
        break;
    case BUTTON_2:
        wasPressed = buttonStates[1] == pressed;
        if (wasPressed) {
            buttonStates[1] = unpressed;
        }
        break;
    case BUTTON_3:
        wasPressed = buttonStates[2] == pressed;
        if (wasPressed) {
            buttonStates[2] = unpressed;
        }
        break;
    }
    return wasPressed;
}

bool buttonHeld(int button)
{
    switch (button) {
    case BUTTON_1:
        return buttonStates[0] == held;
        break;
    case BUTTON_2:
        return buttonStates[1] == held;
        break;
    case BUTTON_3:
        return buttonStates[2] == held;
        break;
    default:
        return false;
    }
}

void handleButtons()
{
    unsigned long currentMillis = millis();
    for (int button = 0; button < 3; ++button) {
        if (lastDebounceTimes[button] + DEBOUNCE_DELAY > currentMillis) {
            continue;
        }
        int currentState = digitalRead(BUTTONS[button]);
        if (currentState != lastReadStates[button]) {
            lastDebounceTimes[button] = currentMillis;
            lastReadStates[button] = currentState;
            buttonStates[button] = currentState == HIGH ? unpressed : pressed;
        } else if (currentState == LOW && lastDebounceTimes[button] + HOLD_BUTTON_DELAY < currentMillis) {
            buttonStates[button] = held;
        }
    }
}