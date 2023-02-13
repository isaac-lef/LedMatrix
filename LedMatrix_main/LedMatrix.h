// Object-oriented driver for an 8x8 LED matrix that comes with an Arduino UNO

#ifndef LEDMATRIX
#define LEDMATRIX

class LedMatrix {
  private:
    const uint8_t* rowPins;
    const uint8_t* columnPins;
    bool pixels[8][8];
    int activeRow = 0;

    void goToNextRow() {
      activeRow = nextRow();
    }

    int nextRow() {
      return (activeRow+1) % NB_ROWS;
    }

    int previousRow() {
      int r = activeRow - 1;
      if (r < 0) return NB_ROWS - 1;
      return r;
    }

    void setRowOn(int rowId) {
      setRow(rowId, ON);
    }

    void setRowOff(int rowId) {
      setRow(rowId, OFF);
    }

    void setRow(int rowId, bool status) {
      int level = status ? HIGH : LOW;
      digitalWrite(rowPins[rowId], level);
    }

    void setColumnOn(int columnId) {
      setColumn(columnId, ON);     
    }

    void setColumnOff(int columnId) {
      setColumn(columnId, OFF);
    }

    void setColumn(int columnId, bool status) {
      int level = status ? LOW : HIGH;    
      digitalWrite(columnPins[columnId], level);  
    }
  
  public:
    static const int NB_ROWS    = 8;
    static const int NB_COLUMNS = 8;
    static const bool ON  = true;
    static const bool OFF = false;

    LedMatrix(uint8_t _rowPins[], uint8_t _columnPins[]) :
      rowPins(_rowPins), columnPins(_columnPins)
    {
      // Initializing pins as output & turning them off
      for (int rowId = 0; rowId < NB_ROWS; rowId++) {
        pinMode(rowPins[rowId], OUTPUT);
        digitalWrite(rowPins[rowId], LOW);
      }
      for (int columnId = 0; columnId < NB_COLUMNS; columnId++) {
        pinMode(columnPins[columnId], OUTPUT);
        digitalWrite(columnPins[columnId], HIGH);
      }
    }

    void print() {
      for (int rowId = 0; rowId < NB_ROWS; rowId++) {
        for (int columnId = 0; columnId < NB_COLUMNS; columnId++) {
          Serial.print(pixels[rowId][columnId]);
          if (columnId < NB_COLUMNS-1) {
            Serial.print(' ');
          }
        }
        Serial.println();
      }
    }

    void setAllOn() {
      for (int rowId = 0; rowId < NB_ROWS; rowId++) {
        for (int columnId = 0; columnId < NB_COLUMNS; columnId++) {
          setPixelOn(rowId, columnId);
        }
      }    
    }

    void setAllOff() {
      for (int rowId = 0; rowId < NB_ROWS; rowId++) {
        for (int columnId = 0; columnId < NB_COLUMNS; columnId++) {
          setPixelOff(rowId, columnId);
        }
      }    
    }

    void setPixelOn(int rowId, int columnId) {
      setPixel(rowId, columnId, ON);
    }

    void setPixelOff(int rowId, int columnId) {
      setPixel(rowId, columnId, OFF);
    }

    void setPixel(int rowId, int columnId, bool status) {
      pixels[rowId][columnId] = status;
    }

    // Moves the cursor and lights the corresponding pixels
    // Should be called in loop()
    void update() {
      setRowOff(previousRow());

      // lighting the pixels of this row that should be on
      for (int columnId = 0; columnId < NB_COLUMNS; columnId++) {
        bool status = pixels[activeRow][columnId];
        setColumn(columnId, status);
      }
      setRowOn(activeRow);

      goToNextRow();
    }

    // Expects an 8x8 matrix of booleans, where true means the LED is set on.
    void display(bool image[8][8]) {
      for (int rowId = 0; rowId < NB_ROWS; rowId++) {
        for (int columnId = 0; columnId < NB_COLUMNS; columnId++) {
          pixels[rowId][columnId] = image[rowId][columnId];
        }
      }
    }

    // Expects a string of 1 (on) and 0 (off), with optional spaces
    // Newline character means next line of the LED matrix
    // There should be 8x8 ones and zeros
    void displayFromText(char* text, int length) {
      int rowId    = 0;
      int columnId = 0;
      char character;
      for (int i = 0; i < length; i++) {
        character = text[i];
        switch(character) {
          case '0':
            setPixelOff(rowId, columnId++);
            break;
          case '1':
            setPixelOn(rowId, columnId++);
            break;
          case '\n':
            rowId++;
            columnId = 0;
            break;
          case ' ':
            // Does nothing, normal behavior.
            break;
          default:
            // Does nothing. Could throw an exception instead...
            break;
        }
      }
    }
};

#endif
