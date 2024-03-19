#pragma once

#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include "user_input.h"

class Game {
protected:
    const int DISPLAY_WIDTH = 160;
    const int DISPLAY_HEIGHT = 128;
    const char *name;
    Adafruit_ST7735 &tft;
    UserInput &userInput;
public:
    explicit Game(const char *name, Adafruit_ST7735 &tft, UserInput &userInput) : name(name), tft(tft),
                                                                                  userInput(userInput) {}

    const char *getName() const;

    virtual void play(Adafruit_ST7735 &tft, UserInput &userInput) = 0;

    static void resetScreen(Adafruit_ST7735 &tft);
};

