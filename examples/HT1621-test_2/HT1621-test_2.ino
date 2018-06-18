/**
  \file HT1621-test.ino
  \brief Simple test sketch for the HT1621 class.
  \author Enrico Formenti
  \date 4 february 2015
  \version 1.0
  \copyright BSD license, check the License page on the blog for more information. All this text must be
   included in any redistribution.
   <br><br>
   See https://macduino.blogspot.ru/2015/02/HT1621.html for more details.
*/

#include <HT1621.h>

// refere to Macduino website for pin connections and their meaning
HT1621 ht(2, 3, 4); // ss, rw, data

byte i, j, a, b, c;

void setup() {

  ht.begin();

  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
  for (i = 0; i < 16; i++) ht.write(i, 0x0);

  Serial.begin (9600);


  Serial.println ("Hello");


//  ht.write(0b0, 0b0);
//  ht.write(0xF, 0b0);
//  ht.write(0x0, 0xF);

    ht.writeBits(0b101, 3);
    ht.writeBits(0xF, 10);

  ht.write(0x7F, 0xF);

}

void loop() {}

