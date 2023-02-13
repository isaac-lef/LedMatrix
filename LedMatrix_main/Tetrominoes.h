#ifndef TETROMINOES
#define TETROMINOES

#include "LedMatrix.h"

const int NB_TETROMINOES = 7;

const bool i_tetromino[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0}
};

const bool j_tetromino[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0}
};

const bool l_tetromino[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0}
};

const bool o_tetromino[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

const bool s_tetromino[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,1,1,1,0},
  {0,0,0,1,1,1,1,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

const bool t_tetromino[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

const bool z_tetromino[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,0,1,1,1,1,0},
  {0,0,0,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

void printTetromino(bool tetromino[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      Serial.print(tetromino[i][j] ? '1' : '0');
      if (j < 7) {
        Serial.print(' ');
      }
    }
    Serial.println();
  }
}

// To iterate over tetrominoes
void displayTetromino(LedMatrix& matrix, int tetrominoId) {
  switch(tetrominoId) {
    case 0:
      matrix.display(i_tetromino);
      break;
    case 1:
      matrix.display(j_tetromino);
      break;
    case 2:
      matrix.display(l_tetromino);
      break;
    case 3:
      matrix.display(o_tetromino);
      break;
    case 4:
      matrix.display(s_tetromino);
      break;
    case 5:
      matrix.display(t_tetromino);
      break;
    case 6:
      matrix.display(z_tetromino);
      break;
    default:
      // should probably show error
      break;
  }
}

#endif
