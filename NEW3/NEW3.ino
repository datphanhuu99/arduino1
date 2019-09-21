#define MISO 4
#define yellow 2
#define cbi(port, bits)      (port) &= ~(1 << (bits))
#define sbi(port, bits)     (port) |=  (1 << (bits))

volatile uint8_t Data;
void setup()
{
  SPCR = 0;                   // reset SPCR = 0
  DDRB |= (1<<MISO);          // MISO -  OUTPUT , SCK,MOSI,SS - INPUT
  SPCR |= (1<<SPE)|(1<<SPIE); // enable spi , spi_interrupt
  pinMode(yellow ,OUTPUT);    // Led output at pin2

}
 void SPI_Response(uint8_t cData)
{
  SPDR = cData;                   //Start transmission
  while(bit_is_clear(SPSR,SPIF)); //Wait for transmission complete
}

void loop()
{
}

ISR(SPI_STC_vect)   // Vector interrupt spi
{
  Data = SPDR;      // volatile Data = data receive

  if(Data == 1) 
  {
  digitalWrite(yellow ,HIGH);   // i turnOn led if i receive data = 5
  SPI_Response(2);              // and response to master a value = 7
  delay(10);
  }

  else if(Data == 3)
  {
  digitalWrite(yellow,LOW);     // i turnOFF led if i receive data = 6
  SPI_Response(4);              //and response to master a value = 8
  delay(10);}}
