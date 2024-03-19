#include "snake.h"
#include "game.h"

void Snake::play(Adafruit_ST7735 &tft, UserInput &userInput) {
    resetScreen(tft);

    for (int i = segments - 1; i > 0; i--) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }

    if (eaten) {
        foodX = static_cast<int>(random(0 + FOOD_SIZE, DISPLAY_WIDTH - FOOD_SIZE));
        foodY = static_cast<int>(random(0 + FOOD_SIZE, DISPLAY_HEIGHT - FOOD_SIZE));
        if (segments < MAX_SEGMENTS) {
            segments++;
        }
        eaten = false;
    }

    tft.fillRect(foodX, foodY, FOOD_SIZE, FOOD_SIZE, ST7735_RED);

    if (snake[0].x >= DISPLAY_WIDTH || snake[0].x < 0 || snake[0].y >= DISPLAY_HEIGHT || snake[0].y < 0) {
        for (int i = 0; i < MAX_SEGMENTS; i++) {  // Reset all segments
            snake[i].x = DISPLAY_WIDTH / 2;
            snake[i].y = DISPLAY_HEIGHT / 2;
        }
        segments = INITIAL_SEGMENTS;
        delay(1000);
    }
    if (snake[0].x < foodX + FOOD_SIZE && snake[0].x + SNAKE_SEGMENT_SIZE > foodX && snake[0].y < foodY + FOOD_SIZE &&
        snake[0].y + SNAKE_SEGMENT_SIZE > foodY) {
        eaten = true;
    }

    if (userInput.isButtonAPressed() && direction != Direction::Down) {
        direction = Direction::Up;
    } else if (userInput.isButtonDPressed() && direction != Direction::Right) {
        direction = Direction::Left;
    } else if (userInput.isButtonBPressed() && direction != Direction::Left) {
        direction = Direction::Right;
    } else if (userInput.isButtonCPressed() && direction != Direction::Up) {
        direction = Direction::Down;
    }

    if (direction == Direction::Up) {
        snake[0].y -= SNAKE_SPEED;
    } else if (direction == Direction::Down) {
        snake[0].y += SNAKE_SPEED;
    } else if (direction == Direction::Left) {
        snake[0].x -= SNAKE_SPEED;
    } else if (direction == Direction::Right) {
        snake[0].x += SNAKE_SPEED;
    }

    for (int i = 0; i < segments; i++) {
        tft.fillRect(snake[i].x, snake[i].y, SNAKE_SEGMENT_SIZE, SNAKE_SEGMENT_SIZE, ST7735_GREEN);
    }

}


