#include<stdio.h>  //find gcd of two numbers using recursion

int gcd();

int main()
{
    int a, b;
    printf("enter two numbers:\n");
    scanf("%d%d", &a, &b);
    printf("the gcd of %d and %d is:%d", a, b, gcd(a,b));
    return 0;
}

int gcd(int a, int b)
{
    if(a > b)
    {
        if(a % b == 0)
        return b;
        else
        return gcd(b,a%b);
        
    }

    if(b > a)
    {
        if(b % a == 0)
        return a;

        else
        return gcd(a, b%a);
    }

    return 0;

}
