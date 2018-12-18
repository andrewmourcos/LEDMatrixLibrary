#include "Matrix.h"

int anodes[2] = {A2,A1};
int cathodes[2] = {9,8};

Matrix m(2,2);
bool arr[2][2]={
  {1,0},
  {0,1}
};

void setup() {
// sets the pins as output
  for (int i = 1; i <= 2; i++) {
    pinMode(anodes[i], OUTPUT);
    pinMode(cathodes[i], OUTPUT);
  }
  // set up cols and rows
  for (int i = 1; i <= 2; i++) {
    digitalWrite(anodes[i], LOW);
  }

  for (int i = 1; i <= 2; i++) {
    digitalWrite(cathodes[i], LOW);
  }
  
  m.fillMatrix(*arr);
  m.setNodes(anodes, cathodes);
}

void loop() {
  // put your main code here, to run repeatedly:
  m.multiplexMatrix();
}
