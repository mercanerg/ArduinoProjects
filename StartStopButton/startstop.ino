const int Led_Kirmizi=4;
const int Led_Yesil=5;
const int buton_basla=2;
const int buton_dur=3;
const int motor=6;

bool durum=false;
void setup()
{
  
  pinMode(Led_Kirmizi, OUTPUT);
  pinMode(Led_Yesil, OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(buton_basla, INPUT);
  pinMode(buton_dur, INPUT);
  digitalWrite(Led_Kirmizi,HIGH);
}

void loop(){
  
  
  if(digitalRead(buton_basla)==LOW)
  {
  
  digitalWrite(Led_Kirmizi,HIGH);
  digitalWrite(Led_Yesil,LOW);
  digitalWrite(motor,0);
   
  }
 
  if(digitalRead(buton_dur)==LOW)
  
  {
  digitalWrite(Led_Kirmizi,LOW);
  digitalWrite(Led_Yesil,HIGH);
  digitalWrite(motor,1);
   
  }
  
}
