/*
 * Matrix.h - Library for driving bare LED matrices
 * Created by Andrew Mourcos, Dec 18 2018
 * Must give proper credit for use.
*/
#ifndef Matrix_h
#define Matrix_h

#include "Arduino.h"

class Matrix
{
  private:
    int rowDim;
    int colDim;
    byte *anode;
    byte *cathode;
    bool** values;

  public:
    // default data constructor
    Matrix()
    {
      rowDim = 0;
      colDim = 0;
      anode = nullptr;
      cathode = nullptr;
      values = nullptr;
    }
    // data constructor
    Matrix(int rowDim0, int colDim0)
    {
      rowDim = rowDim0;
      colDim = colDim0;
      // create "2D array"
      values = new bool*[rowDim];
      anode = new byte[rowDim];
      cathode = new byte[colDim];
      
      for(int i=0; i<rowDim; i++){
        values[i] = new bool[colDim];
      } 
      // fill it with zeroes
      for(int row=0; row<rowDim; row++){
        for(int col=0; col<colDim; col++){
          values[row][col] = 0;
          anode[row]=0;
          cathode[col]=0;
        }
      }
    }
// TO BE FIXED
    void setNodes(byte *ano, byte *catho)
    {
      for(int row=0; row<rowDim; row++){
          
      }
    }

    void fillMatrix(bool* arr)
    {
      int bytes = colDim*sizeof(bool);
      for(int row=0; row<rowDim; row++){
        memcpy(values[row],arr+row*colDim,bytes);
      }
    }
    
    void slideMatrix(bool scrollLeft)
    {
      for(int row=0; row<rowDim; row++){
        for(int col=0; col<colDim; col++){
          if(scrollLeft)
            (*this).values[row][col] == (*this).values[row][col-1];
          else
            (*this).values[row][col] == (*this).values[row][col+1];
        }
      }
    }

    void multiplexMatrix() const
    {
      for (int thisRow = 0; thisRow < 8; thisRow++) {
        // take the row pin (anode) high:
        digitalWrite(anode[thisRow], HIGH);
        // iterate over the cols (cathodes):
        for (int thisCol = 0; thisCol < 8; thisCol++) {
          // get the state of the current pixel;
          int thisPixel = values[thisRow][thisCol];
          // when the row is HIGH and the col is LOW,
          // the LED where they meet turns on:
          digitalWrite(cathode[thisCol], thisPixel);
          // turn the pixel off:
          if (thisPixel == LOW) {
            digitalWrite(cathode[thisCol], HIGH);
          }
        }
        // take the row pin low to turn off the whole row:
        digitalWrite(anode[thisRow], LOW);
      }
    }

    byte yeet() const
    {
      return anode[5];
    }
    
    // destructor
    ~Matrix()
    {
      delete[] values;
      values = NULL;
      delete[] cathode;
      cathode = NULL;
      delete[] anode;
      anode = NULL;
    }
    
    
};

#endif
