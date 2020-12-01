#include "ST7735_TEE.h"
int input,bar=61,ballx=60,bally=25,directions=1,direct=0,died=0,go=0,score=0,life=3,asap=1;
long timebar=0;
TEE_ST7735 lcd(9, 10, 11, 12, 13); //Arduino  csk,sda,A0,rst,cs
void setup() 
{
  lcd.init(lcd.VERTICAL);
  //victory();
  pinMode(8,INPUT);
  Serial.begin(9600);
  starto();
}

void printbar(int wow)
{
  if(wow==1)
  {
    lcd.drawLine(bar+4,150,bar+19,150,BLACK);
    lcd.drawLine(bar,150,bar+15,150,YELLOW);
  }
  else
  {
    lcd.drawLine(bar-4,150,bar+11,150,BLACK);
    lcd.drawLine(bar,150,bar+15,150,YELLOW);
  }
}

void loop() 
{
  bars();
  ball();
  asap+=1;
  if(asap==4)
    asap=1;
}

void starto()
{
  lcd.fillScreen(BLUE);
  lcd.drawString(7,65,"Press!!",RED,3);
  while(1)
  {
    int a=digitalRead(8);
    if(a==0)
    {
      delay(200);
      break;
    }
  }
  lcd.fillScreen(BLACK);
  lcd.drawRect(4,20,120,140,WHITE);
  lcd.fillRect(1,20,4,140,WHITE);
  lcd.fillRect(124,20,4,140,WHITE);
  lcd.drawLine(bar,150,bar+15,150,YELLOW);
  
  //lcd.fillRect(5,21,6,6,GREEN);
  //lcd.fillCircle(ballx,bally,4,RED);
  //lcd.drawLine(ballx,130,ballx,139,GREEN);
  randomSeed(millis());
  directions=random(1,2);
  if(directions==1)
    direct=0;
  else
    direct=1;
  ballx=random(9,119);
  printlife();
  printscore();
}

void gameover()
{
  lcd.fillScreen(WHITE);
  lcd.drawString(40,60,"GAME",RED,2);
  lcd.drawString(40,80,"OVER",RED,2);
  delay(2000);
  life=3;
  died=0;
  go=0;
  score=0;
  starto();
}

void victory()
{
  lcd.fillScreen(YELLOW);
  lcd.drawString(3,70,"VICTORY",BLUE,3);
  delay(2000);
  eraseball();
  bally=25;
  ballx=random(9,119);
  died=0;
  go=0;
  life=3;
  score=0;
  starto();
}

void printlife()
{
  if(life==3)
  {
    lcd.drawChar(115,5,3,GREEN,2);
    lcd.drawChar(100,5,3,GREEN,2);
    lcd.drawChar(85,5,3,GREEN,2);
  }
  else if(life==2)
  {
    lcd.drawChar(115,5,3,GREEN,2);
    lcd.drawChar(100,5,3,GREEN,2);
    lcd.fillRect(85,5,15,15,BLACK);
  }
  else if(life==1)
  {
    lcd.drawChar(115,5,3,GREEN,2);
    lcd.fillRect(100,5,15,15,BLACK);
    lcd.fillRect(85,5,15,15,BLACK);
  }
  else if(life==0)
  {
    lcd.fillRect(115,5,15,15,BLACK);
    lcd.fillRect(100,5,15,15,BLACK);
    lcd.fillRect(85,5,15,15,BLACK);
  }
}

void printscore()
{
  lcd.drawString(4,7,"Score:",BLUE,1);
  if(score<10)
  {
    lcd.fillRect(40,7,6,7,BLACK);
    lcd.drawChar(40,7,score+48,BLUE,1);
  }
  else if(score<100)
  {
    int aaa=score/10,bbb=score%10;
    lcd.fillRect(40,7,12,7,BLACK);
    lcd.drawChar(40,7,aaa+48,BLUE,1);
    lcd.drawChar(46,7,bbb+48,BLUE,1);
  }
  else if(score<1000)
  {
    int aaa=score/100,bbb=score/10-10,ccc=score%10;
    lcd.fillRect(40,7,18,7,BLACK);
    lcd.drawChar(40,7,aaa+48,BLUE,1);
    lcd.drawChar(46,7,bbb+48,BLUE,1);
    lcd.drawChar(54,7,ccc+48,BLUE,1);
  }
  else
    victory();
}

void bars()
{
  if(asap==3)
  {
    input=analogRead(0);
    if(input<522)
    {
      if(bar>6)
      {
        if(bar==7)
          bar-=2;
        else
          bar-=4;
        printbar(1);
      }
    }
    else if(input>526)
    {
      if(bar<106)
      {
        if(bar==105)
          bar+=2;
        else
          bar+=4;
        printbar(0);
      }
    }
  }
}

void printball()
{
  lcd.fillCircle(ballx,bally,4,RED);
}

void eraseball()
{
  lcd.fillCircle(ballx,bally,4,BLACK);
}

void ball()
{
  if(died==0)
  {
    if(bally<145)
      go=0;
    if(directions==1)
    {
      if((ballx<117&&bally<145)||go==1)
      {
        eraseball();
        ballx+=1;
        bally+=1;
        printball();
      }
      else
      {
        if(direct==0)
        {
          directions=2;
          if(bally==145&&go==0)
            died=1;
          if(ballx-1<=9||bally+1>=145)
          {
            direct=1;
            directions=4;
          }
        }
        else if(direct==1)
        {
          directions=4;
          if(bally==145&&go==0)
            died=1;
          if(ballx+1>=117||bally-1<=25)
          {
            direct=0;
            directions=2;
          }
        }
      }
    }
    else if(directions==2)
    {
      if((ballx>9&&bally<145)||go==1)
      {
        eraseball();
        ballx-=1;
        bally+=1;
        printball();
      }
      else
      {
        if(direct==0)
        {
          directions=3;
          if(bally==145&&go==0)
            died=1;
          if(ballx-1<=9||bally-1<=25)
          {
            direct=1;
            directions=1;
          }
        }
        else if(direct==1)
        {
          directions=1;
          if(bally==145&&go==0)
            died=1;
          if(ballx+1>=117||bally+1>=145)
          {
            direct=0;
            directions=3;
          }
        }
      }
    }
    else if(directions==3)
    {
      if((ballx>9&&bally>25)||go==1)
      {
        eraseball();
        ballx-=1;
        bally-=1;
        printball();
      }
      else
      {
        if(direct==0)
        {
          directions=4;
          if(ballx+1>=117||bally-1<=25)
          {
            direct=1;
            directions=2;
          }
        }
        else if(direct==1)
        {
          directions=2;
          if(ballx-1<=9||bally-1>=145)
          {
            direct=0;
            directions=4;
          }
        }
      }
    }
    else if(directions==4)
    {
      if((ballx<117&&bally>25)||go==1)
      {
        eraseball();
        ballx+=1;
        bally-=1;
        printball();
      }
      else
      {
        if(direct==0)
        {
          directions=1;
          if(ballx+1>=117||bally+1>=145)
          {
            direct=1;
            directions=3;
          }
        }
        else if(direct==1)
        {
          directions=3;
          if(ballx-1<=9||bally-1<25)
          {
            direct=0;
            directions=1;
          }
        }
      }
    }
  }
  else
  {
    if(bally==145)
    {
      if((ballx-1<=bar+15&&ballx-1>=bar)||(ballx+1<=bar+15&&ballx+1>=bar))
      {
        go=1;
        died=0;
        score+=5;
        printscore();
      }
    }
    else if(bally==146)
    {
      if((ballx-2<=bar+15&&ballx-2>=bar)||(ballx+2<=bar+15&&ballx+2>=bar)||(ballx-3<=bar+15&&ballx-3>=bar)||(ballx+3<=bar+15&&ballx+3>=bar))
      {
        go=1;
        died=0;
        score+=5;
        printscore();
        if(/*(ballx<bar&&ballx+2<=bar)||(ballx<bar&&ballx+3<=bar)||*/(ballx>bar+15&&ballx-2>=bar+15)||(ballx>bar+15&&ballx-3>=bar+15))
        {
          if(directions==1)
          {
            directions=4;
            direct=1;
          }
          else
          {
            directions=4;
            direct=1;
          }
        }
        else
        {
          if(directions==1)
          {
            directions=3;
            direct=0;
          }
          else
          {
            directions=3;
            direct=0;
          }
        }
      }
    }
    else if(bally==148)
    {
      if((ballx-4<=bar+15&&ballx-4>=bar)||(ballx+4<=bar+15&&ballx+4>=bar))
      {
        go=1;
        died=0;
        score+=5;
        printscore();
        if(/*(ballx<bar&&ballx+4<=bar)||*/(ballx>bar+15&&ballx-4>=bar+15))
        {
          if(directions==1)
          {
            directions=4;
            direct=1;
          }
          else
          {
            directions=4;
            direct=1;
          }
        }
        else
        {
          if(directions==1)
          {
            directions=3;
            direct=0;
          }
          else
          {
            directions=3;
            direct=0;
          }
        }
      }
    }
    else if(bally>=154)
    {
      directions=random(1,2);
      if(directions==1)
        direct=0;
      else
        direct=1;
      bally=25;
      ballx=random(9,119);
      died=0;
      go=0;
      life-=1;
      if(life==0)
      {
        gameover();
      }
      else
      {
        lcd.fillScreen(BLACK);
        lcd.drawRect(4,20,120,140,WHITE);
        lcd.fillRect(1,20,4,140,WHITE);
        lcd.fillRect(124,20,4,140,WHITE);
        lcd.drawLine(bar,150,bar+15,150,YELLOW);
        printscore();
        printlife();
      }
    }
    if(directions==4&&died==1)
      directions=1;
    if(directions==3&&died==1)
      directions=2;
    if(direct==0&&died==1)
      direct=1;
    else
      direct=0;
    if(directions==1&&died==1)
    {
      if(ballx<117&&bally<155)
      {
        eraseball();
        ballx+=1;
        bally+=1;
        printball();
      }
      else
      {
        if(direct==0)
        {
          directions=2;
        }
      }
    }
    else if(directions==2&&died==1)
    {
      if(ballx>9&&bally<155)
      {
        eraseball();
        ballx-=1;
        bally+=1;
        printball();
      }
      else
      {
        if(direct==1)
        {
          directions=1;
        }
      }
    }
  }
}
