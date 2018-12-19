#include "Matrix.h"

//note: cannot use serial if using pin 0 and 1
byte cathodes[10]={9,8,7,6,5,4,3,2,0,1}; //cathodes
byte anodes[7]={A2,A1,A0,13,12,11,10}; //anodes

Matrix m(7,10);
bool arr[7][10]={
  {0,0,0,1,0,0,0,0,0,0},
  {0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,0,1,0,0,0,0},
  {1,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,1,0,0,},
  {0,0,0,0,0,0,0,1,1,0},
  {0,0,0,0,0,0,0,0,0,1},
};

int r=0;
void setup() {
  for (int i = 0; i <= 10; i++) {
    pinMode(anodes[i], OUTPUT);
    pinMode(cathodes[i], OUTPUT);
  }
  // set up cols and rows
  for (int i = 0; i <= 7; i++) {
    digitalWrite(anodes[i], LOW);
  }

  for (int i = 0; i <= 10; i++) {
    digitalWrite(cathodes[i], LOW);
  }
  
  m.fillMatrix(*arr);
  m.setNodes(anodes, cathodes);
}

void loop() {
  m.multiplexMatrix(500);
  m.scroll(1);
}
