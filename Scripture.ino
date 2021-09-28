int three[16][2] = {{4,1},{4,4},{8,1},{8,2},{8,4},{12,1},{12,2},{12,3},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int n[16][2] = {{4,1},{4,2},{4,3},{4,4},{8,2},{8,3},{12,1},{12,2},{12,3},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int e[16][2] = {{4,1},{4,2},{4,3},{4,4},{8,1},{8,2},{8,4},{12,1},{12,2},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int p[16][2] = {{4,1},{4,2},{4,3},{4,4},{8,2},{8,4},{12,2},{12,3},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int h[16][2] = {{4,1},{4,2},{4,3},{4,4},{8,2},{12,1},{12,2},{12,3},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int i[16][2] = {{4,1},{4,4},{8,1},{8,2},{8,3},{8,4},{12,1},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int two[16][2] = {{4,1},{4,4},{8,1},{8,2},{8,4},{12,1},{12,3},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int colon[16][2] = {{8,2},{8,3},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int one[16][2] = {{4,1},{4,3},{8,1},{8,2},{8,3},{8,4},{12,1},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int zero[16][2] = {{4,1},{4,2},{4,3},{4,4},{8,1},{8,4},{12,1},{12,2},{12,3},{12,4},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
void scripture()
{
  getDirect();
  first(three);
  arrayLoop(three, n);
  arrayLoop(n, e);
  arrayLoop(e, p);
  arrayLoop(p, h);
  arrayLoop(h, i);
  arrayLoop(i, two);
  arrayLoop(two, two);
  arrayLoop(two, colon);
  arrayLoop(colon, one);
  arrayLoop(one, zero);
  last(zero);
  delay(3000);
}

void arrayLoop(int (& letArray) [16][2], int (& letArray2) [16][2])
{
  for (int x = 2; x < 4; x++)
  {
    for (int j = 0; j < 100; j++)
    {
      for (int i = 0; i < sizeof(letArray2)/sizeof(letArray2[0]); i++)
      {
        oneLed(letArray[i][0]-x,letArray[i][1]);
        delayMicroseconds(100);
        oneLed(letArray2[i][0]-x+2,letArray2[i][1]);
        delayMicroseconds(100);
      }
    }
  }
}

void first(int (& letArray) [16][2])
{
  for (int x = 0; x < 2; x++)
  {
    for (int j = 0; j < 200; j++)
    {
      for (int i = 0; i < sizeof(letArray)/sizeof(letArray[0]); i++)
      {
        oneLed(letArray[i][0]-x,letArray[i][1]);
        delayMicroseconds(100);
      }
    }
  }
}

void last(int (& letArray) [16][2])
{
  for (int x = 2; x < 4; x++)
  {
    for (int j = 0; j < 200; j++)
    {
      for (int i = 0; i < sizeof(letArray)/sizeof(letArray[0]); i++)
      {
        oneLed(letArray[i][0]-x,letArray[i][1]);
        delayMicroseconds(100);
      }
    }
  }
}
