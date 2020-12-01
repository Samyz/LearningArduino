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
        motor(2);
        delay(200);
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          motor(2);
          if(b>220&&c<220&&d<220&&e>220)
          {
            delay(5);
            break;
          }
        }
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
        motor(4);
        delay(1250);//1450
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          if(b>220&&c<220&&d<220&&e>220)
            motor(4);
          else if(b>220&&c>220&&d<220&&e>220)
            motor(5);
          else if(b>220&&c<220&&d>220&&e>220)
            motor(6);
          else if(b<220&&c<220&&d<220&&e>220)
          {
            motor(1);
            delay(250);
            motor(2);
            delay(200);
            while(1)
            {
              b=analogRead(A1);
              c=analogRead(A2);
              d=analogRead(A3);
              e=analogRead(A4);
              motor(2);
              if(b>220&&c<220&&d<220&&e>220)
              {
                delay(5);
                break;
              }
            }
            break;
          }
            motor(4);
        }
      }
      /*else if(right==3)
      {
        //motor(1);
        //delay(100);
        motor(2);
        delay(200);
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          motor(2);
          if(b>220&&c<220&&d<220&&e>220)
            break;
        }
      }*/
      else if(right==3)
      {
        //motor(1);
        //delay(100);
        motor(4);
        delay(25);
        motor(3);
        delay(800);
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          motor(3);
          if(b>220&&c<220&&d<220&&e>220)
          {
            delay(5);
            break;
          }
        }
      }
      else if(right==4)
      {
        //motor(1);
        //delay(50);
        motor(4);
        delay(25);
        motor(3);
        delay(800);
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          motor(3);
          if(b>220&&c<220&&d<220&&e>220)
          {
            delay(5);
            break;
          }
        }
      }
      else if(right==5)
      {
        //motor(1);
        //delay(100);
        //motor(4);
        //delay(10);
        motor(2);
        delay(600);
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          motor(2);
          if(b>220&&c<220&&d<220&&e>220)
          {
            delay(10);
            break;
          }
        }
        motor(4);
        delay(1400);
        motor(1);
        delay(1200);
      }
      else if(right==6)
      {
        motor(2);
        delay(200);
        while(1)
        {
          b=analogRead(A1);
          c=analogRead(A2);
          d=analogRead(A3);
          e=analogRead(A4);
          motor(2);
          if(b>220&&c<220&&d<220&&e>220)
          {
            delay(5);
            break;
          }
        }
      }
      else if(right==7)
      {
        motor(1);
        delay(600);
      }
      else
      {
        motor(0);
      }
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
    }
    else if(b<220&&c<220&&d<220&&e<220)
    {
      motor(0);
    }
}

void motor(int direct)//stop 0 go 1 left 3 right 2 reverse 4 rel 5 rer 6
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
  else if(direct==4)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(direct==5)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(direct==6)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
