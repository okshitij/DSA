#include<stdio.h>

int main()
{
    int a,b,c,d,e;
    printf("enter a number");
    scanf("%d",&a);
    b=a%10;
    d=a/10;
    e=b*10+d;
    printf("%d",e);
    
    return 0;
    
}