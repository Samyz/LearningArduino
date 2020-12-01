#define button_N 2
#define button_E 3
#define button_W 4
#define led_gn 5
#define led_yn 6
#define led_rn 7
#define led_ge 8
#define led_ye 9
#define led_re 10
#define led_gw 11
#define led_rw 12
#define goN 0
#define waitN 1
#define goE 2
#define waitE 3
#define goW 4
#define waitW 5

struct msi
{
  unsigned long Out;  // 6-bit pattern to street output    
  unsigned long Time; // delay in ms units   
  unsigned long Next[8];
};

const struct msi ser_bobby[6]={
{B00110010,2000,{goN,waitN,waitN,waitN,goN,waitN,waitN,waitN}},
{B01010010,800,{goE,goW,goE,goE,goE,goW,goE,goE}},
{B10000110,2000,{goE,waitE,goE,waitE,waitE,waitE,waitE,waitE}},
{B10001010,800,{goW,goW,goW,goW,goN,goW,goN,goW}},
{B10010001,2000,{goW,goW,waitW,waitW,waitW,waitW,waitW,waitW}},
{B10010010,800,{goN,goN,goE,goE,goN,goN,goN,goN}}
};


void setup() 
{
  pinMode(button_N,INPUT_PULLUP);
  pinMode(button_E,INPUT_PULLUP);
  pinMode(button_W,INPUT_PULLUP);
  pinMode(led_gn,OUTPUT);
  pinMode(led_yn,OUTPUT);
  pinMode(led_rn,OUTPUT);
  pinMode(led_ge,OUTPUT);
  pinMode(led_ye,OUTPUT);
  pinMode(led_re,OUTPUT);
  pinMode(led_gw,OUTPUT);
  pinMode(led_rw,OUTPUT);
  digitalWrite(led_gn,HIGH);
  digitalWrite(led_yn,HIGH);
  digitalWrite(led_rn,HIGH);
  digitalWrite(led_ge,HIGH);
  digitalWrite(led_ye,HIGH);
  digitalWrite(led_re,HIGH);
  digitalWrite(led_gw,HIGH);
  digitalWrite(led_rw,HIGH);
}
long unsigned int times=0;
int nbut=0,ebut=0,wbut=0,Run=0,input;

void loop() 
{
  if(millis()-times<ser_bobby[Run].Time)
  {
    digitalWrite(led_rn,!(ser_bobby[Run].Out&B10000000));
    digitalWrite(led_yn,!(ser_bobby[Run].Out&B01000000));
    digitalWrite(led_gn,!(ser_bobby[Run].Out&B00100000));
  
    digitalWrite(led_re,!(ser_bobby[Run].Out&B00010000));
    digitalWrite(led_ye,!(ser_bobby[Run].Out&B00001000));
    digitalWrite(led_ge,!(ser_bobby[Run].Out&B00000100));

    if(Run==5)
      if(millis()-times>ser_bobby[Run].Time)
        digitalWrite(led_rw,!(ser_bobby[Run].Out&B00000010));
      else
        digitalWrite(led_rw,(ser_bobby[Run].Out&B00000010));
    else
      digitalWrite(led_rw,!(ser_bobby[Run].Out&B00000010));
    if(Run==5)
      if(((millis()-times)<ser_bobby[Run].Time/4)||((millis()-times>2*ser_bobby[Run].Time/4)&&(millis()-times<3*ser_bobby[Run].Time/4)))
        digitalWrite(led_gw,!(ser_bobby[Run].Out&B00000001));
      else
        digitalWrite(led_gw,(ser_bobby[Run].Out&B00000001));
    else
    digitalWrite(led_gw,!(ser_bobby[Run].Out&B00000001));
  }
  else
  {
    times=millis();
    nbut=!digitalRead(button_N);
    ebut=!digitalRead(button_N);
    wbut=!digitalRead(button_N);
    input=nbut*4+ebut*2+wbut;
    Run=ser_bobby[Run].Next[input];
  }
}
