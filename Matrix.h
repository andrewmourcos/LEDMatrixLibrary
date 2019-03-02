/*
 * Matrix.h - Declaration for library driving bare LED matrices w/ Arduino 
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
    Matrix();
    // parametric data constructor
    // pass in the size of the screen
    Matrix(int rowDim0, int colDim0);
    // mutator for setting anode and cathode pins
    // pass in as list of bytes
    void setNodes(byte ano[], byte catho[]);
    // fills matrix object with 2d array data
    void fillMatrix(bool* arr);
    // slides image accross the screen
    // returns whether it is done scrolling
    bool slide();
    void scrollText(int duration);
    // helper function for "multiplexing"
    // reduces number of pins needed for matrix driving
    void multiplexMatrix(int duration) const;
    // destructor
    ~Matrix();
};

#endif
