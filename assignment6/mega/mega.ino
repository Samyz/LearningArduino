#include<SoftwareSerial.h>
SoftwareSerial mySerial(3,10);
long megao=0,nanoo=0;
char nano='0',mega='0';
void setup() 
{
  Serial.begin(4800);
  mySerial.begin(4800);
  pinMode(6,INPUT_PULLUP);//rock
  pinMode(7,INPUT_PULLUP);//paper
  pinMode(8,INPUT_PULLUP);//scissor
  pinMode(4,OUTPUT);//megawin
  pinMode(5,OUTPUT);//error
  pinMode(12,OUTPUT);//draw
  pinMode(13,OUTPUT);//nanowin
}

long asap(long wow)
{
  if(wow<0)
    return -wow;
  else
    return wow;
}

void loop() 
{ 
  if(mySerial.available())
  {
  char inchar=(char)mySerial.read();
  if(inchar=='R'||inchar=='P'||inchar=='S');
  {
    nano=inchar;
  
    nanoo=millis();
  }
  }
  if(millis()-nanoo>200)
  {
    nanoo=millis();
    nano='0';
  }
  Serial.print(nano);
  Serial.print(" ");
  Serial.println(mega);
  int a=digitalRead(6);
  int b=digitalRead(7);
  int c=digitalRead(8);
  if(a==0&&megao-millis()>200)
  {
    mega='R';
    megao=millis();
  }
  if(b==0&&megao-millis()>200)
  {
    mega='P';
    megao=millis();
  }
  if(c==0&&megao-millis()>200)
  {
    mega='S';
    megao=millis();
  }
  if(mega!='0'&&nano!='0')
  {
    if(asap(megao-nanoo)<200)
    {
      if((mega=='R'&&nano=='R')||(mega=='P'&&nano=='P')||(mega=='S'&&nano=='S'))
      {
        mega='0';
        nano='0';
        megao=millis();
        nanoo=millis();
        digitalWrite(12,HIGH);
        delay(250);
        digitalWrite(12,LOW);
      }
      else if((mega=='R'&&nano=='S')||(mega=='S'&&nano=='P')||(mega=='P'&&nano=='R'))
      {
        mega='0';
        nano='0';
        megao=millis();
        nanoo=millis();
        digitalWrite(4,HIGH);
        delay(250);
        digitalWrite(4,LOW);
      }
      else if((mega=='R'&&nano=='P')||(mega=='P'&&nano=='S')||(mega=='S'&&nano=='R'))
      {
        mega='0';
        nano='0';
        megao=millis();
        nanoo=millis();
        digitalWrite(13,HIGH);
        delay(250);
        digitalWrite(13,LOW);
      }
    }
    else
    {
      mega='0';
      nano='0';
      megao=millis();
      nanoo=millis();
      digitalWrite(5,HIGH);
      delay(250);
      digitalWrite(5,LOW);
    }
  }
}
