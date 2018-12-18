#include "Matrix.h"

Matrix m(2,2);
bool arr[2][2]={
  {1,0},
  {0,1}
};

void setup() {
  Serial.begin(9600);
  m.fillMatrix(*arr);
}

void loop() {
  // put your main code here, to run repeatedly:

}
