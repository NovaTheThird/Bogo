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
}

//-----------------------------------------------------------------------------
// Private Functions:
//-----------------------------------------------------------------------------

int IsSorted(Bogo* bogo)
{
  return 0;
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