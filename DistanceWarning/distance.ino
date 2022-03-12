/*   ******* RCN Hard&Soft ********
	If the distance is less than 50 cm,
 the device warns people with light and sound. */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); // LCD ekranın Arduino bağlantı pinleri 

#define echoPin 7
#define trigPin 6
#define buzzerPin 9
#define led 8

int maximumRange = 50;
int minimumRange = 0;
int sayi=125;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16,2);  //init LCD

}

void loop() {

  int olcum = mesafe(maximumRange, minimumRange);

}

int mesafe(int maxrange, int minrange)
{
  float duration, distance;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  lcd.setCursor(0,0);  
  lcd.print("Distance =");
  
  lcd.print(distance);
  lcd.print("cm");
  if(distance<50)
  {
 // digitalWrite(buzzerPin,HIGH);
    digitalWrite(led,HIGH);
    tone(buzzerPin, 261);
    delay(500);
     noTone(buzzerPin);
    delay(500);
   
  }

 else 
  {
 // digitalWrite(buzzerPin,LOW);
     noTone(buzzerPin);
 //   tone(buzzerPin, 1200);
  digitalWrite(led,LOW);
  
  }
  
  delay(50);

}