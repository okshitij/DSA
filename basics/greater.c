#include<stdio.h>

int main()
{
    int a,b;
    printf("enter two numbers");
    scanf("%d %d", &a,&b);
    if(a<b)
    {
    printf("%d is greater",b);
    }
    else if(a>b)
    {
    printf("%d is greater",a);
    }
    else
    {
    printf("%d is equal to %d",a,b);
    }  
    return 0;
}    
