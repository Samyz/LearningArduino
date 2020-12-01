#include "LedControl.h"

const int font_count = 80;
unsigned const char PROGMEM myfont[80][5] = {
  {0, 0, 0, 0, 0}, // space
  {0x3f, 0x48, 0x48, 0x48, 0x3f}, // A
  {0x7f, 0x49, 0x49, 0x49, 0x36},
  {0x3e, 0x41, 0x41, 0x41, 0x22},
  {0x7f, 0x41, 0x41, 0x22, 0x1c},
  {0x7f, 0x49, 0x49, 0x49, 0x41},
  {0x7f, 0x48, 0x48, 0x48, 0x40},
  {0x3e, 0x41, 0x49, 0x49, 0x2e},  
  {0x7f, 0x08, 0x08, 0x08, 0x7f},
  {0x00, 0x41, 0x7f, 0x41, 0x00},
  {0x06, 0x01, 0x01, 0x01, 0x7e},
  {0x7f, 0x08, 0x14, 0x22, 0x41},
  {0x7f, 0x01, 0x01, 0x01, 0x01},
  {0x7f, 0x20, 0x10, 0x20, 0x7f},
  {0x7f, 0x10, 0x08, 0x04, 0x7f},
  {0x3e, 0x41, 0x41, 0x41, 0x3e},
  {0x7f, 0x48, 0x48, 0x48, 0x30},  
  {0x3e, 0x41, 0x45, 0x42, 0x3d},
  {0x7f, 0x48, 0x4c, 0x4a, 0x31},
  {0x31, 0x49, 0x49, 0x49, 0x46},
  {0x40, 0x40, 0x7f, 0x40, 0x40},
  {0x7e, 0x01, 0x01, 0x01, 0x7e},
  {0x7c, 0x02, 0x01, 0x02, 0x7c},
  {0x7f, 0x02, 0x04, 0x02, 0x7f},
  {0x63, 0x14, 0x08, 0x14, 0x63},
  {0x60, 0x10, 0x0f, 0x10, 0x60},
  {0x43, 0x45, 0x49, 0x51, 0x61},  // Z
  {0x01, 0x00, 0x00, 0x00, 0x00},  // .
  {0x00, 0x00, 0x70, 0x00, 0x00},  // '
  {0x00, 0x00, 0x14, 0x00, 0x00},  // :
  {0x7F, 0x22, 0x14, 0x8,  0x00},  // selector arrow
  {0x3E, 0x45, 0x49, 0x51, 0x3E}, // 0 - 9
  {0x00, 0x21, 0x7F, 0x1 , 0x0 },
  {0x21, 0x43, 0x45, 0x49, 0x31},
  {0x22, 0x41, 0x49, 0x49, 0x36},
  {0xC , 0x14, 0x24, 0x7F, 0x4},
  {0x72, 0x51, 0x51, 0x51, 0x4E},
  {0x3E, 0x49, 0x49, 0x49, 0x26},
  {0x40, 0x40, 0x4F, 0x50, 0x60},
  {0x36, 0x49, 0x49, 0x49, 0x36},
  {0x32, 0x49, 0x49, 0x49, 0x3E},
  {0x2,  0x15, 0x15, 0x15, 0xF },  // a
  {0x7F, 0x5,  0x9,  0x9,  0x6 },
  {0xE,  0x11, 0x11, 0x11, 0x2 },
  {0x6,  0x9,  0x9,  0x5,  0x7F},
  {0xE,  0x15, 0x15, 0x15, 0xC },
  {0x8,  0x3F, 0x44, 0x40, 0x20},  // f
  {0x18, 0x25, 0x25, 0x25, 0x3E},
  {0x7F, 0x8,  0x10, 0x10, 0xF},
  {0x0,  0x0,  0x2F, 0x0,  0x0},
  {0x2,  0x1,  0x11, 0x5E, 0x0},
  {0x7F, 0x4,  0x6,  0x11, 0x0},
  {0x0,  0x41, 0x7F, 0x1,  0x0},  // l
  {0x1F, 0x10, 0xC,  0x10, 0xF},
  {0x1F, 0x8,  0x10, 0x10, 0xF},
  {0xE,  0x11, 0x11, 0x11, 0xE},
  {0x1F, 0x14, 0x14, 0x14, 0x8},
  {0x8,  0x14, 0x14, 0xC,  0x1F}, // q
  {0x1F, 0x8,  0x10, 0x10, 0x8},
  {0x9,  0x15, 0x15, 0x15, 0x2},
  {0x10, 0x7E, 0x11, 0x1,  0x2},
  {0x1E, 0x1,  0x1,  0x2,  0x1F}, // u
  {0x1C, 0x2,  0x1,  0x2,  0x1C},
  {0x1E, 0x1,  0x3,  0x1,  0x1E},
  {0x11, 0xA,  0x4,  0xA,  0x11},
  {0x18, 0x5,  0x5,  0x5,  0x1E}, 
  {0x11, 0x13, 0x15, 0x19, 0x11}, // z
  // invader sprites - may still need some tweaking
  {0x0,  0x19, 0x3A, 0x6D, 0x7A}, // top invader left
  {0x7A, 0x6D, 0x3A, 0x19, 0x0} , // top invader right
  {0x0,  0x1A, 0x3D, 0x68, 0x7C}, // top invader left wiggle
  {0x7C, 0x68, 0x3D, 0x1A, 0x0},  // top invader right wiggle
  {0x38, 0xD,  0x5E, 0x36, 0x1C}, // middle invader left
  {0x1C, 0x36, 0x5E, 0xD,  0x38},
  {0xE,  0xC,  0x5E, 0x35, 0x1C}, // middle invader left wiggle
  {0x1C, 0x35, 0x5E, 0xC,  0xE},
  {0x19, 0x39, 0x3A, 0x6C, 0x7A}, // bottom invader left
  {0x7A, 0x6C, 0x3A, 0x39, 0x19},
  {0x18, 0x39, 0x3B, 0x6C, 0x7C}, // bottom invader left wiggle
  {0x7C, 0x6C, 0x3B, 0x39, 0x18},
};
/*


const int bigfont_count = 10;
unsigned const char PROGMEM mybigfont[10][20] = {
   {0x3F,0x7F,0xE0,0xC1,0xC3,0xC7,0xCE,0xFC,0x7F,0x3F,0xF0,0xF8,0xFC,0xCC,0x8C,0xC,0xC,0x3C,0xF8,0xF0} //0
  ,{0x0,0x0,0x30,0x70,0xFF,0xFF,0x0,0x0,0x0,0x0,0x0,0x0,0xC,0xC,0xFC,0xFC,0xC,0xC,0x0,0x0}
  ,{0x30,0x70,0xE0,0xC0,0xC0,0xC1,0xC3,0xE7,0x7E,0x3C,0xC,0x1C,0x3C,0x7C,0xEC,0xCC,0x8C,0xC,0xC,0xC}
  ,{0x30,0x70,0xE0,0xC0,0xC0,0xC3,0xC3,0xE3,0x7F,0x3C,0x30,0x38,0x1C,0xC,0xC,0xC,0xC,0x1C,0xF8,0xF0}
  ,{0x3,0x7,0xE,0x1C,0x38,0x70,0xFF,0xFF,0x0,0x0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFC,0xFC,0xC0,0xC0}
  ,{0xFC,0xFC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCE,0xC7,0xC3,0x30,0x38,0x1C,0xC,0xC,0xC,0xC,0x1C,0xF8,0xF0}
  ,{0x3F,0x7F,0xE3,0xC3,0xC3,0xC3,0xC3,0xE3,0x61,0x20,0xF0,0xF8,0x1C,0xC,0xC,0xC,0xC,0x9C,0xF8,0xF0}
  ,{0xC0,0xC0,0xC0,0xC1,0xC3,0xC7,0xCE,0xDC,0xF8,0xF0,0x0,0x0,0x0,0xFC,0xFC,0x0,0x0,0x0,0x0,0x0}
  ,{0x3C,0x7F,0xE7,0xC3,0xC3,0xC3,0xC3,0xE7,0x7F,0x3C,0xF0,0xF8,0x9C,0xC,0xC,0xC,0xC,0x9C,0xF8,0xF0}
  ,{0x3C,0x7E,0xE7,0xC3,0xC3,0xC3,0xC3,0xC3,0x7F,0x3F,0x10,0x18,0x1C,0xC,0xC,0xC,0xC,0x1C,0xF8,0xF0}
};

*/

const int tinyfont_count = 42;
unsigned const int PROGMEM mytinyfont[42][3] = {
   //a-z
   {0, 0, 0}   // space!   
  ,{0x1F, 0x14, 0x1F}
  ,{0x1F, 0x15, 0xA}
  ,{0x1F, 0x11, 0x11}
  ,{0x1F, 0x11, 0xE}
  ,{0x1F, 0x15, 0x11}
  ,{0x1F, 0x14, 0x10}
  ,{0x1F, 0x11, 0x17}
  ,{0x1F, 0x4,  0x1F}
  ,{0x11, 0x1F, 0x11}
  ,{0x3,  0x1,  0x1F}
  ,{0x1F, 0x4,  0x1B}
  ,{0x1F, 0x1,  0x1}
  ,{0x1F, 0x8,  0x1F}
  ,{0x1F, 0x10, 0xF}
  ,{0x1F, 0x11, 0x1F}
  ,{0x1F, 0x14, 0x1C}
  ,{0x1C, 0x14, 0x1F}
  ,{0x1F, 0x16, 0x1D}
  ,{0x1D, 0x15, 0x17}
  ,{0x10, 0x1F, 0x10}
  ,{0x1F, 0x1,  0x1F}
  ,{0x1E, 0x1,  0x1E}
  ,{0x1F, 0x2,  0x1F}
  ,{0x1B, 0x4,  0x1B}
  ,{0x1C, 0x7,  0x1C}
  ,{0x13, 0x15, 0x19}
  ,{0x01, 0x00, 0x00}  // .
  ,{0x00, 0x0A, 0x00}  // :
  ,{0x18, 0x00, 0x00}  // '
  ,{0x1D, 0x00, 0x00}  // !
  ,{0x10, 0x15, 0x1C}  // ?
  ,{0x1F, 0x11, 0x1F}  //0 - 9
  ,{0x00, 0x00, 0x1F}
  ,{0x17, 0x15, 0x1D}
  ,{0x11, 0x15, 0x1F}
  ,{0x1C, 0x4,  0x1F}
  ,{0x1D, 0x15, 0x17}
  ,{0x1F, 0x15, 0x17}
  ,{0x10, 0x10, 0x1F}
  ,{0x1F, 0x15, 0x1F}
  ,{0x1D, 0x15, 0x1F}
};//#include "FontLEDClock.h" // Font library

LedControl lc=LedControl(11,13,10,4);  // DIN,CLK,CS,Number of LED Module
uint8_t intensity = 1;

unsigned long delaytime=50;  // time to updates of the display

int timer1_counter;
int secrun=0,minrun=0,hourrun=0,daterun=1,monthrun=1,yearrun=18,datarun=0,bobbycount=0,bobbys=0,bobbym=0,bobbyh=0,fords=0,fordm=0,fordh=0,fordcount=0,fordeasy=0;;
int asap1[12]={31,28,31,30,31,30,31,31,30,31,30,31},asap2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
char aha[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"},aho[12][4]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
void setup()
{
  Serial.begin(9600);
  //pinMode(ledPin, OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  //timer1_counter=65500;
  timer1_counter = 3036;   // preload timer 65536-16MHz/256/1Hz
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
  int devices=lc.getDeviceCount();  // find no of LED modules
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {  // set up each device 
    lc.shutdown(address,false);
    lc.setIntensity(address,3);
    lc.clearDisplay(address);
  }
}

ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
  //digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
  ++secrun;
  if(secrun==60)
  {
    ++minrun;
    secrun=0;
    if(minrun==60)
    {
      ++hourrun;
      minrun=0;
      if(hourrun==24)
      {
        hourrun=0;
        if(yearrun%4==0)
        {
          ++daterun;
          ++datarun;
          if(datarun>6)
            datarun=0;
          if(daterun>asap2[monthrun-1])
          {
            daterun=1;
            ++monthrun;
            if(monthrun>12)
            {
              monthrun=1;
              ++yearrun;
              if(yearrun>99)
                yearrun=0;
            }
          }
        }
        else
        {
          ++daterun;
          ++datarun;
          if(datarun>6)
            datarun=0;
          if(daterun>asap1[monthrun-1])
          {
            daterun=1;
            ++monthrun;
            if(monthrun>12)
            {
              monthrun=1;
              ++yearrun;
              if(yearrun>99)
                yearrun=0;
            }
          }          
        }
      }
    }
  }
  if(bobbycount==1)
  {
    if(bobbys>0)
      bobbys-=1;
    else
    {
      if(bobbym>0)
      {
        bobbys=60;
        bobbys-=1;
        bobbym-=1;
      }
      else
      {
        if(bobbyh>0)
        {
          bobbym=60;
          bobbym-=1;
          bobbyh-=1;
        }
      }
    }
  }
  if(fordcount==1)
  {
    fords+=1;
    if(fords==60)
    {
      fords=0;
      fordm+=1;
      if(fordm==60)
      {
        fordm=0;
        fordh+=1;
        if(fordh==24)
          fordh=0;
      }
    }
  }
}

//plot a point on the display
void plot (uint8_t x, uint8_t y, uint8_t value) {

  //select which matrix depending on the x coord
  uint8_t address;
  if (x >= 0 && x <= 7)   { address = 3; }
  if (x >= 8 && x <= 15)  { address = 2; x = x - 8; }
  if (x >= 16 && x <= 23) { address = 1; x = x - 16;}
  if (x >= 24 && x <= 31) { address = 0; x = x - 24;}
  lc.setLed(address, y, x, value);
}

//clear screen
void clear_display() {
  for (uint8_t address = 0; address < 4; address++) {
    lc.clearDisplay(address);
  }
}

void print_tiny_char(uint8_t x, uint8_t y, char c)
{
  uint8_t dots;
  if (c >= 'A' && c <= 'Z' || (c >= 'a' && c <= 'z') ) { c &= 0x1F; }  // A-Z maps to 1-26 
  else if (c >= '0' && c <= '9') { c = (c - '0') + 32; }
  else if (c == ' ') { c = 0;  } // space 
  else if (c == '.') { c = 27; } // full stop 
  else if (c == ':') { c = 28; } // colon 
  else if (c == '\''){ c = 29; } // single quote mark 
  else if (c == '!') { c = 30; } // single quote mark 
  else if (c == '?') { c = 31; } // single quote mark 

  for (uint8_t col = 0; col < 3; col++) {
    dots = pgm_read_byte_near(&mytinyfont[c][col]);
    for (uint8_t row = 0; row < 5; row++) {
      if (dots & (16 >> row))
        plot(x + col, y + row, 1);
      else
        plot(x + col, y + row, 0);
    }
  }
}

void print_normal_char(uint8_t x, uint8_t y, char c)
{

  uint8_t dots;
  if (c >= 'A' && c <= 'Z' ) { c &= 0x1F; }  // A-Z maps to 1-26
  else if (c >= 'a' && c <= 'z') { c = (c - 'a') + 41; }  // A-Z maps to 41-67
  else if (c >= '0' && c <= '9') { c = (c - '0') + 31; }
  else if (c == ' ') { c = 0; } // space
  else if (c == '.') { c = 27; } // full stop
  else if (c == '\'') { c = 28; } // single quote mark
  else if (c == ':') { c = 29; } // clock_mode selector arrow
  else if (c == '>') { c = 30; } // clock_mode selector arrow
  else if (c >= -80 && c <= -67) { c *= -1; }

  for (uint8_t col = 0; col < 5; col++) {
    dots = pgm_read_byte_near(&myfont[c][col]);
    for (uint8_t row = 0; row < 7; row++) {
      if (dots & (64 >> row)) {   // only 7 rows.
        plot(x + col, y + row, 1);
      } else {
        plot(x + col, y + row, 0);
      }
    }
  }
}

char wow[6];
long times;

void printtime(int oh)
{
  if(minrun<10)
  {
    wow[2]='0';
    wow[3]=minrun+48;
  }
  else
  {
    int aaaa=minrun/10,bbbb=minrun%10;
    wow[2]=aaaa+48;
    wow[3]=bbbb+48;
  }
  if(hourrun<10)
  {
    wow[0]='0';
    wow[1]=hourrun+48;
  }
  else
  {
    int aaaa=hourrun/10,bbbb=hourrun%10;
    wow[0]=aaaa+48;
    wow[1]=bbbb+48;
  }
  if(oh==-1)
  {
    for(int i=0;i<2;++i)
    {
      print_normal_char(i*7+1,1,wow[i]);
    }
    if(millis()-times<500)
      for(int i=15;i<17;++i)
      {
        plot(i,2,1);
        plot(i,3,1);
        plot(i,5,1);
        plot(i,6,1);
      }
    else if(millis()-times<1000)
      for(int i=15;i<17;++i)
      {
        plot(i,2,0);
        plot(i,3,0);
        plot(i,5,0);
        plot(i,6,0);
      }
    else times=millis();
    for(int i=2;i<4;++i)
    {
      print_normal_char(i*7+5,1,wow[i]);
    }
  }
  else if(oh==0)
  {
    if(millis()-times<150)
      for(int i=0;i<2;++i)
      {
        print_normal_char(i*7+1,1,wow[i]);
      }
    else if(millis()-times<300)
      for(int i=0;i<2;++i)
      {
        print_normal_char(i*7+1,1,0);
      }
    else times=millis();
    for(int i=15;i<17;++i)
    {
      plot(i,2,1);
      plot(i,3,1);
      plot(i,5,1);
      plot(i,6,1);
    }
    for(int i=2;i<4;++i)
    {
      print_normal_char(i*7+5,1,wow[i]);
    }
  }
  else
  {
    for(int i=0;i<2;++i)
    {
      print_normal_char(i*7+1,1,wow[i]);
    }
    for(int i=15;i<17;++i)
    {
      plot(i,2,1);
      plot(i,3,1);
      plot(i,5,1);
      plot(i,6,1);
    }
    if(millis()-times<150)
      for(int i=2;i<4;++i)
      {
        print_normal_char(i*7+5,1,wow[i]);
      }
    else if(millis()-times<300)
      for(int i=2;i<4;++i)
      {
        print_normal_char(i*7+5,1,0);
      }
    else times=millis();
    if(millis()<times)
      times=millis();
  }
}

void printdate(int oh)
{
  if(daterun<10)
  {
    wow[0]='0';
    wow[1]=daterun+48;
  }
  else
  {
    int aaaa=daterun/10,bbbb=daterun%10;
    wow[0]=aaaa+48;
    wow[1]=bbbb+48;
  }
  if(oh==-1)
  {
    for(int i=0;i<2;++i)
    {
      print_normal_char(i*7+1,1,wow[i]);
    }
    for(int i=0;i<3;++i)
    {
      print_tiny_char(i*5+17,3,aha[datarun][i]);
    }
  }
  else if(oh==0)
  {
    if(millis()-times<150)
      for(int i=0;i<2;++i)
      {
        print_normal_char(i*7+1,1,wow[i]);
      }
    else if(millis()-times<300)
      for(int i=0;i<2;++i)
      {
        print_normal_char(i*7+1,1,0);
      }
    else times=millis();
    for(int i=0;i<3;++i)
    {
      print_tiny_char(i*5+17,3,aha[datarun][i]);
    }
  }
  else
  {
    for(int i=0;i<2;++i)
    {
      print_normal_char(i*7+1,1,wow[i]);
    }
    if(millis()-times<150)
      for(int i=0;i<3;++i)
      {
        print_tiny_char(i*5+17,3,aha[datarun][i]);
      }
    else if(millis()-times<300)
      for(int i=0;i<3;++i)
      {
        print_tiny_char(i*5+17,3,0);
      }
    else times=millis();
    if(millis()<times)
      times=millis();
  }
}

void printmy(int oh)
{
  if(yearrun<10)
  {
    wow[2]='0';
    wow[3]=yearrun+48;
  }
  else
  {
    int aaaa=yearrun/10,bbbb=yearrun%10;
    wow[2]=aaaa+48;
    wow[3]=bbbb+48;
  }
  if(oh==-1)
  {
    for(int i=0;i<3;++i)
    {
      print_tiny_char(i*5+1,3,aho[monthrun-1][i]);
    }
    for(int i=2;i<4;++i)
    {
      print_normal_char(i*7+5,1,wow[i]);
    }
  }
  else if(oh==0)
  {
    if(millis()-times<150)
      for(int i=0;i<3;++i)
      {
        print_tiny_char(i*5+1,3,aho[monthrun-1][i]);
      }
    else if(millis()-times<300)
      for(int i=0;i<3;++i)
      {
        print_tiny_char(i*5+1,3,0);
      }
    else times=millis();
    for(int i=2;i<4;++i)
    {
      print_normal_char(i*7+5,1,wow[i]);
    }
  }
  else
  {
    for(int i=0;i<3;++i)
    {
      print_tiny_char(i*5+1,3,aho[monthrun-1][i]);
    }
    if(millis()-times<150)
      for(int i=2;i<4;++i)
      {
        print_normal_char(i*7+5,1,wow[i]);
      }
    else if(millis()-times<300)
      for(int i=2;i<4;++i)
      {
        print_normal_char(i*7+5,1,0);
      }
    else times=millis();
    if(millis()<times)
      times=millis();
  }
}

void printalarm(int oh)
{
  if(bobbyh<10)
  {
    wow[0]='0';
    wow[1]=bobbyh+48;
  }
  else
  {
    int aaaa=bobbyh/10,bbbb=bobbyh%10;
    wow[0]=aaaa+48;
    wow[1]=bbbb+48;
  }
  if(bobbym<10)
  {
    wow[2]='0';
    wow[3]=bobbym+48;
  }
  else
  {
    int aaaa=bobbym/10,bbbb=bobbym%10;
    wow[2]=aaaa+48;
    wow[3]=bbbb+48;
  }
  if(bobbys<10)
  {
    wow[4]='0';
    wow[5]=bobbys+48;
  }
  else
  {
    int aaaa=bobbys/10,bbbb=bobbys%10;
    wow[4]=aaaa+48;
    wow[5]=bbbb+48;
  }
  if(oh==-1)
  {
    for(int i=0;i<2;++i)
    {
      print_tiny_char(i*4+2,3,wow[i]);
    }
    plot(10,4,HIGH);
    plot(10,6,HIGH);
    plot(20,4,HIGH);
    plot(20,6,HIGH);
    for(int i=2;i<4;++i)
    {
      print_tiny_char(i*4+4,3,wow[i]);
    }
    for(int i=4;i<6;++i)
    {
      print_tiny_char(i*4+6,3,wow[i]);
    }
  }
  else if(oh==0)
  {
    if(millis()-times<150)
      for(int i=0;i<2;++i)
      {
        print_tiny_char(i*4+2,3,wow[i]);
      }
    else if(millis()-times<300)
      for(int i=0;i<2;++i)
      {
         print_tiny_char(i*4+2,3,0);
      }
    else times=millis();
    plot(10,4,HIGH);
    plot(10,6,HIGH);
    plot(20,4,HIGH);
    plot(20,6,HIGH);
    for(int i=2;i<4;++i)
    {
      print_tiny_char(i*4+4,3,wow[i]);
    }
    for(int i=4;i<6;++i)
    {
      print_tiny_char(i*4+6,3,wow[i]);
    }
  }
  else if(oh==1)
  {
    for(int i=0;i<2;++i)
    {
      print_tiny_char(i*4+2,3,wow[i]);
    }
    plot(10,4,HIGH);
    plot(10,6,HIGH);
    plot(20,4,HIGH);
    plot(20,6,HIGH);
    if(millis()-times<150)
      for(int i=2;i<4;++i)
      {
        print_tiny_char(i*4+4,3,wow[i]);
      }
    else if(millis()-times<300)
      for(int i=2;i<4;++i)
      {
         print_tiny_char(i*4+4,3,0);
      }
    else times=millis();
    for(int i=4;i<6;++i)
    {
      print_tiny_char(i*4+6,3,wow[i]);
    }
  }
  else
  {
    for(int i=0;i<2;++i)
    {
      print_tiny_char(i*4+2,3,wow[i]);
    }
    plot(10,4,HIGH);
    plot(10,6,HIGH);
    plot(20,4,HIGH);
    plot(20,6,HIGH);
    for(int i=2;i<4;++i)
    {
      print_tiny_char(i*4+4,3,wow[i]);
    }
    if(millis()-times<150)
    for(int i=4;i<6;++i)
    {
      print_tiny_char(i*4+6,3,wow[i]);
    }
    else if(millis()-times<300)
      for(int i=4;i<6;++i)
      {
         print_tiny_char(i*4+6,3,0);
      }
    else times=millis();
  }
  if(bobbys==0&&bobbym==0&&bobbyh==0&&bobbycount==1)
  {
    times=millis();
    bobbycount=0;
    bobbys=0;
    bobbym=0;
    bobbyh=0;
    if(bobbyh<10)
    {
      wow[0]='0';
      wow[1]=bobbyh+48;
    }
    else
    {
      int aaaa=bobbyh/10,bbbb=bobbyh%10;
      wow[0]=aaaa+48;
      wow[1]=bbbb+48;
    }
    if(bobbym<10)
    {
      wow[2]='0';
      wow[3]=bobbym+48;
    }
    else
    {
      int aaaa=bobbym/10,bbbb=bobbym%10;
      wow[2]=aaaa+48;
      wow[3]=bbbb+48;
    }
    if(bobbys<10)
    {
      wow[4]='0';
      wow[5]=bobbys+48;
    }
    else
    {
      int aaaa=bobbys/10,bbbb=bobbys%10;
      wow[4]=aaaa+48;
      wow[5]=bbbb+48;
    }
    while(1)
    {
      int c=digitalRead(4);
      if(c==0)
      {
        delay(200);
        digitalWrite(6,HIGH);
        break;
      }
      if(millis()-times<500)
      {
        digitalWrite(6,LOW);
        for(int i=0;i<2;++i)
        {
          print_tiny_char(i*4+2,3,wow[i]);
        }
        plot(10,4,HIGH);
        plot(10,6,HIGH);
        plot(20,4,HIGH);
        plot(20,6,HIGH);
        for(int i=2;i<4;++i)
        {
          print_tiny_char(i*4+4,3,wow[i]);
        }
        for(int i=4;i<6;++i)
        {
          print_tiny_char(i*4+6,3,wow[i]);
        }
      }
      else if(millis()-times<1000)
      {
        digitalWrite(6,HIGH);
        for(int i=0;i<2;++i)
        {
          print_tiny_char(i*4+2,3,0);
        }
        plot(10,4,LOW);
        plot(10,6,LOW);
        plot(20,4,LOW);
        plot(20,6,LOW);
        for(int i=2;i<4;++i)
        {
          print_tiny_char(i*4+4,3,0);
        }
        for(int i=4;i<6;++i)
        {
          print_tiny_char(i*4+6,3,0);
        }
      }
      else times=millis();
    }
  }
}

void printclock()
{
  int c=digitalRead(4);
  if(fordh<10)
  {
    wow[0]='0';
    wow[1]=fordh+48;
  }
  else
  {
    int aaaa=fordh/10,bbbb=fordh%10;
    wow[0]=aaaa+48;
    wow[1]=bbbb+48;
  }
  if(fordm<10)
  {
    wow[2]='0';
    wow[3]=fordm+48;
  }
  else
  {
    int aaaa=fordm/10,bbbb=fordm%10;
    wow[2]=aaaa+48;
    wow[3]=bbbb+48;
  }
  if(fords<10)
  {
    wow[4]='0';
    wow[5]=fords+48;
  }
  else
  {
    int aaaa=fords/10,bbbb=fords%10;
    wow[4]=aaaa+48;
    wow[5]=bbbb+48;
  }
  for(int i=0;i<2;++i)
  {
    print_tiny_char(i*4+2,3,wow[i]);
  }
  if(millis()-times<500)
  {
    plot(10,4,HIGH);
    plot(10,6,HIGH);
    plot(20,4,HIGH);
    plot(20,6,HIGH);
  }
  else if(millis()-times<1000)
  {
    plot(10,4,LOW);
    plot(10,6,LOW);
    plot(20,4,LOW);
    plot(20,6,LOW);
  }
  else times=millis();
  for(int i=2;i<4;++i)
  {
    print_tiny_char(i*4+4,3,wow[i]);
  }
  for(int i=4;i<6;++i)
  {
    print_tiny_char(i*4+6,3,wow[i]);
  }
  if(c==0&&fordeasy==0)
  {
    fordcount=1;
    fordeasy=1;
    fords=0;
    fordm=0;
    fordh=0;
    delay(200);
    while(1)
    {
      if(fordh<10)
      {
        wow[0]='0';
        wow[1]=fordh+48;
      }
      else
      {
        int aaaa=fordh/10,bbbb=fordh%10;
        wow[0]=aaaa+48;
        wow[1]=bbbb+48;
      }
      if(fordm<10)
      {
        wow[2]='0';
        wow[3]=fordm+48;
      }
      else
      {
        int aaaa=fordm/10,bbbb=fordm%10;
        wow[2]=aaaa+48;
        wow[3]=bbbb+48;
      }
      if(fords<10)
      {
        wow[4]='0';
        wow[5]=fords+48;
      }
      else
      {
        int aaaa=fords/10,bbbb=fords%10;
        wow[4]=aaaa+48;
        wow[5]=bbbb+48;
      }
      for(int i=0;i<2;++i)
      {
        print_tiny_char(i*4+2,3,wow[i]);
      }
      if(millis()-times<500)
      {
        plot(10,4,HIGH);
        plot(10,6,HIGH);
        plot(20,4,HIGH);
        plot(20,6,HIGH);
      }
      else if(millis()-times<1000)
      {
        plot(10,4,LOW);
        plot(10,6,LOW);
        plot(20,4,LOW);
        plot(20,6,LOW);
      }
      else times=millis();
      for(int i=2;i<4;++i)
      {
        print_tiny_char(i*4+4,3,wow[i]);
      }
      for(int i=4;i<6;++i)
      {
        print_tiny_char(i*4+6,3,wow[i]);
      }
      c=digitalRead(4);
      if(c==0)
      {
        fordcount=0;
        delay(200);
        break;
      }
    }
  }
  else if(fordeasy==1)
  {
    c=digitalRead(4);
    if(c==0)
    {
      delay(200);
      fordeasy=0;
      fords=0;
      fordm=0;
      fordh=0;
    }
  }
}

void setalarm()
{
  int a,b,c=digitalRead(4);
  if(c==0&&bobbycount!=1)
  {
    delay(200);
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        bobbyh+=10;
        if(bobbyh>23)
          bobbyh=0;
      }
      if(b==0)
      {
        delay(100);
        bobbyh+=1;
        if(bobbyh>23)
          bobbyh=0;
      }
      printalarm(0);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        bobbym+=10;
        if(bobbym>59)
          bobbym=0;
      }
      if(b==0)
      {
        delay(100);
        bobbym+=1;
        if(bobbym>59)
          bobbym=0;
      }
      printalarm(1);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        bobbys+=10;
        if(bobbys>59)
          bobbys=0;
      }
      if(b==0)
      {
        delay(100);
        bobbys+=1;
        if(bobbys>59)
          bobbys=0;
      }
      printalarm(2);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    if(bobbys!=0||bobbym!=0||bobbyh!=0)
    {
      bobbycount=1;
    }
  }
}

void settime()
{
  int a,b,c=digitalRead(4);
  if(c==0)
  {
    delay(200);
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        hourrun+=10;
        if(hourrun>23)
          hourrun=0;
      }
      if(b==0)
      {
        delay(100);
        hourrun+=1;
        if(hourrun>23)
          hourrun=0;
      }
      printtime(0);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        minrun+=10;
        if(minrun>59)
          minrun=0;
      }
      if(b==0)
      {
        delay(100);
        minrun+=1;
        if(minrun>59)
          minrun=0;
      }
      printtime(1);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    for(int i=0;i<4;++i)
      lc.clearDisplay(i);
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        daterun+=10;
        if(yearrun%4==0)
        {
          if(daterun>asap2[monthrun-1])
            daterun=1;
        }
        else
        {
          if(daterun>asap1[monthrun-1])
            daterun=1;
        }
      }
      if(b==0)
      {
        delay(100);
        daterun+=1;
        if(yearrun%4==0)
        {
          if(daterun>asap2[monthrun-1])
            daterun=1;
        }
        else
        {
          if(daterun>asap1[monthrun-1])
            daterun=1;
        }
      }
      printdate(0);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0||b==0)
      {
        delay(100);
        datarun+=1;
        if(datarun>6)
          datarun=0;
      }
      printdate(1);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    for(int i=0;i<4;++i)
      lc.clearDisplay(i);
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0||b==0)
      {
        delay(100);
        monthrun+=1;
        if(monthrun>12)
          monthrun=1;
      }
      printmy(0);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    while(1)
    {
      c=digitalRead(4);
      b=digitalRead(3);
      a=digitalRead(2);
      if(a==0)
      {
        delay(100);
        yearrun+=10;
        if(yearrun>99)
          yearrun=0;
      }
      if(b==0)
      {
        delay(100);
        yearrun+=1;
        if(yearrun>99)
          yearrun=0;
      }
      printmy(1);
      if(c==0)
      {
        delay(100);
        break;
      }
    }
    for(int i=0;i<4;++i)
      lc.clearDisplay(i);
  }
}

int loopp=0;

void loop()
{
  int d=digitalRead(5);
  if(d==0&&bobbycount!=1)
  {
    //digitalWrite(6,LOW);
    fords=0;
    fordm=0;
    fordh=0;
    delay(100);
    for(int i=0;i<4;++i)
      lc.clearDisplay(i);
      ++loopp;
      if(loopp>4)
        loopp=0;
    //digitalWrite(6,HIGH);
  }
  if(loopp==0)
  {
    printtime(-1);
    settime();
  }  
  else if(loopp==1)
  {
    printdate(-1);
    settime();
  }
  else if(loopp==2)
  {
    printmy(-1);
    settime();
  }
  else if(loopp==3)
  {
    printalarm(-1);
    setalarm();
  }
  else
  {
    printclock();
  }
}
