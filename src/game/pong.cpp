#include "pong.h"
#include "game.h"

void Pong::play(Adafruit_ST7735 &tft, UserInput &userInput) {
    resetScreen(tft);

    // Player paddle
    int playerPaddleY = static_cast<int>(DISPLAY_HEIGHT - PADDLE_HEIGHT -
                                         map(userInput.getJoystickY(), 0, 1023, 0, DISPLAY_HEIGHT - PADDLE_HEIGHT));

    tft.fillRect(0, playerPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, ST7735_WHITE);

    // Enemy paddle
    int enemyPaddleY = static_cast<int>(map(ballY, 0, DISPLAY_HEIGHT, 0, DISPLAY_HEIGHT - PADDLE_HEIGHT));
    tft.fillRect(DISPLAY_WIDTH - PADDLE_WIDTH, enemyPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, ST7735_RED);

    // Border collision
    if (ballY >= DISPLAY_HEIGHT || ballY <= 0) {
        ballYDir *= -1;
    }
    if (ballX >= DISPLAY_WIDTH) { // Player scores
        ballX = DISPLAY_WIDTH / 2;
        ballY = DISPLAY_HEIGHT / 2;
        ballXDir = -BALL_SPEED;
        ballYDir = -BALL_SPEED;
        playerPaddleY = DISPLAY_HEIGHT / 2;
        enemyPaddleY = DISPLAY_HEIGHT / 2;

        resetScreen(tft);

        tft.fillRect(0, playerPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, ST7735_WHITE);
        tft.fillRect(DISPLAY_WIDTH - PADDLE_WIDTH, enemyPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, ST7735_RED);
        delay(1000);
    } else if (ballX <= 0) { // Enemy scores
        ballX = DISPLAY_WIDTH / 2;
        ballY = DISPLAY_HEIGHT / 2;
        ballXDir = BALL_SPEED;
        ballYDir = BALL_SPEED;
        playerPaddleY = DISPLAY_HEIGHT / 2;
        enemyPaddleY = DISPLAY_HEIGHT / 2;

        resetScreen(tft);

        tft.fillRect(0, playerPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, ST7735_WHITE);
        tft.fillRect(DISPLAY_WIDTH - PADDLE_WIDTH, enemyPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, ST7735_RED);
        delay(1000);
    }

    // Paddle collision
    if ((ballX < PADDLE_WIDTH + BALL_SIZE && ballX > 0) &&
        (ballY < playerPaddleY + PADDLE_HEIGHT && ballY > playerPaddleY - PADDLE_HEIGHT)) {
        ballX = 0 + PADDLE_WIDTH + BALL_SIZE;
        ballXDir *= -1;
    } else if ((ballX > DISPLAY_WIDTH - PADDLE_WIDTH - BALL_SIZE && ballX < DISPLAY_WIDTH) &&
               (ballY < enemyPaddleY + PADDLE_HEIGHT && ballY > enemyPaddleY - PADDLE_HEIGHT)) {
        ballX = DISPLAY_WIDTH - PADDLE_WIDTH - BALL_SIZE;
        ballXDir *= -1;
    }

    ballYDir += static_cast<int>(random(-1, 2));

    ballX += ballXDir;
    ballY += ballYDir;

    // Ball
    tft.fillCircle(ballX, ballY, BALL_SIZE / 2, ST7735_BLUE);

    delay(50);
}

