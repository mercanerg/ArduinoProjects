#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorvalue;
int sensorpercentage;
int led=10;
int dcmotor=7;
int sensor = A0;
int buzzer = 13;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
 sensorvalue = analogRead(sensor);
 sensorpercentage=map(sensorvalue ,487,877,0,100);
  
  if(sensoryuzdesi > 20){
    
     digitalWrite(dcmotor, HIGH);
     digitalWrite(led, HIGH);
    
      tone(buzzer,400);
    
  }
  
  else{
    
        digitalWrite(dcmotor, LOW);
        digitalWrite(led, LOW);
    
       noTone(buzzer);
    
  }
  lcd.setCursor(0, 0); 
  lcd.print("Gas % ");
  lcd.print(sensorpercantage);
  
  Serial.print("Gas % ");
  Serial.println(sensorpercentage);

  
 delay(100);   
}
