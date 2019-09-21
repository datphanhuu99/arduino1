#define sbi(PORT,bit) {PORT |=(1<<bit);}
#define cbi(PORT,bit) {PORT &=~(1<<bit);}
#define tbi(PORT,bit) {PORT ^= (1<<bit);}
 void setup()
{
  DDRB = 0b00100001; // PB0, PB5 - OUTPUT 
  //sbi(DDRB,0);
  //sbi(DDRB,5);
  //cbi(DDRB,2);…………… [Don’t need]}
}
 void loop()
{
  PORTB = 0b00100000; 
}

