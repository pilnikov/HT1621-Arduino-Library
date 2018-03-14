//---------------------------------------------------------------------------HT1621

void bat (uint8_t num) //Батарейка
{
  buf[22] &= 0xC;
  buf[21] = 0x0;

  buf[21] |= (batt[num] & 0xF0) >> 4;
  buf[22] |= batt[num] & 0x0F;
}

void digit (uint8_t place, uint8_t num) // Большие цифры
{
  uint8_t place2 = place + 1;
  if (place == 7) place2 = 31;

  buf[place] = 0x0;
  buf[place2] &= 0x8;

  buf[place] |= (dig1[num] & 0xF0) >> 4;
  buf[place2] |= dig1[num] & 0x0F;
}

void mon_day (uint8_t mon, uint8_t _day) //Маленькие цифры (Месяц, число, год)
{
  buf[25] = 0x0;
  buf[26] = 0x0;
  buf[27] &= 0x8;
  buf[28] = 0x0;
  buf[29] = 0x0;

  buf[25] |= (dig2[_day % 10] & 0xF0) >> 4;
  buf[26] |= (dig2[_day % 10] & 0x0F);

  if (_day > 9) buf[26] |= 0x1;
  buf[27] |= int(_day / 10);
  if (int(_day / 10) == 2) buf[27] |= 0x6;

  buf[28] |= (dig2[mon % 10] & 0xF0) >> 4;
  buf[29] |= (dig2[mon % 10] & 0x0F) + (mon / 10);
}

void ala (uint8_t num) //Будильник
{
  buf[0] &= 0x1;
  buf[6] &= 0x7;

  switch (num)
  {
    case 0:
      buf[6] |= 0x8;
      break;
    case 1:
      buf[0] |= 0x8;
      break;
    case 2:
      buf[0] |= 0x4;
      break;
    case 3:
      buf[0] |= 0x2;
      break;
  }
}

//-------------------------------------------------------------- Выбор дня недели
void inline dow_sel(uint8_t num)
{
  buf[22] &= 0x3;
  buf[23] = 0x0;
  buf[24] &= 0xE;
  // Выбор Дня недели

  switch (num)
  {
    case 2:      //ПН
      buf[23] |= 0x1;
      break;
    case 3:      //Bt
      buf[23] |= 0x2;
      break;
    case 4:      //CP
      buf[23] |= 0x4;
      break;
    case 5:      //Чt
      buf[23] |= 0x8;
      break;
    case 6:      //Пt
      buf[22] |= 0x8;
      break;
    case 7:      //СБ
      buf[22] |= 0x4;
      break;
    default:      //BС
      buf[24] |= 0x1;
      break;
  }
  //  return dow;
}
