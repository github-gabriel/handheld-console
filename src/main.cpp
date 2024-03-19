#include <Arduino.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include "user_input.h"
#include "game_selection_menu.h"
#include "asteroids.h"
#include "pong.h"
#include "space_invaders.h"
#include "snake.h"
#include "breakout.h"

// Potentiometer and buzzer pins
const int BUZZER_PIN = 10;

#define TFT_CS        10
#define TFT_RST        8
#define TFT_DC         9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST); // 128x160

UserInput userInput;

Asteroids asteroids("Asteroids", tft, userInput);
Pong pong("Pong", tft, userInput);
SpaceInvaders spaceInvaders("Space Invaders", tft, userInput);
Snake snake("Snake", tft, userInput);
Breakout breakout("Breakout", tft, userInput);

MenuItem items[] = {
        {asteroids.getName(),     &asteroids},
        {pong.getName(),          &pong},
        {spaceInvaders.getName(), &spaceInvaders},
        {snake.getName(),         &snake},
        {breakout.getName(),      &breakout}
};
GameSelectionMenu gameSelectionMenu(tft, userInput, items, sizeof(items) / sizeof(MenuItem));

void setup() {
    Serial.begin(9600);

    gameSelectionMenu.init();

    userInput.init();
}

void loop() {
    gameSelectionMenu.update();
}

