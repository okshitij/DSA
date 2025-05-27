#include<stdio.h>
#include<ctype.h> //header file for tolower or toupper

int main()
{
    char x;
    printf("enter any letter");
    scanf("\n%c",&x);
    x=tolower(x);

    switch (x)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        printf("%c is a vowel",x);
        break;

        default:
        printf("%c is a consonant",x);
        break;
    }
    return 0;
}