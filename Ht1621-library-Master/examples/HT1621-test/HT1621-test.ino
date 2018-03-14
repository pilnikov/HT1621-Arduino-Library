/**
 * \file HT1621-test.ino
 * \brief Simple test sketch for the HT1621 class.
 * \author Enrico Formenti
 * \date 4 february 2015
 * \version 1.0
 * \copyright BSD license, check the License page on the blog for more information. All this text must be
 *  included in any redistribution.
 *  <br><br>
 *  See https://macduino.blogspot.ru/2015/02/HT1621.html for more details. 
 */

#include "HT1621.h"

// refere to Macduino website for pin connections and their meaning
HT1621 ht(2,3,4); // ss, rw, data

void setup() {

  register uint8_t i;
  
  ht.begin();
  
  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);

  // clear memory
  for(i=0; i<16; i++)
    ht.write(i,0);

  // write all zeroes
  for(i=0; i<16; i++)  
    ht.write(i, 0xBE);
}

void loop() {}