#include <Servo.h> 
Servo myservo;
#define sbi(PORT,bit) {PORT |=(1<<bit);}
#define cbi(PORT,bit) {PORT &=~(1<<bit);}
#define tbi(PORT,bit) {PORT ^= (1<<bit);}
int servoPin = B1 ;                         //Chan dieu khien servo
void control(int a, int b, int c, int d);
void setup() {
  
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);

myservo.attach(servoPin);     

DDRB=0xff;
Serial.begin(115200);
}

void loop() {
 PORTB=0x00;

int x = analogRead(A0); //doc gia tri a0 gan vao x
int y= analogRead(A1);  //doc gia tri a1 gan vao y
int z=analogRead(A2);   //doc gia tri a2 gan vao z
int t=analogRead(A3);   //doc gia tri a3 gan vao t

control(x,y,z,t);
}
void control(int a, int b, int c, int d)
{
  int n=0; //gan lai gia tri ban dau cho n
  if(a>40||b>40||c>40||d>40)    //dieu kien vao vong lap
  {
    for(int i=0;i<500;i++)    //kiem tra tin hieu nhieu
    {
      int a=  analogRead(A0); //doc gia tri a0 gan vao a
      int b=  analogRead(A1);  //doc gia tri a1 gan vao b
      int c=  analogRead(A2);   //doc gia tri a2 gan vao c
      int d=  analogRead(A3);   //doc gia tri a3 gan vao d
      
      if(a>40)        //dieu kien tang n
      n++; 
      if(b>40)        //dieu kien tang n
      n++;
      if(c>40)        //dieu kien tang n
      n++; 
      if(d>40)        //dieu kien tang n
      n++; 
    if (n>10)    //dieu kien de thuc hien lenh
    {
      sbi(DDRB,2);
      sbi(DDRB,0);
      int servoPos = map(90, 0, 1023, 0, 180);
      myservo.attach(servoPin);
    }
    }
     sbi(DDRB,0);
    cbi(DDRB,2);
    }
    
  }


