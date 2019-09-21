#include <Servo.h>
Servo MyServo;

#define Max_A1 29
#define Max_A2 40
#define Max_A3 29

#define Sound 10

int x1,x2,x3;

void turn_on_sound(void) {
  digitalWrite(Sound,HIGH);
  delay(1);
  digitalWrite(Sound,LOW);
  MyServo.write(10);
  delay(3000);
  MyServo.write(180);
  delay(3000);
}

void setup() {
  //MyServo init
  MyServo.attach(9);
  // analog
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  //init sound
  pinMode(Sound,OUTPUT);
  digitalWrite(Sound,LOW);
  //serial
  Serial.begin(115200);
  delay(200);
}

int k=0;
#define Count_Avoid_Noise 3

void loop() {
  x1 = analogRead(A1);
  x2 = analogRead(A2);
  x3 = analogRead(A3);
  if(x1>=Max_A1||x2>=Max_A2||x3>=Max_A3)
  {
    if (x1>=Max_A1) {
      k++;
    }
    if (x2>=Max_A2) {
      k++;
    }
    if (x3>=Max_A3) {
      k++;
    }
  } else {
    k=0;
  }
  if (k>=Count_Avoid_Noise) {
    Serial.print("A1: ");
    Serial.println(x1);
    Serial.print("A2: ");
    Serial.println(x2);
    Serial.print("A3: ");
    Serial.println(x3);
    turn_on_sound();
    k=0;
  }

  /*
  if (x1>=Max_A1) {
    Serial.print("A1: ");
    Serial.println(x1);
    turn_on_sound();
  }
  delay(1);
  

  if (x2>=Max_A2) { 
    Serial.print("A2: ");
    Serial.println(x2);
    turn_on_sound();
  }
  delay(1);
    

  if (x3>=Max_A3) {
    Serial.print("A3: ");
    Serial.println(x3);
    turn_on_sound();
  }
  delay(1);*/
}

