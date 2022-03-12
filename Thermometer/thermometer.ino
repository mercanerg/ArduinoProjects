#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temp;             
int temppin=A0;       

void setup()
{

  
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  
  temp = ((analogRead(temppin) * 4.9)-500)/10; 
  
  lcd.setCursor(0, 0); 
  lcd.print("Temperatute ");
  lcd.setCursor(0, 1); 
  lcd.print(temp);
  lcd.print(" C ");
  Serial.print(temp);
  Serial.println(" C ");
  delay(500); 
}