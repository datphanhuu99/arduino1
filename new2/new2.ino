#define sbi(PORT,bit) {PORT |=(1<<bit);}
#define cbi(PORT,bit) {PORT &=~(1<<bit);}
#define tbi(PORT,bit) {PORT ^= (1<<bit);}
#include <avr/sfr_defs.h>
#include <string.h>
char k[]="123";
char n[]="X";
void setup()
{
   UBRR0H = 0;
   UBRR0L = 103; // Baud = 103
   UCSR0B |=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
   //  TxEnable , RxEnable , Rx-Interrupt Enable
   UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
   // Select Asynchronous , 8 bits data
   sei();
}

void _Send(uint8_t data)
{
  while(bit_is_clear(UCSR0A,UDRE0));
  UDR0 = data; // send
}
/*void receive(char n[])
{
  int s=0;
  while (UDR0='\0');
  {
    n[s]=UDR0;
    _send(n[s]);
    
 }
}*/
void send_string(char k[])
{
   int s=0;
  
while(k[s]|='\0')
 {
  _Send(k[s]);
  s++;
 }
}
void loop()
{ 
  delay(1000);
 send_string(k);
 
  }
ISR(USART_RX_vect)
{
   if(UDR0 == 'X')
   {  
  send_string(n);
   }
   if(UDR0 == "xxx")
   {
    PORTD=0x01;
   }
}

/*
void setup()
{
  pinMode(9, OUTPUT);   
}

void loop()
{
  analogWrite(9, 127); // duty 50%
}*/

