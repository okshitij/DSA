#include<stdio.h>

int main()
{
    int a,b,c,f,g,k;
    float j;
    printf("enter two numbers");
    scanf("%d %d", &a, &b);
    c=a+b;
    printf("addition of %d %d is %d",a,b,c);
    f=a-b;
    printf("\nsubtraction of %d %d is %d",a,b,f);
    g=a*b;
    printf("\nmultipication of %d %d is %d",a,b,g);
    j=a*1.0/b;
    printf("\ndivision of %d %d is %f",a,b,j);
    k=a%b;
    printf("\nremainder of %d %d is %d",a,b,k);
    

    return 0;
}