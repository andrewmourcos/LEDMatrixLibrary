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
    bool *values;
    int *anodes;
    int *cathodes;
    
  public:
    // default data constructor
    Matrix()
    {
      rowDim = 0;
      colDim = 0;
      values=NULL;
      anodes = NULL;
      cathodes = NULL;
    }
    // data constructor
    Matrix(int rowDim0, int colDim0)
    {
      rowDim = rowDim0;
      colDim = colDim0;
      values = new bool[rowDim][colDim];
      anodes = new int[rowDim];
      cathodes = new int[colDim];
      for(int row=0; row<rowDim; row++){
        for(int col=0; col<colDim; col++){
          values[row][col] = 0;
        }
      }
    }
    // mutator for anode/cathodes
    void setNodes(int ano[], int catho[])
    {
      for(int i=0; i<rowDim; i++){
        anode[i] == ano[i];
      }
      for(int j=0; j<colDim; j++){
        cathode[j] == catho[j];
      }
    }
    // mutator to fill matrix
    void fillMatrix(bool arr[][])
    {
      for(int row=0; row<rowDim; row++){
        for(int col=0; col<colDim; col++){
          (*this).values[row][col] == arr[row][col];
        }
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

    void showMatrix() const
    {
      
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
