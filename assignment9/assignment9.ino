#include<Servo.h>

Servo servoBobby,servoRutherford,servolnwBon,servoSamy;

void setup() 
{
  servoBobby.attach(11,500,1700);
  servoRutherford.attach(10,500,1700);
  servolnwBon.attach(9,500,1700);
  servoSamy.attach(8,500,1700);
  servoBobby.write(0);
  //delay(500);
  //servoBobby.write(180);
  servoRutherford.write(90);
  servolnwBon.write(60);
  servoSamy.write(45);
}

int a,b,c,d;

void loop() 
{
  for(a=45;a<=90;++a)
  {
    servoSamy.write(a);
    delay(15);
  }
  for(c=100;c>=90;--c)
  {
    servoRutherford.write(c);
    delay(15);
  }
  for(b=60;b<=90;++b)
  {
    servolnwBon.write(b);
    delay(15);
  }
  for(d=0;d<=100;++d)
  {
    servoBobby.write(d);
    delay(15);
  }
  for(c=90;c<=110;++c)
  {
    servoRutherford.write(c);
    delay(15);
  }
  delay(1000);
  for(b=90;b>=60;--b)
  {
    servolnwBon.write(b);
    delay(15);
  }
  for(a=90;a>=45;--a)
  {
    servoSamy.write(a);
    delay(15);
  }
  for(d=110;d>=0;--d)
  {
    servoBobby.write(d);
    delay(15);
  }
  delay(3000);
  
  delay(5000);
}
