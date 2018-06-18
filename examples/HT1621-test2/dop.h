//массив больших цифр
/*byte dig[10][2] =
  {
  {0xF, 0x5},  //0
  {0x6, 0x0},  //1
  {0xB, 0x6},  //2
  {0xF, 0x2},  //3
  {0x6, 0x3},  //4
  {0xD, 0x3},  //5
  {0xD, 0x7},  //6
  {0x7, 0x0},  //7
  {0xF, 0x7},  //8
  {0xF, 0x3}   //9
  };
*/

void digit6 (byte num)
{
  ht.write(0x1C, 0x0);
  ht.write(0x1D, 0x0);
  switch (num) {
    case 0:
      ht.write(0x1C, 0xF);
      ht.write(0x1D, 0xA);
      break;
    case 1:
      ht.write(0x1C, 0x6);
      break;
    case 2:
      ht.write(0x1C, 0xD);
      ht.write(0x1D, 0x6);
      break;
    case 3:
      ht.write(0x1C, 0xF);
      ht.write(0x1D, 0x4);
      break;
    case 4:
      ht.write(0x1C, 0x6);
      ht.write(0x1D, 0xC);
      break;
    case 5:
      ht.write(0x1C, 0xB);
      ht.write(0x1D, 0xC);
      break;
    case 6:
      ht.write(0x1C, 0xB);
      ht.write(0x1D, 0xE);
      break;
    case 7:
      ht.write(0x1C, 0xE);
      break;
    case 8:
      ht.write(0x1C, 0xF);
      ht.write(0x1D, 0xE);
      break;
    case 9:
      ht.write(0x1C, 0xF);
      ht.write(0x1D, 0xC);
      break;
    case 10:
      ht.write(0x1D, 0x1);
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
void char0 (char num)
{
  switch (num) {

    case 'A':
      ht.write(0x16, 0x3);
      ht.write(0x15, 0xF);
      break;
    case 'a':
      ht.write(0x16, 0x2);
      break;
    case 'B':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0x8);
      break;
    case 'b':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0x9);
      break;
    case 'C':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0xD);
      break;
    case 'c':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0xF);
      break;
    case 'D':
      ht.write(0x16, 0x3);
      ht.write(0x15, 0xF);
      break;
    case 'd':
      ht.write(0x16, 0x2);
      break;
    case 'E':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0x8);
      break;
    case 'e':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0x9);
      break;
    case 'F':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0xD);
      break;
    case 'f':
      ht.write(0x16, 0x2);
      ht.write(0x15, 0xF);
      break;
    case 'G':
      ht.write(0x16, 0x3);
      ht.write(0x15, 0xF);
      break;
    default:
      ht.write(0x16, 0x2);
      break;
  }
}

