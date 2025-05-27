#include<stdio.h>
int main()
{
    int a,b,c,f,g;
    float j;
    char h;
    printf("enter two numbers");
    scanf("%d %d", &a, &b);
    printf("Press + for addition \nPress - for subtraction \nPress * for multiplication \nPress / for division\n");
    scanf("\n%c",&h);
    switch (h)
    {
        case '+': 
        c=a+b;
        printf("addition of %d %d is %d",a,b,c);
        break;

        case '-':
        f=a-b;
        printf("subtraction of %d %d is %d",a,b,f);
        break;

        case '*':
        g=a*b;
        printf("multipication of %d %d is %d",a,b,g);
        break;

        case '/':
        j=a*1.0/b;
        printf("division of %d %d is %f",a,b,j);
        break;
    }

    return 0;
}