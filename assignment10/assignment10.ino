// motor one 
int enA = 10; 
int in1 = 9; 
int in2 = 8; 
int in3 = 7;
int in4 = 6;
int enB = 5;
void setup() 
{ 
   delay(1000);
  // set all the motor control pins to outputs 
  pinMode(enA, OUTPUT); 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);

}
 
void loop() 
{
  // now change motor directions
  /*analogWrite(enA, 160); 
  analogWrite(enB, 200);*/
  motor(1);    
  delay(1300); 
  // now turn off motors 
  motor(0);
  delay(500);
  motor(3);
  delay(747);
  motor(0);
  delay(500);
}

void motor(int direct)//stop 0 go 1 left 2 right 3 reverse 4
{
  analogWrite(enA, 72); 
  analogWrite(enB, 99);
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
