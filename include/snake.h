#pragma once

#include <Arduino.h>
#include "game.h"

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

struct Segment {
    int x;
    int y;
};

class Snake : public Game {
    const int SNAKE_SEGMENT_SIZE = 10;
    const int SNAKE_SPEED = 5;
    const int FOOD_SIZE = 8;
    const int INITIAL_SEGMENTS = 5;
    const int MAX_SEGMENTS = 15;
    Direction direction = Direction::Right;
    int foodX = static_cast<int>(random(0, DISPLAY_WIDTH - FOOD_SIZE));
    int foodY = static_cast<int>(random(0, DISPLAY_HEIGHT - FOOD_SIZE));
    bool eaten = false;
    int segments = INITIAL_SEGMENTS;
    Segment *snake;
public:
    Snake(const char *name, Adafruit_ST7735 &tft, UserInput &userInput)
            : Game(name, tft, userInput), snake(new Segment[MAX_SEGMENTS]) {
        snake[0].x = DISPLAY_WIDTH / 2;
        snake[0].y = DISPLAY_HEIGHT / 2;
    };

    ~Snake() {
        delete[] snake; // Free the memory for snake
    }

    void play(Adafruit_ST7735 &tft, UserInput &userInput) override;
};
