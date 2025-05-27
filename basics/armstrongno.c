#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c,d,e,f;
    printf("enter a number");
    scanf("%d", &a);

    b=a%100;
    c=a%10;
    d=a;
    e=b*100 + c*10 + d;

    if(pow(b,3) + pow(c,3) + pow(d,3) == e)
        printf("the number is an armstrong number");

    else
        printf("the number is not an armstrong number");

    return 0;
}