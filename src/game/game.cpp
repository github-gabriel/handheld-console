#include "game.h"

const char *Game::getName() const {
    return name;
}

void Game::resetScreen(Adafruit_ST7735 &tft) {
    tft.fillScreen(ST7735_BLACK);
}
