#include <Servo.h>;
byte turning = 0;
int degree = 0;
Servo servo1;
int changeInDegree = 0;
int previous = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(8);
}
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){
  turning = Serial.read();
  degree = map(turning, 0 ,128, 140, 40);
  degree = constrain(degree, 40, 140);
  changeInDegree = degree - previous;
  if(changeInDegree>0){
    servo1.write(degree+2);
  }
  else{
  servo1.write(degree-2);
  }
  previous = degree;
 }
}
