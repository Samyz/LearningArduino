#include<SoftwareSerial.h>
SoftwareSerial mySerial(3,10);
int aha=0;
long times;
char aho='R',ahi='P',ahu='S';
void setup() 
{
  Serial.begin(4800);
  mySerial.begin(4800);
  pinMode(6,INPUT_PULLUP);//rock
  pinMode(7,INPUT_PULLUP);//paper
  pinMode(8,INPUT_PULLUP);//scissor
}

void loop() 
{
  int a=digitalRead(6);
  int b=digitalRead(7);
  int c=digitalRead(8);
  if(a==0&&millis()-times>200)
  {
    mySerial.println("R");
    times=millis();
  }
  if(b==0&&millis()-times>200)
  {
    mySerial.println("P");
    times=millis();
  }
  if(c==0&&millis()-times>200)
  {
    mySerial.println("S");
    times=millis();
  }
}
