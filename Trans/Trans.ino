#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() 
{
  pinMode(6,OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() 
{
  digitalWrite(6,1);
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
