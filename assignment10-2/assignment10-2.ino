// motor one 
int enA = 10; 
int in1 = 9; 
int in2 = 8; 
int in3 = 7;
int in4 = 6;
int enB = 5;
long times=0;
int right=0,left=0,reverse=0;
void setup() 
{ 
  //delay(1000);
  // set all the motor control pins to outputs 
  pinMode(enA, OUTPUT); 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  //pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);
  times=millis();
  delay(200);
}
 
void loop() 
{
  // now change motor directions
  /*analogWrite(enA, 160); 
  analogWrite(enB, 200);*/
  //int a=analogRead(A0);
  int b=analogRead(A1);
  int c=analogRead(A2);
  int d=analogRead(A3);
  int e=analogRead(A4);
  //Serial.print(a);
  //Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print(c);
  Serial.print(" ");
  Serial.print(d);
  Serial.print(" ");
  Serial.println(e);
  /*if(times>=8750&&times<=9250)
  {
    if((b>200&&c<200&&d<200&&e>200))//straight
    {
      motor(1);
    }
    else if((b>200&&c<200&&d<200&&e<200)||(b>200&&c>200&&d<200&&e<200)||(b>200&&c>200&&d<200&&e>200))//left
    {
      motor(1);
    }
    else if((b<200&&c<200&&d<200&&e>200)||(b<200&&c<200&&d>200&&e>200)||(b>200&&c<200&&d>200&&e>200))//right
    {
      motor(2);
    }else if(b>200&&c>200&&d>200&&e>200)
    {
      motor(0);
      //motor(3);
    }
  }
  else*/
  //{
    if((b>220&&c<220&&d<220&&e>220))//straight
    {
      motor(1);
    }
    else if(b>220&&c<220&&d<220&&e<220)//left turn
    {
      //motor(1);
      //delay(100);//100
      //motor(3);
      //delay(600);//1100
      motor(1);
    }
    else if(b<220&&c<220&&d<220&&e>220)//right turn
    {
      if(right==0)
      {
        //motor(1);
        //delay(100);
        //motor(4);
        //delay(50);
        motor(2);
        delay(850);//825
      }
      else if(right==1)
      {
        motor(1);
        delay(200);
      }
      else if(right==2)
      {
        motor(1);
        delay(500);
        //motor(3);
        //delay(100);
        motor(4);
        delay(1450);
      }
      else if(right==3)
      {
        //motor(1);
        //delay(100);
        motor(2);
        delay(650);
      }
      else if(right==4)
      {
        //motor(1);
        //delay(100);
        motor(4);
        delay(25);
        motor(3);
        delay(900);
      }
      else if(right==5)
      {
        //motor(1);
        //delay(50);
        motor(4);
        delay(50);
        motor(3);
        delay(850);
      }
      else if(right==6)
      {
        //motor(1);
        //delay(100);
        motor(4);
        delay(50);
        motor(2);
        delay(875);
        motor(4);
        delay(1400);
        motor(1);
        delay(1200);
        while(reverse==0||reverse==1)
        {
          int b=analogRead(A1);
          int c=analogRead(A2);
          int d=analogRead(A3);
          int e=analogRead(A4);
          if((b>220&&c<220&&d<220&&e>220)||(b<220&&c<220&&d<220&&e>220))//straight
          {
            motor(1);
          }
          else if((b>220&&c>220&&d<220&&e<220)||(b>220&&c>220&&d<220&&e>220))//left
          {
            motor(3);
          }
          else if((b<220&&c<220&&d>220&&e>220)||(b>220&&c<220&&d>220&&e>220))//right
          {
            motor(2);
          }
          else if((b<220&&c<220&&d<220&&e>220)||(b<220&&c<220&&d<220&&e<220))
          {
            motor(2);
            delay(875);
            reverse=1;
          }
          if(reverse==1&&(b<220&&c<220&&d<220&&e<220))
          {
            motor(1);
            delay(200);
            while(1)
              motor(0);
          }
        }
      }
      /*else if(right==7)
      {
        motor(4);
        delay(1600);
        motor(1);
        delay(1600);
        while(1)
        {
          int b=analogRead(A1);
          int c=analogRead(A2);
          int d=analogRead(A3);
          int e=analogRead(A4);
          if((b>220&&c<220&&d<220&&e>220)||(b<220&&c<220&&d>220&&e>220)||(b>220&&c>220&&d<220&&e<220) )//straight
          {
            motor(1);
          }
          else if((b>220&&c>220&&d<220&&e<220)||(b>220&&c>220&&d<220&&e>220))//left
          {
            motor(3);
          }
          else if((b<220&&c<220&&d>220&&e>220)||(b>220&&c<220&&d>220&&e>220))//right
          {
            motor(2);
          }
          else if(b<220&&c<220&&d<220&&e<220)
          {
            motor(2);
            delay(650);
            break;
          }
        }
      }*/
      else if(right==7)
      {
        motor(1);
        delay(600);
      }
      else
      {
        /*motor(1);
        delay(1000);
        motor(2);
        delay(850);*/
        motor(0);
      }
      /*else if(right==8)
      {
        motor(1);
        delay(100);
        motor(2);
        delay(750);
      }
      else if(right==9)
      {
        //motor(1);
        //delay(100);
        motor(4);
        delay(50);
        motor(2);
        delay(800);
      }
      else if(right==10)
      {
        motor(1);
        delay(400);
      }
      else if(right==11)
      {
        //motor(1);
        //delay(100);
        motor(4);
        delay(50);
        motor(2);
        delay(850);
      }
      else if(right==12)
      {
        motor(1);
        delay(600);
      }
      else if(right==13)
      {
        motor(1);
        delay(600);
      }
      else
      {
        /*motor(1);
        delay(1000);
        motor(2);
        delay(850);*/
        //motor(0);
      //}
      right++;
    }
    else if((b>220&&c>220&&d<220&&e<220)||(b>220&&c>220&&d<220&&e>220)||(b>220&&c>220&&d>220&&e<220))//left
    {
      motor(3);
    }
    else if((b<220&&c<220&&d>220&&e>220)||(b>220&&c<220&&d>220&&e>220)||(b<220&&c>220&&d>220&&e>220))//right
    {
      motor(2);
    }
    else if(b>220&&c>220&&d>220&&e>220)
    {
      motor(0);
      //motor(3);
    }
    else if(b<220&&c<220&&d<220&&e<220)
    {
      motor(0);
    }
  //}
}

void motor(int direct)//stop 0 go 1 left 3 right 2 reverse 4
{
  analogWrite(enA, 80); //72
  analogWrite(enB, 100); //83
  if(direct==0)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else if(direct==1)
  {
    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW);      
    digitalWrite(in3, LOW); 
    digitalWrite(in4, HIGH);
  }
  else if(direct==2)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if(direct==3)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}
