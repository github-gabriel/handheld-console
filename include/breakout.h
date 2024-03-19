#pragma once

#include <Arduino.h>
#include "game.h"

class Breakout : public Game {
public:
    Breakout(const char *name, Adafruit_ST7735 &tft, UserInput &userInput)
            : Game(name, tft, userInput) {};

    void play(Adafruit_ST7735 &tft, UserInput &userInput) override;
};
