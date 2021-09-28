byte upM[] = {
  B00000,
  B10101,
  B10101,
  B10101,
  B10101,
  B01011,
  B00000,
  B00000
};
byte upO[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000
};
byte upD[] = {
  B00000,
  B11110,
  B10001,
  B10001,
  B10001,
  B11110,
  B10000,
  B10000
};
byte upN[] = {
  B00000,
  B10001,
  B10001,
  B10001,
  B10011,
  B01101,
  B00000,
  B00000
};
byte upA[] = {
  B00000,
  B11110,
  B10001,
  B11110,
  B10000,
  B01110,
  B00000,
  B00000
};
byte bigUpR[] = {
  B00000,
  B10001,
  B01001,
  B00101,
  B01111,
  B10001,
  B10001,
  B01111
};

byte upB[] = {
  B00000,
  B01111,
  B10001,
  B10001,
  B10001,
  B01111,
  B00001,
  B00001
};

byte bigUpB[] = {
  B00000,
  B01111,
  B10001,
  B10001,
  B01111,
  B10001,
  B10001,
  B01111
};

byte bigUpS[] = {
  B00000,
  B01110,
  B10001,
  B10000,
  B01110,
  B00001,
  B10001,
  B01110
};

byte upP[] = {
  B00000,
  B00001,
  B00001,
  B01111,
  B10001,
  B01111,
  B00000,
  B00000
};

byte upR[] = {
  B00000,
  B00010,
  B00010,
  B00010,
  B00010,
  B00110,
  B11010,
  B00000
};

byte upK[] = {
  B00000,
  B01001,
  B00101,
  B00011,
  B00101,
  B01001,
  B00001,
  B00001
};

byte upL[] = {
  B00000,
  B01110,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00110
};

byte upE[] = {
  B00000,
  B01110,
  B00001,
  B11111,
  B10001,
  B01110,
  B00000,
  B00000
};

byte upS[] = {
  B00000,
  B01111,
  B10000,
  B01110,
  B00001,
  B11110,
  B00000,
  B00000
};

byte bigUpI[] = {
  B00000,
  B01110,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B01110
};

byte upU[] = {
  B00000,
  B10110,
  B11001,
  B10001,
  B10001,
  B10001,
  B00000,
  B00000
};

byte upI[] = {
  B00000,
  B01110,
  B00100,
  B00100,
  B00100,
  B01100,
  B00000,
  B00100
};

byte upC[] = {
  B00000,
  B11110,
  B00001,
  B00001,
  B00001,
  B11110,
  B00000,
  B00000
};

byte upT[] = {
  B00000,
  B11000,
  B00100,
  B00100,
  B00100,
  B11111,
  B00100,
  B00100
};

byte bigUpK[] = {
  B00000,
  B10001,
  B01001,
  B00101,
  B00011,
  B00101,
  B01001,
  B10001
};

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lButton = 8;
int mButton = 7;
int rButton = 6;
int choice = 0;

void setup() {
  lcd.begin(16, 2);
  writeText(choice);
  Serial.begin(9600);
  pinMode(lButton, INPUT_PULLUP);
  pinMode(mButton, INPUT_PULLUP);
  pinMode(rButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(lButton)==LOW){
    delay(200);
    choice--;
    writeText(choice);
  }
  else if(digitalRead(rButton)==LOW){
    delay(200);
    choice++;
    writeText(choice);
  }
    
  if (choice > 4)
  {
    choice = 0;
    writeText(choice);
  }
  else if (choice < 0)
  {
    choice = 4;
    writeText(choice);
  }
  else
  {
    choice = choice;
  }
  
  if (digitalRead(mButton)==LOW){
    switch(choice){
      case 1:
        Serial.write("1");
        break;
      case 2:
        Serial.write("2");
        break;
      case 3:
        Serial.write("3");
        break;
      case 4:
        Serial.write("4");
        break;
      default:
        Serial.write("0");
        break;
    }
    delay(200);
  }
}

void writeText(int choice)
{
  lcd.clear();
  
  switch(choice){
    case 1:
      writeSnake();
      break;
    case 2:
      writeSparkles();
      break;
    case 3:
      writeIllusion();
      break;
    case 4:
      writeKindness();
      break;
    default:
      writeRandom();
      break;
  }
  
  lcd.setCursor(0,0);
  lcd.print("<");
  lcd.setCursor(7, 0);
  lcd.print("[]");
  lcd.setCursor(15, 0);
  lcd.print(">");
}

void writeRandom()
{
  lcd.createChar(1, upM);
  lcd.createChar(2, upO);
  lcd.createChar(3, upD);
  lcd.createChar(4, upN);
  lcd.createChar(5, upA);
  lcd.createChar(6, bigUpR);
  
  lcd.setCursor(5, 1);
  
  for(int i = 1; i < 7; i++)
  {
    lcd.write(i);
  }
}

void writeSnake()
{
  lcd.createChar(1, upE);
  lcd.createChar(2, upK);
  lcd.createChar(3, upA);
  lcd.createChar(4, upN);
  lcd.createChar(5, bigUpS);
  
  lcd.setCursor(6, 1);
  
  for(int i = 1; i < 6; i++)
  {
    lcd.write(i);
  }
}

void writeSparkles()
{
  lcd.createChar(1, upS);
  lcd.createChar(2, upE);
  lcd.createChar(3, upL);
  lcd.createChar(4, upK);
  lcd.createChar(5, upR);
  lcd.createChar(6, upA);
  lcd.createChar(7, upP);
  lcd.createChar(8, bigUpS);
  
  lcd.setCursor(4, 1);
  
  for(int i = 1; i < 9; i++)
  {
    lcd.write(i);
  }
}

void writeIllusion()
{
  lcd.createChar(1, upN);
  lcd.createChar(2, upO);
  lcd.createChar(3, upI);
  lcd.createChar(4, upS);
  lcd.createChar(5, upU);
  lcd.createChar(6, upL);
  lcd.createChar(7, upL);
  lcd.createChar(8, bigUpI);
  
  lcd.setCursor(4, 1);
  
  for(int i = 1; i < 9; i++)
  {
    lcd.write(i);
  }
}

void writeKindness()
{
  lcd.createChar(1, upS);
  lcd.createChar(2, upS);
  lcd.createChar(3, upE);
  lcd.createChar(4, upN);
  lcd.createChar(5, upD);
  lcd.createChar(6, upN);
  lcd.createChar(7, upI);
  lcd.createChar(8, bigUpK);
  
  lcd.setCursor(4, 1);
  
  for(int i = 1; i < 9; i++)
  {
    lcd.write(i);
  }
}
