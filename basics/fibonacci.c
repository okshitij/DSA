#include<stdio.h>

void main()
{
    int n;    
    printf("Enter the number of elements:\n");    
    scanf("%d",&n); 
    fib(n);
}

void fib(int n)
{
    static int n1=0,n2=1,n3;
    for(int i = 0; i < n; i++)   
    {    
        printf("%d", n3);
        n1= n2;
        n2 = n3;
        n3 = n1 + n2;
    }  
}