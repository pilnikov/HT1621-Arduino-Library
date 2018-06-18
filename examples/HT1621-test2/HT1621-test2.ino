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
#include "data.h"


// refere to Macduino website for pin connections and their meaning
HT1621 ht(16, 14, 13); // ss, rw, data
//HT1621 ht(2, 3, 4); // ss, rw, data

byte i, j, a, b, c;

void setup() {

  Serial.begin (9600);
  Serial.println ("Hello");

  ht.begin();

  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);

  // clear memory
  for (i = 0; i < 32; i++) buf[i] = 0x0;
  ht.clear_all();

  a = 0b1;
  b = 0;
  c = 0;
}

void loop()
{
  switch (c)
  {
    case 0:
      for (b = 0; b < 32; b++)
      {
        for (j = 0; j < 4; j++)
        {
          ht.write(b, a);
          delay (100);
          a <<= 1;
          a |= 0b1;
        }
        a = 0b1;
        if (b == 7 ) b = 20;
      }
      delay (200);
      for (i = 0; i < 32; i++) buf[i] = 0x0;
      ht.clear_all();
      c ++;
      break;

    case 1:
      for (b = 0; b < 23; b++)
      {
        buf[sim_obj[b][0]] |= sim_obj[b][1];
        ht.write(sim_obj[b][0], buf[sim_obj[b][0]]);
        delay (200);
      }
      b = 0;
      c ++;
      break;

    case 2:
      for (b = 0; b < 6; b++)
      {
        bat (b);
        ht.write(21, buf, 2);
        delay (200);
      }
      c++;
      break;

    case 3:
      for (b = 0; b < 10; b++)
      {
        digit (1, b);
        ht.write(1, buf, 2);
        delay (200);
      }
      c++;
      break;

    case 4:
      for (b = 0; b < 10; b++)
      {
        digit (3, b);
        ht.write(3, buf, 2);
        delay (200);
      }
      c++;
      break;

    case 5:
      for (b = 0; b < 10; b++)
      {
        digit (5, b);
        ht.write(5, buf, 2);
        delay (200);
      }
      c ++;
      break;

    case 6:
      for (b = 0; b < 10; b++)
      {
        digit (7, b);
        ht.write(7, buf[7]);
        ht.write(31, buf[31]);
        delay (200);
      }
      c++;
      break;

    case 7:
      for (b = 0; b < 40; b++)
      {
        mon_day (1, b);
        ht.write(25, buf, 3);
        delay (200);
      }
      c ++;
      break;

    case 8:
      b = 0;
      c++;
      break;

    case 9:
      for (b = 0; b < 20; b++)
      {
        mon_day (b, 31);
        ht.write(28, buf, 2);
        delay (200);
      }
      c++;
      break;

    case 10:
      for (b = 1; b < 8; b++)
      {
        dow_sel (b);
        ht.write(22, buf, 3);
        delay (200);
      }
      c ++;
      break;

  }

  if (c > 10)
  {
    c = 0;
    delay (2000);
    for (i = 0; i < 32; i++) buf[i] = 0x0;
    ht.clear_all();
  }
}


/*создаём новую функцию для отображения по шаблону "позиция-цифра":
  void writeDigit(byte pos, byte val)
  {
  for (byte i = 0; i < 3; i++) ht.write(3 * pos + 5 + i, arr[val][i]);

  }
*/
