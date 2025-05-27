#include<stdio.h>
#include<stdlib.h>

int main()
{
    int mindnum = 0, low = 0, high = 100, compnum = 0, tries=0;
    char h,l,e;
    //h --> higher, l --> lower, e --> equal

    printf("Enter a number between 0 - 100: ");
    scanf("%d", &mindnum);


    while (compnum != mindnum) 
    {
        compnum = ((high - low)/2 + low);
        printf("%d ", compnum);
        tries++;

        if (mindnum > compnum)
        {
            printf("Your guess was h/l/e\n");
            scanf("\n%c",&h);
            low = compnum+1;
        }
        else if (mindnum < compnum)
        {
            printf("Your guess was h/l/e \n");
            scanf("\n%c", &l);
            high = compnum-1;
        }
        else if (mindnum == compnum)
        {
            printf("Your guess was h/l/e \n");
            scanf("\n%c", &e);
            printf("CONGRATULATIONS! You've got it right in %d guesses!\n", tries);
        }
    }


    return 0; 

}