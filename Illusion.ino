int illusion1[2] = {7,2};
int illusion2[2][2] = {{7,2},{6,2}};
int illusion3[7][2] = {{7,3},{6,3},{11,3},{10,3},{11,2},{10,2}};
int illusion4[32][2] = {{1,1},{1,2},{1,3},{1,4},{2,1},{2,4},{3,1},{3,4},{4,1},{4,2},{4,3},{4,4},{5,1},{5,4},{8,1},{8,4},{9,1},{9,4},{12,1},{12,4},{13,1},{13,2},{13,3},{13,4},{14,1},{14,4},{15,1},{15,4},{16,1},{16,2},{16,3},{16,4}};

void illusion()
{
  getDirect();
  for (int i = 0; i < 180; i++)
  {
    for (int j = 0; j < sizeof(illusion2)/sizeof(illusion2[0]); j++)
      {
        illusionLoop(illusion2[j]);
      }
  }
  for (int i = 0; i < 60; i++)
  {
    for (int j = 0; j < sizeof(illusion3)/sizeof(illusion3[0]); j++)
    {
      illusionLoop(illusion3[j]);
    }
  }
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < sizeof(illusion4)/sizeof(illusion4[0]); j++)
    {
      illusionLoop(illusion4[j]);
    }
  }
}

void illusionLoop(int (& letArray) [2])
{
  for (int i = 0; i < sizeof(letArray)/sizeof(int); i++)
  {
    oneLed(letArray[0],letArray[1]);
    delayMicroseconds(50);
  }
}
