/*
 * Matrix.cpp - Definition for library driving bare LED matrices
 * Created by Andrew Mourcos, Dec 18 2018
 * Must give proper credit for use.
*/
#include "Matrix.h"
#include "Arduino.h"

Matrix::Matrix()
{
  rowDim = 0;
  colDim = 0;
  anode = nullptr;
  cathode = nullptr;
  values = nullptr;
}
// data constructor
Matrix::Matrix(int rowDim0, int colDim0)
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

void Matrix::setNodes(byte ano[], byte catho[])
{
  memcpy(anode, ano, rowDim);
  memcpy(cathode, catho, colDim);
}

void Matrix::fillMatrix(bool* arr)
{
  int bytes = colDim*sizeof(bool);
  for(int row=0; row<rowDim; row++){
    memcpy(values[row],arr+row*colDim,bytes);
  }
}

// returns whether it is done scrolling
bool Matrix::slide()
{
  int tally=0;
  for(int col=0; col<colDim; col++){
    for(int row=0; row<rowDim; row++){
      
      if(col==colDim-1)
        values[row][col]=0;
      else
        values[row][col] = values[row][col+1];
      tally += values[row][col];
    }
  }
  return tally;
}

void Matrix::scrollText(int duration){
  
}

void Matrix::multiplexMatrix(int duration) const
{
  int temps=millis();
  int row=0;
  while(duration > millis()-temps){
    digitalWrite(anode[row], HIGH);  
    row++;
    if (row == rowDim) {
      row = 0;
    }
    for(int col=0; col<colDim; col++){
      if(values[row][col] == 1)
        digitalWrite(cathode[col], HIGH);
      else
        digitalWrite(cathode[col], LOW);
    }
    digitalWrite(anode[row], LOW);
    delayMicroseconds(100);
  }
}

// destructor
Matrix::~Matrix()
{
  if(values != NULL){
    for(int row=0; row<rowDim; row++){
      delete[] values[row];
      values[row] = NULL;
    }
    delete[] values;
    values = NULL;
  }
  delete[] cathode;
  cathode = NULL;
  delete[] anode;
  anode = NULL;
}
