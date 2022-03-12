#include <Adafruit_NeoPixel.h>

#define pin 2     

#define pikselsayisi 12 

// rastgele renk secerken renklerin sabit olması için değişkenler

int kirmizi = 0;
int yesil = 0;
int mavi = 0;

Adafruit_NeoPixel piksel = Adafruit_NeoPixel(pikselsayisi, pin, NEO_GRB + NEO_KHZ800);

void setup() {
  piksel.begin(); 
  Serial.begin(9600);
}

void loop() {
      renkler();
  // Birer birer rastgele yansın
  for(int i=0;i<12;i++){ 
    piksel.setPixelColor(i, random(255), random(255), random(255));    
    piksel.show();
    delay(150);    
  } 
  piksel.clear(); 
  
  // ikişer ikişer rastgele yansın
    for(int i=0;i<12;i+=2){ 
    piksel.setPixelColor(i, random(255), random(255), random(255));    
    piksel.show();
    delay(150);    
  } 
  piksel.clear(); 
  
  // ücer ücer sadece mavi yansın
    for(int i=0;i<12;i+=3){ 
    piksel.setPixelColor(i, 0, 0, 255);    
    piksel.show();
    delay(150);    
  } 
  
  piksel.clear(); 
  
  // hepsi birden yesil yansın
  for(byte i=0;i<13;i++)
  {
    piksel.setPixelColor(i, 0, 255, 0);
  }
  
  piksel.show();
  delay(1000); 
  
  // hepsi birden sonsun
  piksel.clear(); 
  piksel.show();
  delay(500); 
  
  
  // hepsi birden kırmızı yansın
  for(byte i=0;i<13;i++)
  {
    piksel.setPixelColor(i, 255, 0, 0);
  }
  piksel.show();
  delay(1000); 
  
  // hepsi birden mavi yansın
  for(byte i=0;i<13;i++)
  {
    piksel.setPixelColor(i, 0, 0, 255);
  }
  piksel.show();
  delay(1000);
  
  
  // hepsi birden sonsun
  piksel.clear(); 
  piksel.show();
  delay(500); 
  

  // tek tek yanarken rastgele tek renk çıkması
  for(int i=0;i<pikselsayisi;i++){

   
    piksel.setPixelColor(i, piksel.Color(kirmizi, yesil,mavi)); // Moderately bright green color.

    piksel.show();

    delay(500); 
  }
}
void renkler(){
  
  kirmizi = random(0, 255);
  yesil = random(0,255);
  mavi = random(0, 255);
  Serial.print("Kirmizi: ");
  Serial.println(kirmizi);
  Serial.print("Yesil: ");
  Serial.println(yesil);
  Serial.print("Mavi: ");
  Serial.println(mavi);
  
}