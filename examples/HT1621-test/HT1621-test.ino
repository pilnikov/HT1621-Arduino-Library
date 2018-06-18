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

//массив констант для отображения цифр, минуса и пробела:
byte sim_obj[29][2] =
{
  { 0xC, 0x40}, // YEAR
  { 0xC, 0x20}, // TIME
  { 0xC, 0x10}, // SUN
  { 0xB, 0x01}, // MON
  { 0xB, 0x02}, // TUES
  { 0xB, 0x04}, // WED
  { 0xB, 0x08}, // THUR
  { 0xB, 0x80}, // FRI
  { 0xB, 0x40}, // SAT
  { 0xC, 0x80}, // MONTH-DAY
  { 0xD, 0x08}, // SLASH
  { 0x2, 0x80}, // COLON
  { 0x1, 0x80}, // DP
  { 0xF, 0x10}, // PLAY
  { 0xF, 0x20}, // PAUSE
  { 0xF, 0x40}, // REPEAT
  { 0xF, 0x80}, // REPEAT ONCE
  { 0xF, 0x08}, // RND
  { 0x3, 0x80}, // AL1
  { 0x0, 0x80}, // AL2
  { 0x0, 0x40}, // AL3
  { 0x0, 0x20}, // AL4
  { 0x0, 0x10}  // MHZ
};

void bat (byte num)
{
  ht.write(0xB, 0x00);
  ht.write(0xA, 0x00);
  switch (num) {
    case 1:
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x08);
      break;
    case 2:
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x09);
      break;
    case 3:
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x0D);
      break;
    case 4:
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x0F);
      break;
    case 5:
      ht.write(0xB, 0x30);
      ht.write(0xA, 0x0F);
      break;
    default:
      ht.write(0xB, 0x20);
      break;
  }
}
/////////////////////////////
//  /* 0 *  0 */
//  /* 1 *  1 */
//  /* 2 *  2 */
//  /* 3 *  3 */
//  /* 4 *  4 */
//  /* 5 *  5 */
//  /* 6 *  6 */
//  /* 7 *  7 */
//  /* 8 *  8 */
//  /* 9 *  9 */
//  /* a * 10 */
//  /* b * 11 */
//  /* C * 12 */
//  /* d * 13 */
//  /* E * 14 */
//  /* F * 15 */
//  /* H * 16 */
//  /* L * 17 */
//  /* P * 18 */
//  /* t * 19 */
//  /* У * 20 */
//  /* Г * 21 */
//  /* П * 22 */
//  /* - * 23 */
//  /*   * 24 */
///////////////////////////////////

void digit0 (byte num)
{
  ht.write(0x0, 0x00);
  ht.write(0x1, 0x00);
  switch (num) {
    case 0:
      ht.write(0x0, 0x0F);
      ht.write(0x1, 0x50);
      break;
    case 1:
      ht.write(0x0, 0x06);
      break;
    case 2:
      ht.write(0x0, 0x0B);
      ht.write(0x1, 0x60);
      break;
    case 3:
      ht.write(0x0, 0x0F);
      ht.write(0x1, 0x20);
      break;
    case 4:
      ht.write(0x0, 0x06);
      ht.write(0x1, 0x30);
      break;
    case 5:
      ht.write(0x0, 0x0D);
      ht.write(0x1, 0x30);
      break;
    case 6:
      ht.write(0x0, 0x0D);
      ht.write(0x1, 0x70);
      break;
    case 7:
      ht.write(0x0, 0x07);
      break;
    case 8:
      ht.write(0x0, 0x0F);
      ht.write(0x1, 0x70);
      break;
    case 9:
      ht.write(0x0, 0x0F);
      ht.write(0x1, 0x30);
      break;
  }
}

void digit1 (byte num)
{
  ht.write(0x1, 0x00);
  ht.write(0x2, 0x00);
  switch (num) {
    case 0:
      ht.write(0x1, 0x0F);
      ht.write(0x2, 0x50);
      break;
    case 1:
      ht.write(0x1, 0x06);
      break;
    case 2:
      ht.write(0x1, 0x0B);
      ht.write(0x2, 0x60);
      break;
    case 3:
      ht.write(0x1, 0x0F);
      ht.write(0x2, 0x20);
      break;
    case 4:
      ht.write(0x1, 0x06);
      ht.write(0x2, 0x30);
      break;
    case 5:
      ht.write(0x1, 0x0D);
      ht.write(0x2, 0x30);
      break;
    case 6:
      ht.write(0x1, 0x0D);
      ht.write(0x2, 0x70);
      break;
    case 7:
      ht.write(0x1, 0x07);
      break;
    case 8:
      ht.write(0x1, 0x0F);
      ht.write(0x2, 0x70);
      break;
    case 9:
      ht.write(0x1, 0x0F);
      ht.write(0x2, 0x30);
      break;
  }
}
void digit2 (byte num)
{
  ht.write(0x2, 0x00);
  ht.write(0x3, 0x00);
  switch (num) {
    case 0:
      ht.write(0x2, 0x0F);
      ht.write(0x3, 0x50);
      break;
    case 1:
      ht.write(0x2, 0x06);
      break;
    case 2:
      ht.write(0x2, 0x0B);
      ht.write(0x3, 0x60);
      break;
    case 3:
      ht.write(0x2, 0x0F);
      ht.write(0x3, 0x20);
      break;
    case 4:
      ht.write(0x2, 0x06);
      ht.write(0x3, 0x30);
      break;
    case 5:
      ht.write(0x2, 0x0D);
      ht.write(0x3, 0x30);
      break;
    case 6:
      ht.write(0x2, 0x0D);
      ht.write(0x3, 0x70);
      break;
    case 7:
      ht.write(0x2, 0x07);
      break;
    case 8:
      ht.write(0x2, 0x0F);
      ht.write(0x3, 0x70);
      break;
    case 9:
      ht.write(0x2, 0x0F);
      ht.write(0x3, 0x30);
      break;
  }
}
void digit3 (byte num)
{
  ht.write(0x3, 0x00);
  ht.write(0xF, 0x00);
  switch (num) {
    case 0:
      ht.write(0x3, 0x0F);
      ht.write(0xF, 0x05);
      break;
    case 1:
      ht.write(0x3, 0x06);
      break;
    case 2:
      ht.write(0x3, 0x0B);
      ht.write(0xF, 0x06);
      break;
    case 3:
      ht.write(0x3, 0x0F);
      ht.write(0xF, 0x02);
      break;
    case 4:
      ht.write(0x3, 0x06);
      ht.write(0xF, 0x03);
      break;
    case 5:
      ht.write(0x3, 0x0D);
      ht.write(0xF, 0x03);
      break;
    case 6:
      ht.write(0x3, 0x0D);
      ht.write(0xF, 0x07);
      break;
    case 7:
      ht.write(0x3, 0x07);
      break;
    case 8:
      ht.write(0x3, 0x0F);
      ht.write(0xF, 0x07);
      break;
    case 9:
      ht.write(0x3, 0x0F);
      ht.write(0xF, 0x03);
      break;
  }
}
void digit4 (byte num)
{
  ht.write(0xC, 0x00);
  ht.write(0xD, 0x00);
  switch (num) {
    case 0:
      ht.write(0xC, 0x0F);
      ht.write(0xD, 0xA0);
      break;
    case 1:
      ht.write(0xC, 0x06);
      break;
    case 2:
      ht.write(0xC, 0x0D);
      ht.write(0xD, 0x60);
      break;
    case 3:
      ht.write(0xC, 0x0F);
      ht.write(0xD, 0x40);
      break;
    case 4:
      ht.write(0xC, 0x06);
      ht.write(0xD, 0xC0);
      break;
    case 5:
      ht.write(0xC, 0x0B);
      ht.write(0xD, 0xC0);
      break;
    case 6:
      ht.write(0xC, 0x0B);
      ht.write(0xD, 0xE0);
      break;
    case 7:
      ht.write(0xC, 0x0E);
      break;
    case 8:
      ht.write(0xC, 0x0F);
      ht.write(0xD, 0xE0);
      break;
    case 9:
      ht.write(0xC, 0x0F);
      ht.write(0xD, 0xC0);
      break;
  }
}

void digit5 (byte num)
{
  ht.write(0xD, 0x00);
  switch (num) {
    case 1:
      ht.write(0xD, 0x11);
      break;
    case 2:
      ht.write(0xD, 0x16);
      break;
    case 3:
      ht.write(0xD, 0x13);
      break;
  }
}

void digit6 (byte num)
{
  ht.write(0xE, 0x00);
  switch (num) {
    case 0:
      ht.write(0xE, 0xFA);
      break;
    case 1:
      ht.write(0xE, 0x60);
      break;
    case 2:
      ht.write(0xE, 0xD6);
      break;
    case 3:
      ht.write(0xE, 0xF4);
      break;
    case 4:
      ht.write(0xE, 0x6C);
      break;
    case 5:
      ht.write(0xE, 0xBC);
      break;
    case 6:
      ht.write(0xE, 0xBE);
      break;
    case 7:
      ht.write(0xE, 0xE0);
      break;
    case 8:
      ht.write(0xE, 0xFE);
      break;
    case 9:
      ht.write(0xE, 0xFC);
      break;
    case 10:
      ht.write(0xE, 0x01);
      break;
  }
}

void char0 (char num)
{
  switch (num) {

    case 'A':
      ht.write(0xB, 0x30);
      ht.write(0xA, 0x0F);
      break;
    case 'a':
      ht.write(0xB, 0x20);
      break;
    case 'B':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x08);
      break;
    case 'b':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x09);
      break;
    case 'C':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x0D);
      break;
    case 'c':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x0F);
      break;
    case 'D':
      ht.write(0xB, 0x30);
      ht.write(0xA, 0x0F);
      break;
    case 'd':
      ht.write(0xB, 0x20);
      break;
    case 'E':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x08);
      break;
    case 'e':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x09);
      break;
    case 'F':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x0D);
      break;
    case 'f':
      ht.write(0xB, 0x20);
      ht.write(0xA, 0x0F);
      break;
    case 'G':
      ht.write(0xB, 0x30);
      ht.write(0xA, 0x0F);
      break;
    default:
      ht.write(0xB, 0x20);
      break;
  }
}

void sim_obj_d (byte num)
{
  ht.write(sim_obj[num][0], sim_obj[num][1]);
}


void setup() {

  Serial.begin (9600);
  Serial.println ("Hello");

  ht.begin();

  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);

  // clear memory
  for (i = 0; i < 0x10; i++) ht.write(i, 0x0);

  a = 0b1;
  b = 0;
  c = 0;
}

void loop()
{
  switch (c)
  {
    case 0:
      for (b = 0; b < 0x10; b++)
      {
        for (j = 0; j < 8; j++)
        {
          ht.write(b, a);
          Serial.print (b, BIN);
          Serial.print (" : ");
          Serial.println (a, BIN);
          delay (100);
          a <<= 1;
          a |= 0b1;
        }
        a = 0b1;
        //if (b == 3 ) b = 9;
        //b <<= 1;
        //b |= 1;
      }
      //b = 0x1;
      delay (2000);
      for (i = 0; i < 0x80; i++) ht.write(i, 0x00);
      c = 10;
      break;

    case 1:
      for (b = 0; b < 23; b++)
      {
        sim_obj_d (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 2:
      for (b = 0; b < 6; b++)
      {
        bat (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 3:
      for (b = 0; b < 10; b++)
      {
        digit0 (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 4:
      for (b = 0; b < 10; b++)
      {
        digit1 (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 5:
      for (b = 0; b < 10; b++)
      {
        digit2 (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 6:
      for (b = 0; b < 10; b++)
      {
        digit3 (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 7:
      for (b = 0; b < 10; b++)
      {
        digit4 (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 8:
      for (b = 1; b < 4; b++)
      {
        digit5 (b);
        delay (200);
      }
      b = 0;
      c++;
      break;

    case 9:
      for (b = 0; b < 11; b++)
      {
        digit6 (b);
        delay (200);
        ht.write(0xE, 0x00);
      }
      b = 0;
      c++;
      break;
  }
  if (c > 9)
  {
    c = 0;
    delay (2000);
    for (i = 0; i < 16; i++) ht.write(i, 0x00);
  }
}


/*создаём новую функцию для отображения по шаблону "позиция-цифра":
  void writeDigit(byte pos, byte val)
  {
  for (byte i = 0; i < 3; i++) ht.write(3 * pos + 5 + i, arr[val][i]);

  }
*/
