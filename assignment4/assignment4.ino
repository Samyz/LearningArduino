#include "LedControl.h"
LedControl lc = LedControl(11, 9, 10, 1);
const byte PIN_A = 2;
const byte PIN_B = 3;
const byte PIN_D = 5;
int bar = 3, laststateb = 1, laststated = 1, pressb = 0, pressd = 0, x = 0, y = 0, directions = 1, direct = 0, count = 3, g = 0;
long lastpress = 0, lasttimeb = 0, lasttimed = 0, lastball = 0, times = 0;
int number3[8][8] = {{0, 0, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0}};
int number2[8][8] = {{0, 0, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 0, 0}};
int number1[8][8] = {{0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}};
int skeleton[8][8] = {{0, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 0, 1, 1}, {1, 0, 0, 1, 1, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 0, 1, 0}};

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_A, INPUT);
  digitalWrite(PIN_A, HIGH);
  pinMode(PIN_B, INPUT);
  digitalWrite(PIN_B, HIGH);
  pinMode(PIN_D, INPUT);
  digitalWrite(PIN_D, HIGH);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  print3();
  printbar();
  x = millis() % 8;
  directions = millis() % 2 + 1;
  if (directions == 1)
    direct = 0;
  else
    direct = 1;
  delay(200);
  printball(x, y);
  delay(175);
}

void loop()
{
  barcontrol();
  ball();
}

void print3()
{
  int a = 1;
  times = millis();
  for (; a == 1; times = millis())
  {
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        lc.setLed(0, 7 - j, i, number3[i][j]);
    while (millis() - times < 500)
    {
      if (a == 1)
        a = digitalRead(PIN_A);
      delay(50);
    }
    lc.clearDisplay(0);
    while (millis() - times < 1000&&millis()-times>500)
    {
      if (a == 1)
        a = digitalRead(PIN_A);
      delay(50);
    }
  }
}

void gameover()
{
  delay(50);
  lc.clearDisplay(0);
  x = millis() % 8;
  y = 0;
  count = 3;
  bar = 3;
  for (int k = 0; k < 2; ++k)
  {
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        lc.setLed(0, 7 - j, i, skeleton[i][j]);
    delay(2000);
    lc.clearDisplay(0);
    delay(1000);
  }
  delay(1500);
  print3();
  printball(x, y);
  lastball = millis();
  printbar();
  directions = millis() % 2 + 1;
  if (directions == 1)
    direct = 0;
  else
    direct = 1;
}

void error()
{
  delay(50);
  lc.clearDisplay(0);
  x = millis() % 8;
  y = 0;
  count -= 1;
  bar = 3;
  int a = 1;
  times = millis();
  if (count == 2)
  {
    for (; a == 1; times = millis())
    {
      for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
          lc.setLed(0, 7 - j, i, number2[i][j]);
      while (millis() - times < 500)
      {
        if (a == 1)
          a = digitalRead(PIN_A);
        delay(50);
      }
      lc.clearDisplay(0);
      while (millis() - times < 1000&&millis()-times>500)
      {
        if (a == 1)
          a = digitalRead(PIN_A);
        delay(50);
      }
    }
  }
  else
  {
    for (; a == 1; times = millis())
    {
      for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
          lc.setLed(0, 7 - j, i, number1[i][j]);
      while (millis() - times < 500)
      {
        if (a == 1)
          a = digitalRead(PIN_A);
        delay(50);
      }
      lc.clearDisplay(0);
      while (millis() - times < 1000&&millis()-times>500)
      {
        if (a == 1)
          a = digitalRead(PIN_A);
        delay(50);
      }
    }
  }
  printball(x, y);
  lastball = millis();
  printbar();
  directions = millis() % 2 + 1;
  if (directions == 1)
    direct = 0;
  else
    direct = 1;
}

void eraseball(int a, int b)
{
  lc.setLed(0, a, b, false);
}

void printball(int a, int b)
{
  lc.setLed(0, a, b, true);
}

void ball()
{
  if (millis() - lastball > 175)
  {
    if (directions == 1)
    {
      if (y == 6 && g == 0)
      {
        if (x != bar - 1 && x != bar && x != bar + 1 && count != 1)
        {
          eraseball(x, y);
          if (x != 0)
            printball(--x, ++y);
          else
            printball(++x, ++y);
          error();
        }
        else if (x != bar - 1 && x != bar && x != bar + 1 && count == 1)
        {
          eraseball(x, y);
          if (x != 0)
            printball(--x, ++y);
          else
            printball(++x, ++y);
          gameover();
        }
        else g = 1;
      }
      else if (x > 0 && y < 6)
      {
        eraseball(x, y);
        printball(--x, ++y);
        lastball = millis();
        directions = 1;
        g = 0;
      }
      else
      {
        if (x == 1 && y == 6)
          direct = 1;
        if (direct == 0)
          directions += 1;
        else
          directions = 4;
      }
    }
    else if (directions == 2)
    {
      if (y == 6 && g == 0)
      {
        if (x != bar - 1 && x != bar && x != bar + 1 && count != 1)
        {
          eraseball(x, y);
          printball(++x, ++y);
          error();
        }
        else if (x != bar - 1 && x != bar && x != bar + 1 && count == 1)
        {
          eraseball(x, y);
          printball(++x, ++y);
          gameover();
        }
        else g = 1;
      }
      else if (x < 7 && y < 6)
      {
        eraseball(x, y);
        printball(++x, ++y);
        lastball = millis();
        directions = 2;
        g = 0;
      }
      else
      {
        if (direct == 0)
          directions += 1;
        else
          directions -= 1;
      }
    }
    else if (directions == 3)
    {
      if (y == 6 && g == 0)
      {
        if (x != bar - 1 && x != bar && x != bar + 1 && count != 1)
        {
          eraseball(x, y);
          printball(++x, --y);
          error();
        }
        else if (x != bar - 1 && x != bar && x != bar + 1 && count == 1)
        {
          eraseball(x, y);
          printball(++x, --y);
          gameover();
        }
        else g = 1;
      }
      else if (x < 7 && y > 0)
      {
        eraseball(x, y);
        printball(++x, --y);
        lastball = millis();
        directions = 3;
        g = 0;
      }
      else
      {
        if (x == 6 && y == 0)
          direct = 1;
        if (direct == 0)
          directions += 1;
        else
          directions -= 1;
      }
    }
    else
    {
      if (y == 6 && g == 0)
      {
        if (x != bar - 1 && x != bar && x != bar + 1 && count != 1)
        {
          eraseball(x, y);
          if (x == 7)
            printball(--x, --y);
          else
            printball(++x, --y);
          error();
        }
        else if (x != bar - 1 && x != bar && x != bar + 1 && count == 1)
        {
          eraseball(x, y);
          if (x == 7)
            printball(--x, --y);
          else
            printball(++x, --y);
          gameover();
        }
        else g = 1;
      }
      else if (x > 0 && y > 0)
      {
        eraseball(x, y);
        printball(--x, --y);
        lastball = millis();
        directions = 4;
        g = 0;
      }
      else
      {
        if ((x == 0 && y == 0) || (x == 1 && y == 0))
          direct = 0;
        if (direct == 0)
          directions = 1;
        else
          directions -= 1;
      }
    }
  }
}

void printbar()
{
  lc.setLed(0, bar, 7, true);
  lc.setLed(0, bar - 1, 7, true);
  lc.setLed(0, bar + 1, 7, true);
}

void erasebar()
{
  lc.setLed(0, bar + 1, 7, false);
  lc.setLed(0, bar - 1, 7, false);
  lc.setLed(0, bar, 7, false);
}

void barcontrol()
{
  int b = digitalRead(PIN_B);
  int d = digitalRead(PIN_D);
  if (laststateb != b)
    lasttimeb = millis();
  if (millis() - lasttimeb > 50)
  {
    if (b == 0)
    {
      if (millis() - lastpress > 175)
        if (pressb == 0)
        {
          pressb = 1;
          lastpress = millis();
        }
        else
          pressb = 0;

    }
  }
  laststateb = b;

  if (laststated != d)
    lasttimed = millis();
  if (millis() - lasttimed > 50)
  {
    if (d == 0)
    {
      if (millis() - lastpress > 175)
        if (pressd == 0)
        {
          pressd = 1;
          lastpress = millis();
        }
        else
          pressd = 0;

    }
  }
  laststated = d;

  if (pressb == 1 && millis() - lastpress > 175)
  {
    if (bar > 1)
    {
      erasebar();
      bar -= 1;
      printbar();
    }
    pressb = 0;
  }

  if (pressd == 1 && millis() - lastpress > 175)
  {
    if (bar < 6)
    {
      erasebar();
      bar += 1;
      printbar();
    }
    pressd = 0;
  }
}
