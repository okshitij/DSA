#include <stdio.h>
int fact(int n, int *factorial)
{
    *factorial = 1;
    if (n == 0 && n == 1)
        return 1;
    else if (n != 0 && n != 1)
    {
        for (int i = n;i >= 1;i--)
        {
            *factorial = *factorial*i;
        }
    }
    return *factorial;
}
int main()
{
    int num,i,factorial;
    printf("enter the number:\n");
    scanf("%d",&num);
    scanf("%*c");
    printf("%d",fact(num,&factorial));
}
