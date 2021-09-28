int posx = random(1, 17);
int posy = random(1, 5);
int direct = random(1, 5);
int addX[] = {posx, 0, 0};
int addY[] = {posy, posy, posy};
int snakeLevel = 1;
  
void snake()
{
  
  for (int x = 0; x < random(1, 6); x++)
  {

    addX[2] = addX[1];
    addX[1] = addX[0];
    addX[0] = addDirect(addX[0]);

    addY[2] = addY[1];
    addY[1] = addY[0];
    addY[0] = snakeLevel;

    displaySnake(addY, addX);
  }
  getDirect();
}

void displaySnake(int (& addY) [3], int (& addX) [3])
{
  for (int i = 0; i < 100; i++)
  {
    oneLed(addX[0], addY[0]);
    //delayMicroseconds(timeDelay);
    delay(1);
    oneLed(addX[1], addY[1]);
    //delayMicroseconds(timeDelay);
    delay(1);
    oneLed(addX[2], addY[2]);
    //delayMicroseconds(timeDelay);
    delay(1);
  }
}

int getDirect()
{
  if (direct == 1 or direct == 3)
  {
    while(direct == 3 or direct == 1)
    {
      direct = random(1, 7);
    }
    return direct;
  }
  else if (direct == 2 or direct == 4)
  {
    while(direct == 4 or direct == 2)
    {
      direct = random(1, 7);
    }
    return direct;
  }
  else if (direct == 5 or direct == 6)
  {
    while(direct == 5 or direct == 6)
    {
      direct = random(1, 7);
    }
    return direct;
  }
}

int addDirect(int head)
{
  int fin = 0;
  int randArray[] = {-1, 1};
  if (direct == 1)
  {
    fin = head + 4;
    if (head == 15 or head == 14)
    {
      fin = head + randArray[random(2)];
      direct = getDirect();
    }
    else if (head == 13)
    {
      fin = 14;
      direct = 2;
    }
    else if (head == 16)
    {
      fin = 15;
      direct = 4;
    }
    return fin;
  }
  else if (direct == 2)
  {
    fin = head + 1;
    if (head == 8 or head == 12)
    {
      fin = head + (randArray[random(2)] * 4);
      direct = getDirect();
    }
    else if (head == 4)
    {
      fin = 8;
      direct = 1;
    }
    else if (head == 16)
    {
      fin = 12;
      direct = 3;
    }
    return fin;
  }
  else if (direct == 3)
  {
    fin = head - 4;
    if (head == 2 or head == 3)
    {
      fin = head + randArray[random(2)];
      direct = getDirect();
    }
    else if(head == 4)
    {
      fin = 3;
      direct = 4;
    }
    else if (head == 1)
    {
      fin = 2;
      direct = 2;
    }
    return fin;
  }
  else if (direct == 4)
  {
    fin = head - 1;
    if (head == 5 or head == 9)
    {
      fin = head + (randArray[random(2)] * 4);
      direct = getDirect();
    }
    else if (head == 1)
    {
      fin = 5;
      direct = 3;
    }
    else if (head == 13)
    {
      fin = 9;
      direct = 3;
    }
    return fin;
  }
  else if (direct == 5)
  {
    if (snakeLevel <= 0)
    {
      snakeLevel = 4;
    }
    else
    {
      snakeLevel -= 1;
    }
  }
  else if (direct == 6)
  {
    if (snakeLevel >= 4)
    {
      snakeLevel = 0;
    }
    else
    {
      snakeLevel += 1;
    }
  }
  else
  {
    Serial.println("Error!");
  }
  return addX[0];
}
