#include<stdio.h>
#include<stdlib.h>

static int r_to_i(char a)
{
    switch(a)
    {
        case 'I':
            return 1;

        case 'V':
            return 5;

        case 'X':
            return 10;

        case 'L':
            return 50;

        case 'C':
            return 100;

        case 'D' :
            return 500;

        case 'M':
            return 1000;

        default:
            return 0;

    }
}

int romantoint()
{

}

int main()
{

    return 0;

}