void bat (uint8_t);
void digit (uint8_t, uint8_t);
void mon_day (uint8_t, uint8_t);
void ala (uint8_t);
void inline dow_sel(uint8_t);

//буфер экрана
uint8_t buf[32];

//массив простых элементов
byte sim_obj[29][2] =
{
  {24, 0x4}, // YEAR
  {24, 0x2}, // TIME
  {24, 0x1}, // SUN
  {23, 0x1}, // MON
  {23, 0x2}, // TUES
  {23, 0x4}, // WED
  {23, 0x8}, // THUR
  {22, 0x8}, // FRI
  {22, 0x4}, // SAT
  {24, 0x8}, // MONTH-DAY
  {27, 0x8}, // SLASH
  { 4, 0x8}, // COLON
  { 2, 0x8}, // DP
  {30, 0x1}, // PLAY
  {30, 0x2}, // PAUSE
  {30, 0x4}, // REPEAT
  {30, 0x8}, // REPEAT ONCE
  {31, 0x8}, // RND
  { 6, 0x8}, // AL1
  { 0, 0x8}, // AL2
  { 0, 0x4}, // AL3
  { 0, 0x2}, // AL4
  { 0, 0x1}  // MHZ
};

//массив батарейка
static const uint8_t batt[6] = {0x02, 0x82, 0x92, 0xD2, 0xF2, 0xF3};

//массив больших цифр
static const uint8_t dig1[10] = {0xF5, 0x60, 0xB6, 0xF2, 0x63, 0xD3, 0xD7, 0x70, 0xF7, 0xF3};

//массив маленьких цифр
static const uint8_t dig2[10] = {0xFA, 0x60, 0xD6, 0xF4, 0x6C, 0xBC, 0xBE, 0xE0, 0xFE, 0xFC};


