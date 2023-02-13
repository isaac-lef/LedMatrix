// Source : https://create.arduino.cc/projecthub/shahbaz75sb/8x8-led-matrix-interfacing-with-arduino-daec65

#include "LedMatrix.h"
#include "Tetrominoes.h"

uint8_t rowPins[] = {
  10, A4, 2, 13, 9, 3, 8, 5
};

uint8_t columnPins[] = {
  A5, 7, 6, 11, 4, 12, A3, A2
};

LedMatrix matrix = LedMatrix(rowPins, columnPins);

void setup() {
  // Open serial port
  Serial.begin(9600);
}

int counter = 0;
int tetrominoId = 0;

void loop() {
  counter++;
  if (counter > 10000) {
    counter = 0;
    tetrominoId = (tetrominoId + 1) % NB_TETROMINOES;
    displayTetromino(matrix, tetrominoId);
  }
  matrix.update();
}
