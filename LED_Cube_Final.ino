int ledPins[12]={2,3,4,5,6,7,8,9,A0,A1,A2,A3};
int dataPin = 12;
int clockPin = A5;
int latchPin = A4;
int yLevel = 1;
int readNum;
int randNum = random(1,5);

int timeDelay = 100;

void setup()
{
  Serial.begin(9600);
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  randNum = random(1,5);

  for (int i = 0; i < sizeof(ledPins)/sizeof(int); i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }

  clearAll();
  
}

void loop()
{
  if(Serial.available() > 0){
    readNum = Serial.read();
    if (Serial.read() == 10)
    {
    }
    randNum = random(1,5);
  }

  switch (readNum)
  {
    case 49:
      snake();
      break;
    case 50:
      sparkles();
      break;
    case 51:
      illusion();
      break;
    case 52:
      scripture();
      break;
    default:
      switch(randNum)
      {
        case 1:
          snake();
          break;
        case 2:
          sparkles();
          break;
        case 3:
          illusion();
          break;
        case 4:
          scripture();
          break;
      }
  }
}

void clearAll()
{
  for (int i = 0; i < sizeof(ledPins)/sizeof(int); i++)
  {
    digitalWrite(ledPins[i], HIGH);
  }
  
  blueOff(0);
}



void blueOff(int num)
{
  num = num + 15;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, num);
  digitalWrite(latchPin, HIGH);
}

void oneLed(int x, int y)
{
  clearAll();
  yLevel = y - 1;

  if (x <= 12 and x >= 9)
  {
    turnOnBlue(x);
  }
  else if (x >= 13)
  {
    blueOff(16 * exponent(2, yLevel));
    digitalWrite(ledPins[x-5], LOW);
  }
  else
  {
    blueOff(16 * exponent(2, yLevel));
    digitalWrite(ledPins[x-1], LOW);
  }
}

void turnOnBlue(int LED)
{
  switch(LED)
  {
    case 9:
      blueOff(16 * exponent(2, yLevel) - 1);
      break;
    case 10:
      blueOff(16 * exponent(2, yLevel) - 2);
      break;
    case 11:
      blueOff(16 * exponent(2, yLevel) - 4);
      break;
    case 12:
      blueOff(16 * exponent(2, yLevel) - 8);
      break;
    default:
      Serial.println("Error num OB");
  }
}

int exponent(int value, int power)
{
  int total = 1;
  for (int i = 1; i <= power; i++)
  {
    total *= value;
  }
  return total;
}

void sparkles()
{
    getDirect();
    int posx = random(1, 17);
    int posy = random(1, 5);
    oneLed(posx, posy);
    delay(timeDelay);
}
