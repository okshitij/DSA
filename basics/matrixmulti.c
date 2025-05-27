#include<stdio.h>

int main()
{
    int r,c,r1,c1,r2,c2, tot=0;
    int first[10][10], sec[10][10], mul[10][10];

    printf("enter the number of rows and columns for first matrix:\n");
    scanf("%d %d", &r1, &c1);

    printf("insert your matrix elements: \n");

    for(r=0; r<r1; r++)
    {
        for(c=0; c<c1; c++)
        { scanf("%d", &first[r][c]); }
    }

    printf("enter the number of rows and coulmns for second matrix:\n");
    scanf("%d %d", &r2, &c2);

    if (c!= r2)
        printf("your givern matrices cannot be multiplied with each other\n");
    else
    {
        printf("insert your elements for second matrix\n");

        for(r = 0; r < r2; r++)
            for(c = 0; c < c2; c++)
                scanf("%d", &sec[r][c]);

        for(r = 0; r < r1; r++)
        {
            for(c = 0; c < c2; c++)
            {
                for(int k = 0; k < r2; k++)
                {
                    tot += first[r][k] * sec[k][c];
                }
                mul[r][c] = tot;
                tot = 0;
            }
        }

        printf("the result of product of matrices is:\n");
        for(r = 0; r < r1; r++)
        {
            for(c = 0; c < c2; c++)
                printf("%d\t", mul[r][c]);
                printf("\n");
        }

    }

    return 0;    
}   