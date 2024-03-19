#include "user_input.h"

void UserInput::init() const {
    // Set button pins as inputs and enable internal pull-up resistors
    pinMode(BUTTON_A, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
    pinMode(BUTTON_C, INPUT_PULLUP);
    pinMode(BUTTON_D, INPUT_PULLUP);
    pinMode(BUTTON_E, INPUT_PULLUP);
    pinMode(BUTTON_F, INPUT_PULLUP);
    pinMode(BUTTON_K, INPUT_PULLUP);
}

bool UserInput::isButtonAPressed() const {
    return !digitalRead(BUTTON_A);
}

bool UserInput::isButtonBPressed() const {
    return !digitalRead(BUTTON_B);
}

bool UserInput::isButtonCPressed() const {
    return !digitalRead(BUTTON_C);
}

bool UserInput::isButtonDPressed() const {
    return !digitalRead(BUTTON_D);
}

bool UserInput::isButtonEPressed() const {
    return !digitalRead(BUTTON_E);
}

bool UserInput::isButtonFPressed() const {
    return !digitalRead(BUTTON_F);
}

bool UserInput::isButtonKPressed() const {
    return !digitalRead(BUTTON_K);
}

int UserInput::getJoystickX() const {
    return analogRead(PIN_JOYSTICK_X);
}

int UserInput::getJoystickY() const {
    return analogRead(PIN_JOYSTICK_Y);
}

int UserInput::getPotentiometerValue() const {
    return static_cast<int>(map(analogRead(POTENTIOMETER_PIN), 0, 1023, 0, 100));
}

