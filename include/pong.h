#pragma once

#include <Arduino.h>
#include "game.h"

class Pong : public Game {
    const int PADDLE_WIDTH = 15;
    const int PADDLE_HEIGHT = 45;
    const int BALL_SIZE = 5;
    const int BALL_SPEED = 10;
    int ballX = DISPLAY_WIDTH / 2;
    int ballY = DISPLAY_HEIGHT / 2;
    int ballXDir = BALL_SPEED;
    int ballYDir = BALL_SPEED;
public:
    Pong(const char *name, Adafruit_ST7735 &tft, UserInput &userInput)
            : Game(name, tft, userInput) {};

    void play(Adafruit_ST7735 &tft, UserInput &userInput) override;
};
