// master
#include <Psx.h>
#include <SPI.h>
#include "SPI_anything.h"
#define dataPin 8   //brown
#define cmndPin 6   //orange
#define attPin 3 //yellow
#define clockPin 5 //blue

// create a structure to store the different data values:
Psx Psx;    

void setup ()
  {
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
  SPI.begin ();
  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);

  }  // end of setup

void loop () 
  { 
    
  int a = Psx.read(); 
  delay(10);
  digitalWrite(SS, LOW);    // SS is pin 10
  SPI_writeAnything (a);
  //delay(10);
  digitalWrite(SS, HIGH);
  delay(10);
  }  // end of loop
