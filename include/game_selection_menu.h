#pragma once

#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include "user_input.h"
#include "game.h"

struct MenuItem {
    const char *title;
    Game *gameInstance;
};

class GameSelectionMenu {
    UserInput userInput;
    Adafruit_ST7735 tft;
    const MenuItem *items;
    int numItems;
    int selectedIndex = 0;
    bool playing = false;

    void highlightItem();

    void resetHighlighting();

public:
    GameSelectionMenu(Adafruit_ST7735 &tft, UserInput &userInput, const MenuItem items[], int numItems)
            : userInput(userInput), tft(tft), items(items), numItems(numItems) {}

    void init();

    void update();
};

