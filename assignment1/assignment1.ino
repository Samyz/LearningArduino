#define switch_green 10
#define green 2
#define switch_yellow 11
#define yellow 3
#define switch_red 12
#define red 4
int g = 1, y = 1, r = 0, LastStateR = 0, LastStateY = 1, LastStateG = 1, Gstate = 0, Ystate = 0, Rstate = 0;
long LastDebounceG = 0, LastDebounceY = 0, LastDebounceR = 0, debounce = 100, StartR = 0, StartG = 0,StartY=0;

void setup()
{
  Serial.begin(9600);
  pinMode(switch_green, INPUT_PULLUP);
  pinMode(green, OUTPUT);
  pinMode(switch_yellow, INPUT);
  pinMode(yellow, OUTPUT);
  pinMode(switch_red, INPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  int switchG = digitalRead(switch_green);
  int switchY = digitalRead(switch_yellow);
  int switchR = digitalRead(switch_red);

 
  if (switchG != LastStateG) {
    LastDebounceG = millis();
  }
  if (millis() - LastDebounceG > debounce)
    if (switchG != g)
    {
        g=switchG;
        if (g == 0)
        {
          if (Gstate == 0&&Rstate!=1)
          {
             Gstate = 1; StartG = millis();
          }
           else
             {Gstate = 0;}
        }
    }
  LastStateG = switchG;

  if (switchY != LastStateY) {
    LastDebounceY = millis();
  }
  if (millis() - LastDebounceY > debounce)
    if (switchY != y)
      {
        y = switchY;
        if (y == 0)
          if (Ystate == 0&&Gstate!=1&&Rstate!=1)
          {
            Ystate = 1;StartY=millis();
          }
          else
            Ystate = 0;
      }
  LastStateY = switchY;

  if (switchR != LastStateR) {
    LastDebounceR = millis();
  }
  if (millis() - LastDebounceR > debounce)
    if (switchR != r)
    {
      r = switchR;
      if (r == 1)
        if (Rstate == 0)
        {
          Rstate = 1; StartR = millis();
        }
        else
          Rstate = 0;
   }
  LastStateR = switchR;

  
  
  


  if (Gstate == 1 && millis() - StartG <= 3000)
  {
    digitalWrite(green, HIGH);
  }
  else
  {
    digitalWrite(green, LOW);Gstate=0;
  }
  if (Ystate == 1&&(millis()-StartY<=500||(1000<millis()-StartY&&millis()-StartY<=1500)))
  {
    digitalWrite(yellow, HIGH);
  }
  else
  {
    digitalWrite(yellow, LOW);
    if(millis()-StartY>2000)
      Ystate=0;
  }
  if (Rstate == 1 && millis() - StartR <= 3000)
  {
    digitalWrite(red, HIGH);
  }
  else
  {
    digitalWrite(red, LOW);Rstate=0;
  }
}
