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
#include <stdio.h>
#include <time.h>

//-----------------------------------------------------------------------------
// Private Structures:
//-----------------------------------------------------------------------------

typedef struct Bogo 
{
  clock_t begin, end;
  double elapsed;

  unsigned size;
  int *array;

  int print;
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
  bogo->print = 0;

  for (unsigned i = 0; i < size; ++i)
  {
    bogo->array[i] = i + 1;
  }

  Shuffle(bogo);

  return bogo;
}

void FreeBogo(Bogo* bogo)
{
  free(bogo->array);
  free(bogo);
  bogo = NULL;
}

void SetPrint(Bogo* bogo, int newPrint)
{
  bogo->print = newPrint;
}

int GetPrint(Bogo* bogo)
{
  return bogo->print;
}

void Sort(Bogo* bogo)
{
  bogo->begin = clock();

  while (!IsSorted(bogo))
  {
    if (bogo->print)
    {
      printf("Array: ");
      for (unsigned i = 0; i < bogo->size; ++i)
      {
        printf("%d ", bogo->array[i]);
      }
      printf("\n");
    }

    Shuffle(bogo);
  }

  bogo->end = clock();
  bogo->elapsed = (bogo->end - bogo->begin) / CLOCKS_PER_SEC;

  return; 
}

void Dump(Bogo* bogo)
{
  printf("Array size:   %d\n", bogo->size);
  printf("Time Elapsed: %f\n", bogo->elapsed);
  
  for (unsigned i = 0; i < bogo->size; ++i)
  {
    printf("%d ", bogo->array[i]);
  }
  printf("\n");
}

//-----------------------------------------------------------------------------
// Private Functions:
//-----------------------------------------------------------------------------

int IsSorted(Bogo* bogo)
{
  for (unsigned i = 1; i < bogo->size; ++i)
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