#define DDR_SPI DDRB
#define PORT_SPI PORTB
#define MOSI 3
#define SCK 5
#define SS 2
#define red 2
#define cbi(port, bits)      (port) &= ~(1 << (bits))
#define sbi(port, bits)     (port) |=  (1 << (bits))

volatile uint8_t Data1;
volatile uint8_t Data2;
void setup()
{
  Serial.begin(9600);   //debug by UART
  SPCR = 0;             // Reset SPCR = 0

  DDR_SPI |= (1<<MOSI)|(1<<SCK)|(1<<SS);// MOSI,SCK,SS - OUTPUT , MISO - INPUT
  SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0); // Enable spi , Set master , div/16

  pinMode(red,OUTPUT);   // led output at pin 2
  pinMode(6,INPUT_PULLUP);    // internal res input at pin6
  pinMode(7,INPUT_PULLUP);    // internal res input at pin7

  sbi(PORT_SPI,SS);   // disable slave
}

uint8_t SPI_MasterTransmit(uint8_t cData)
{
  SPDR = cData;                   // Start transmission 
  delay(50);
  while(bit_is_clear(SPSR,SPIF)); //Wait for transmission complete
  return SPDR;
}

void loop()
{
   if(bit_is_clear(PIND,6))       // if i push button at pin 6
  {
     while(bit_is_clear(PIND,6));  // if i still push button at pin 6
     cbi(PORTB,SS);               // enable slave

     Data1 = SPI_MasterTransmit(1); // send value 1 to slave
     Serial.print(Data1);           // debug
     delay(50);

     if(Data1 == 2)                 //if slave response value = 2
     digitalWrite(red,LOW);         //turnOFF led at pin 2

     sbi(PORT_SPI,SS);              // disable slave
  }


   else if(bit_is_clear(PIND,7))  // if i push button at pin 7
  {
    while(bit_is_clear(PIND,7)); // if i still push button at pin 7
    cbi(PORT_SPI,SS);            // disable slave

    Data2 = SPI_MasterTransmit(3);  // send value 3 to slave
    Serial.print(Data2);            // debug
    delay(50);

    if(Data2==4)                    //if slave response value = 4
    digitalWrite(red,HIGH);         //turnON led at pin 2

    sbi(PORT_SPI,SS);               // disable slave
  }
}
