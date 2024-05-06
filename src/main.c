//-----------------------------------------------------------------------------
//
// Name:    main.c
// Author:  Nicholas Brennan
// Purpose: Driver
//
// Date Created: 05/03/2024
// Last Updated: 05/03/2024
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Include Files:
//-----------------------------------------------------------------------------

#include "bogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------------------------------------
// Main:
//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    printf("Invalid argument count\n");
    return -1;
  }

  if (strcmp(argv[1], "-h") == 0)
  {
    printf("compile time: %s\n", __TIME__);
    printf("compile date: %s\n", __DATE__);
    printf("==============================\n");
    printf("bogo [argument]\n");
    printf("arguments:\n");
    printf("  -h  -  lists help (here)\n");
    printf("  -s  -  an integer that is the size of the array\n");

    return 0;
  }
  else if (strcmp(argv[1], "-s") == 0)
  {
    if (argv[2])
    {
      int size = atoi(argv[2]);

      Bogo* bogo = CreateBogo(size);

      Sort(bogo);
      Dump(bogo);

      FreeBogo(bogo);

      return 0;
    }
    else
    {
      printf("No size provided\n");
      return -1;
    }
  }
  else
  {
    printf("Invalid arguments\n");
    return -1;
  }
}