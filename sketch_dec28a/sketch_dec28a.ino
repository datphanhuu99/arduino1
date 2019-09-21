#include <dummy.h>


void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);   // bật đèn led sáng
  delay(1000);               // dừng chương trình trong 1 giây => thây đèn sáng được 1 giây
  digitalWrite(13, LOW);    // tắt đèn led
  delay(1000);
}
