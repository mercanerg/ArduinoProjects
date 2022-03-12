byte a=2,b=3,c=4,d=5,e=6,f=7,g=8;
byte buton_sol=9,buton_sag=10,birlik=12,onluk=11;
int sayac=0,sayac2=0;

byte dogruluk_tablosu[10][7]{{1,1,1,1,1,1,0}, //0
                          	 {0,1,1,0,0,0,0}, //1
                          	 {1,1,0,1,1,0,1}, //2
                          	 {1,1,1,1,0,0,1}, //3
                          	 {0,1,1,0,0,1,1}, //4
                             {1,0,1,1,0,1,1}, //5
                          	 {1,0,1,1,1,1,1}, //6
                          	 {1,1,1,0,0,0,0}, //7
                             {1,1,1,1,1,1,1}, //8
                          	 {1,1,1,1,0,1,1}, //9
                         };

void setup()
{
  for(int i=2;i<9;i++)
  {
   pinMode(i, OUTPUT);
  }
 
 
  
  pinMode(buton_sol, INPUT);
  pinMode(buton_sag, INPUT);
  
   pinMode(birlik, OUTPUT);
   pinMode(onluk, OUTPUT);
  
   

}


void loop() {
if(digitalRead(buton_sag)==1)
{
sayac++;
}

if(digitalRead(buton_sol)==1)
{
sayac--;
}
  
  
  if(sayac>9)
  {
  sayac=0;sayac2++;
  
  }
  else if(sayac<0)
  {
  sayac=9;sayac2--;
  }
  
  if(sayac2>9)
  {
  sayac2=0;
  }
  
  if(sayac2<0)
  {
  sayac2=9;
  }
  digitalWrite(birlik,0);
    digitalWrite(onluk,1);
  for(int pin=2;pin<9;pin++)
  {
    
    digitalWrite(pin,dogruluk_tablosu[sayac][pin-2]);
  }
  delay(2);
  digitalWrite(birlik,1);
    digitalWrite(onluk,0);
  for(int pin=2;pin<9;pin++)
  {
  
    digitalWrite(pin,dogruluk_tablosu[sayac2][pin-2]);
  }
  delay(100);
      
}