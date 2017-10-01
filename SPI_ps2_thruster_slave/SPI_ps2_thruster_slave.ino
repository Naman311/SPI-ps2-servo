// slave
#include <Servo.h>//Using servo library to control ESC
Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;
#include <SPI.h>
#include "SPI_anything.h"
unsigned int a;

void setup ()
  {
  Serial.begin (9600);   // debugging

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
   // end of setup
/*Serial.println("100%");
esc1.write(180);
esc2.write(180);
esc3.write(180);
esc4.write(180);
delay(1000);
Serial.println("0%");
esc1.write(50);
esc2.write(50);
esc3.write(50);
esc4.write(50);
delay(1000);

Serial.println("Intialized!");
*/
esc1.attach(7); //Specify the esc signal pin,Here as D8
//esc1.writeMicroseconds(1000); //initialize the signal to 1000

esc2.attach(6); //Specify the esc signal pin,Here as D8
//esc2.writeMicroseconds(1000); //initialize the signal to 1000

esc3.attach(5); //Specify the esc signal pin,Here as D8
//esc3.writeMicroseconds(1000); //initialize the signal to 1000

esc4.attach(4); //Specify the esc signal pin,Here as D8
//esc4.writeMicroseconds(1000); //initialize the signal to 1000
  }
void loop () 
  {   
  SPI_readAnything (a);
  Serial.println (a);
  switch (a){
    case 2048:                  // first 8 seperate
      esc1.writeMicroseconds(1150);
      break;
    case 18432:
      esc1.writeMicroseconds(1200);
      break;
    case 1024:
      esc2.writeMicroseconds(1350);
      break;
    case 17408:            
      esc2.writeMicroseconds(1400);
      break;
    case 512:
      esc3.writeMicroseconds(1240);
      break;
    case 16896:
      esc3.writeMicroseconds(1300);
      break;
    case 256:            
      esc4.writeMicroseconds(1260);
      break;
    case 16640:
      esc4.writeMicroseconds(1300);
      break;
    case 4096:            //last 4 combination
      esc1.writeMicroseconds(1140);
      esc2.writeMicroseconds(1320);
      break;
    case 20480:
      esc1.writeMicroseconds(1200);
      esc2.writeMicroseconds(1400);
      break;
    case 8192:
      esc3.writeMicroseconds(1240);
      esc4.writeMicroseconds(1260);
      break;
    case 24576:
      esc3.writeMicroseconds(1300);
      esc4.writeMicroseconds(1300);
      break;    
    case 0:
      esc1.writeMicroseconds(0);
      esc2.writeMicroseconds(0);
      esc3.writeMicroseconds(0);
      esc4.writeMicroseconds(0);
      break;
  }
  delay(20);
  }  // end of loop
