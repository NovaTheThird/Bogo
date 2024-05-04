//-----------------------------------------------------------------------------
//
// Name:    bogo.c
// Author:  Nicholas Brennan
// Purpose: Bogo sort functions
//
// Date Created: 05/03/2024
// Last Updated: 05/03/2024
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Include Files:
//-----------------------------------------------------------------------------

#include "bogo.h"
#include <stdlib.h>
#include <time.h>

//-----------------------------------------------------------------------------
// Private Structures:
//-----------------------------------------------------------------------------

typedef struct Bogo 
{
  time_t timeBegin;
  time_t timeEnd;
  time_t timeElapsed;

  unsigned size;
  int *array;
}Bogo;

//-----------------------------------------------------------------------------
// Private Function Declarations:
//-----------------------------------------------------------------------------

int IsSorted(Bogo* bogo);
void Shuffle(Bogo* bogo);

//-----------------------------------------------------------------------------
// Public Functions:
//-----------------------------------------------------------------------------

Bogo* CreateBogo(unsigned size)
{
  // Create bogo
  Bogo* bogo = calloc(1, sizeof(Bogo));

  // Set array values
  bogo->size = size;
  bogo->array = calloc(size, sizeof(int));

  for (unsigned i = 0; i < size; ++i)
  {
    bogo->array[i] = i + 1;
  }

  Shuffle(bogo);

  return bogo;
}

void FreeBogo(Bogo* bogo)
{
  free(bogo);
  bogo = NULL;
}

void Sort(Bogo* bogo)
{
  bogo->timeBegin = time(NULL);

  while (!IsSorted(bogo))
  {
    Shuffle(bogo);
  }

  bogo->timeEnd = time(NULL);
  bogo->timeElapsed = bogo->timeEnd - bogo->timeBegin;

  return; 
}

void Dump(Bogo* bogo)
{
  char buff[20];
  printf("Array size: %d", bogo->size);
  strftime(buff, 20, "Time to sort: %H:%M:%S", localtime(&bogo->timeElapsed));
}

//-----------------------------------------------------------------------------
// Private Functions:
//-----------------------------------------------------------------------------

int IsSorted(Bogo* bogo)
{
  for (int i = 1; i < bogo->size; ++i)
  {
    if (bogo->array[i - 1] > bogo->array[i])
    {
      return 0;
    }
  }

  return 1;
}

void Shuffle(Bogo* bogo)
{
  srand(time(NULL));

  for (unsigned i = 0; i < bogo->size; i++)
  {
    unsigned swapIndex = rand() % bogo->size;
    unsigned temp = bogo->array[i];
    bogo->array[i] = bogo->array[swapIndex];
    bogo->array[swapIndex] = temp;
  }
}