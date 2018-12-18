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
    bool** values;

  public:
    // default data constructor
    Matrix()
    {
      rowDim = 0;
      colDim = 0;
      values = nullptr;
    }
    // data constructor
    Matrix(int rowDim0, int colDim0)
    {
      rowDim = rowDim0;
      colDim = colDim0;
      // create "2D array"
      values = new bool*[rowDim];
      for(int i=0; i<rowDim; i++){
        values[i] = new bool[colDim];
      } 
      // fill it with zeroes
      for(int row=0; row<rowDim; row++){
        for(int col=0; col<colDim; col++){
          values[row][col] = 0;
        }
      }
    }

//    // mutator for anode/cathodes
//    void setNodes(int ano[], int catho[])
//    {
//      for(int i=0; i<rowDim; i++){
//        anode[i] == ano[i];
//      }
//      for(int j=0; j<colDim; j++){
//        cathode[j] == catho[j];
//      }
//    }

    // mutator to fill matrix
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

    void MultiplexMatrix() const
    {
      
    }
    
    // destructor
    ~Matrix()
    {
      delete[] values;
      values = NULL;
//      delete[] cathode;
//      cathode = NULL;
//      delete[] anode;
//      anode = NULL;
    }
    
    
};

#endif
