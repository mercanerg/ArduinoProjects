/* control stepper
 * as pressing right button, it steps how steps you set
 * one turn  is  200 steps  
 * when pressed button it steps 90 degree
 */
#include <Stepper.h> //stepper library
int solbuton =2;  //assign button pins
int sagbuton =3;
int stepadimi = 0;  // stepping vaule

// in the library, defined for stepper pins are  8 and 11,
//  PWM pins 9,10,11. to send pulses:
Stepper stepmotor(stepadimi, 8, 9, 10, 11);

void setup() {
  pinMode(solbuton, INPUT_PULLUP);
  pinMode(sagbuton, INPUT_PULLUP);
 
 stepmotor.setSpeed(60); // stepper speed
  }

void loop() {

if(digitalRead(solbuton)==HIGH) // left button
{
 stepadimi=stepadimi+10;
  delay(1000);} // while pressing button, it turns 90 degree delay 1 second then goes on.

// right button
  if(digitalRead(sagbuton)==HIGH)
  {
stepadimi=-1*stepadimi; // Forward - Revers
  delay(1000);}
  stepmotor.step(stepadimi);
} 