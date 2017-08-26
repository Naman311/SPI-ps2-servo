// slave

#include <SPI.h>
#include "SPI_anything.h"

void setup ()
  {
  Serial.begin (115200);   // debugging

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  }  // end of setup

void loop () 
  { 
  int a;
  SPI_readAnything (a);
  Serial.println (a);
  delay(20);
  }  // end of loop
