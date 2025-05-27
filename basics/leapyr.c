#include<stdio.h>

int main()
{
  int a;
  printf("enter year");
  scanf("%d", &a);

  if(a % 4 == 0)
    printf("the year is a leap year");
  else
    printf("the year was not a leap year");

  return 0;
}