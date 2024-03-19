#pragma once

#include <Arduino.h>

class UserInput {
    const byte BUTTON_A = 2;
    const byte BUTTON_B = 3;
    const byte BUTTON_C = 4;
    const byte BUTTON_D = 5;
    const byte BUTTON_E = 6;
    const byte BUTTON_F = 7;
    const byte BUTTON_K = 8;
    const byte PIN_JOYSTICK_X = 0;
    const byte PIN_JOYSTICK_Y = 1;
    const int POTENTIOMETER_PIN = A3;
public:
    void init() const;

    bool isButtonAPressed() const;

    bool isButtonBPressed() const;

    bool isButtonCPressed() const;

    bool isButtonDPressed() const;

    bool isButtonEPressed() const;

    bool isButtonFPressed() const;

    bool isButtonKPressed() const;

    int getJoystickX() const;

    int getJoystickY() const;

    int getPotentiometerValue() const;
};
