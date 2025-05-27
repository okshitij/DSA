#include<stdio.h>

int main()
{
    int a, i = 0;
    int remainder[10];
    printf("enter the number in decimal form:\n");
    scanf("%d",&a);

    while(a!= 0)
    {
        remainder[i] = a % 2;
        a = a / 2;
        i++;
    }

    for(a=i-1;a>=0;a--) //printing the array in reverse order
    {
        printf("%d",remainder[a]);
    }

    return 0;
}