
int ledPin = 13;                 // đèn LED được kết nối với chân digital 13

void setup()
{
  pinMode(ledPin, OUTPUT);      // thiết đặt chân ledPin là OUTPUT
}

void loop()
{
  digitalWrite(ledPin, HIGH);   // bật đèn led
  delay(1000);                  // dừng trong 1 giây
  digitalWrite(ledPin, LOW);    // tắt đèn led
  delay(1000);                  // dừng trong 1 giây
}
