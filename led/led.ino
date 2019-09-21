/*void setup()
{
    
  for(int i = 0 ; i < 8 ; i++)
  pinMode(i,OUTPUT);

  pinMode(A0,INPUT);


}


uint16_t nghin,tram,chuc,dv;
void led7(uint16_t ADC_val)
{
  dv = ADC_val % 10;
  ADC_val /= 10;
  chuc = ADC_val % 10;
  ADC_val /= 10;
  tram = ADC_val % 10;
  ADC_val /= 10;
  nghin = ADC_val;
 PORTD = nghin|(1<<4);
    delay(1);
  PORTD = tram|(1<<5);
    delay(1);
  PORTD = chuc|(1<<6);
    delay(1);
  PORTD = dv|(1<<7);
    delay(1);  
}
void loop()
{

  led7(analogRead(A0));
  

}*/
float x=0;
void setup()
{
  
  pinMode(2,OUTPUT);

  pinMode(A0,INPUT);
}
void loop()
{
  x=7+(analogRead(A0)/1000);
  Serial.println(x);
//  analogWrite(9, x);
  PORTD= 0b00000100;
  delay(x);
  PORTD=0X00;
  delay(x);
  
}

