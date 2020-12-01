#define sw1 3
#define sw2 4
#define sw3 5
#define sw4 6
#define sw5 7
#define sw6 8
#define sw7 9
#define speaker 11

void setup()
{
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  pinMode(sw6, INPUT_PULLUP);
  pinMode(sw7, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);
}

void loop()
{
  int a = digitalRead(sw1);
  int b = digitalRead(sw2);
  int c = digitalRead(sw3);
  int d = digitalRead(sw4);
  int e = digitalRead(sw5);
  int f = digitalRead(sw6);
  int g = digitalRead(sw7);
  while(a==0)
  {
    tone(speaker, 262);
    a=digitalRead(sw1);
  }
  while(b==0)
  {
    tone(speaker, 294);
    b=digitalRead(sw2);
  }
  while(c==0)
  {
    tone(speaker, 330);
    c=digitalRead(sw3);
  }
  while(d==0)
  {
    tone(speaker, 349);
    d=digitalRead(sw4);
  }
  while(e==0)
  {
    tone(speaker, 392);
    e=digitalRead(sw5);
  }
  while(f==0)
  {
    tone(speaker, 440);
    f=digitalRead(sw6);
  }
  while(g==0)
  {
    tone(speaker, 494);
    g=digitalRead(sw7);
  }
  noTone(speaker);
}
