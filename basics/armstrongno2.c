#include<stdio.h>
#include<math.h>
int main()
{
    int a, b=0, c, d, e=0;
    printf("enter a number");
    scanf("%d",&a);

    d = a;
    while(d!=0)
    {
        d = d/10;
        e++;
    }

    a = d;
    while(a!=0)
    {
        c = a%10;
        b = b + pow(c,e);
        a = a / 10;
    }

    if(b == a)
        printf("the number is an armstrong number");
    else
        printf("the number is not an armstrong number");

    return 0;
}