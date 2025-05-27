#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   srand(time(NULL));

   int number = rand() % 100;
   int chances = 9, tries=0;

    int a;
    for(int i = 0; i<=chances; i++)
    {
        printf("\nwhat's your guess:");
        scanf("%d", &a);
        tries++;


        if(number < a)
           printf("Your guess is larger than the number you are predicting\n"); 

        else if(number > a)
            printf("Your guess is smaller than the number you are predicting\n");

        else if(number == a)
            printf("CONGRATULATIONS! YOU'VE GOT IT RIGHT IN %d GUESSES!!\n", tries);
            
    }

    return 0;
}