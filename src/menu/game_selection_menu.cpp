#include <Arduino.h>
#include "game_selection_menu.h"

void GameSelectionMenu::init() {
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);

    resetHighlighting();

    highlightItem();
}

void GameSelectionMenu::update() {
    if (userInput.isButtonFPressed()) {
        playing = false;
        tft.fillScreen(ST7735_BLACK);
        return;
    }
    if (userInput.isButtonBPressed()) {
        playing = true;
    }
    if (!playing) {
        if (userInput.isButtonCPressed()) {
            selectedIndex++;
            if (selectedIndex >= numItems) {
                selectedIndex = 0;
            }
        } else if (userInput.isButtonAPressed()) {
            selectedIndex--;
            if (selectedIndex < 0) {
                selectedIndex = numItems - 1;
            }
        }

        resetHighlighting();

        highlightItem();
    } else {
        items[selectedIndex].gameInstance->play(tft, userInput);
    }
    delay(50);
}

void GameSelectionMenu::highlightItem() {
    for (int i = 0; i < numItems; i++) {
        if (i == selectedIndex) {
            tft.setTextColor(ST77XX_RED);
        } else {
            tft.setTextColor(ST77XX_WHITE);
        }
        tft.println(items[i].title);
    }
}

void GameSelectionMenu::resetHighlighting() {
    tft.setCursor(0, 0);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    tft.setTextWrap(true);
    tft.setRotation(3);
}


