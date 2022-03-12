#include <EEPROM.h>

#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>


int basamak=0;
String girilen_sifre="";
char tus;
String sifre="1234";
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Servo myservo;
bool eepromsifre=false;
byte eepromchar;

const byte satir = 4; 
const byte sutun= 4;
const byte ledyesil=12;
const byte ledkirmizi=11;
const byte buzzer=13;


char tus_takimi[satir][sutun] =
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
 
byte satirPin[satir]={2,3,4,5};
byte sutunPin[sutun]={6,7,8,9};
 
Keypad tus_takimim=Keypad(makeKeymap(tus_takimi),satirPin,sutunPin,satir,sutun );
 
void setup()
{
lcd.begin(16,2);
lcd.setCursor(0,0);
  myservo.attach(10);myservo.write(0);
  Serial.begin(9600);
 
}


void sifreKontrol()
{
    if(girilen_sifre==sifre+"#")
    {
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SIFRE DOGRU");
    digitalWrite(ledyesil,HIGH);
    digitalWrite(ledkirmizi,LOW);
  myservo.write(180);
    

    tone(buzzer,262);delay(100);noTone(buzzer);delay(100);
    tone(buzzer,262);delay(100);noTone(buzzer);delay(2000);
    digitalWrite(ledyesil,LOW);
      lcd.clear();lcd.setCursor(0,0);
      girilen_sifre="";basamak=0;
   myservo.write(0);  
    
  }
     else 
     {
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SIFRE YANLIS");
    digitalWrite(ledyesil,LOW);
    digitalWrite(ledkirmizi,HIGH);
    tone(buzzer,262);delay(100);noTone(buzzer);delay(100);
    tone(buzzer,440);delay(100);noTone(buzzer);delay(2000);
    digitalWrite(ledkirmizi,LOW);
       lcd.clear();lcd.setCursor(0,0);
        girilen_sifre="";basamak=0;
     }
   }


void loop()
{
   
tus=tus_takimim.getKey();
lcd.setCursor(4,0);
  lcd.print("Sifre Gir");
if(tus!=NO_KEY)
{
 girilen_sifre=girilen_sifre+tus;
 basamak=basamak++;
  lcd.setCursor(basamak+4,1);
  lcd.print(tus);
  basamak++;
}
    
 if(tus=='#')
 {
 sifreKontrol();
 }
}