#include <stdio.h>

int main(void)
{
  printf("compile time: %s\n", __TIME__);
  printf("compile date: %s\n", __DATE__);

  return 0;
}