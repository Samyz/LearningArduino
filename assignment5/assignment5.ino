int x=0,y=0,z=0;
long times;
void setup() 
{
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
}

void loop() 
{
  int starto=digitalRead(3);
  int xs=analogRead(A0);
  int ys=analogRead(A1);
  int zs=analogRead(A2);
  if(starto==0)
  {
    delay(50);
    x=xs;
    y=ys;
    z=zs;
  }
  if(x!=0&&y!=0&&z!=0)
  if((xs<x-12||xs>x+12)||(ys<y-12||ys>y+12)||(zs<z-12||zs>z+12))
  {
    times=millis();
    while(1)
    {
      if(millis()-times<200)
      {
        tone(5,1200);
      }
      else if(millis()-times==200)
        noTone(5);
      else if(millis()-times<400)
      {
        tone(5,300);
      }
      else
      {
        noTone(5);
        times=millis();
      }
      int finisho=digitalRead(4);
      delay(50);
      if(finisho==0)
        break;
    }
    noTone(5);
    x=0;y=0;z=0;
  }

}
