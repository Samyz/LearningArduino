#define a 4
#define b 5
#define c 6
#define d 7
#define e 8
#define f 9
#define g 10
#define dp 11
#define switch1 2
#define switch2 3
#define greenled 12
#define redled 13
int arr[10][7]={{1,1,1,1,1,0,1},{0,1,1,0,0,0,0},{1,1,0,1,1,1,0},{1,1,1,1,0,1,0},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int surprise[8]={a,b,f,e,d,c,f,g};
int L[5]={d,e,g};
int laststatesw2=1,count=0,laststatesw1=1;
long lasttimesw2=0,debounce=50,startbib=0,lasttime=0,lasttimesw1=0,times=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(dp,OUTPUT);
  pinMode(switch1,INPUT_PULLUP);
  pinMode(switch2,INPUT_PULLUP);
  pinMode(greenled,OUTPUT);
  pinMode(redled,OUTPUT);
  clearsegment();
  //printsegment(1);
  digitalWrite(greenled,HIGH);
  digitalWrite(redled,HIGH);
  randomSeed(millis());
}

void loop() 
{
  bib();
  input();
}

void bib()
{
  if(millis()-startbib>500)
  {
    digitalWrite(dp,HIGH);
    if(millis()-startbib>1000)
      startbib=millis();
  }
  else
    digitalWrite(dp,LOW);
}

void input()
{
  int sw1=digitalRead(switch1);
  int sw2=digitalRead(switch2);
  if(laststatesw2!=sw2)
    lasttimesw2=millis();
  if(millis()-lasttimesw2>debounce)
  {
    if(sw2==0)
    {
      prepareprint();
    }
  }
  laststatesw2=sw2;
  if(count!=0)
  {
  if(laststatesw1!=sw1)
    lasttimesw1=millis();
  if(millis()-lasttimesw1>debounce)
  {
    if(sw1==0)
    {
      interrupt();
    }
  }
  laststatesw1=sw1;
  }
}

void prepareprint()
{
  count+=1;
  if(count%7==0)
    count-=6;
  printsegment(count,0);
}

void printsegment(int j,int k)
{
  int i;
  clearsegment();
  if(k!=1)
    for(times=millis();millis()-times<250;)
      bib();
  for(i=0;i<7;++i)
  {
    digitalWrite(i+4,!arr[j][i]);
  }
  if(k!=1)
    for(times=millis();millis()-times<250;)
      bib();
}

void interrupt()
{
  digitalWrite(dp,HIGH);
  clearsegment();
  printsurprise();
  int x=random(1,6);
  printsegment(x,1);
  delay(250);
  clearsegment();
  delay(250);
  if(x==count)
  {
    printsegment(count,1);
    digitalWrite(greenled,LOW);
  }
  else
  {
    printL();
    digitalWrite(redled,LOW);
  }
  delay(3000);
  digitalWrite(greenled,HIGH);
  digitalWrite(redled,HIGH);
  clearsegment();
  count=0;
  delay(3000);
}

void printL()
{
  int i;
  for(i=0;i<3;++i)
    digitalWrite(L[i],LOW);
}

void printsurprise()
{
  int i,j;
  for(i=1;i<4;++i)
  {
    for(j=0;j<8;++j)
    {
      digitalWrite(surprise[j],LOW);
      delay(100);
      digitalWrite(surprise[j],HIGH);
      delay(100);
    }
  }
  delay(500);
}

void clearsegment()
{
  int i;
  for(i=4;i<11;++i)
  {
    digitalWrite(i,HIGH);
  }
}
