#include<stdio.h>

int main()
{
    int r, c, r1, c1;
    int first[10][10], t[10][10];

    printf("enter the number of rows and columns of first matrix\n");
    scanf("%d %d",&r1,&c1);

    printf("insert your matrix elements:\n");

    for(r = 0; r < r1; r++)
    {
        for(c = 0; c < c1; c++)
            scanf("%d",first[r][c]);
    }

    for(r = 0; r < r1; r++)
    {
        for(c = 0; c < c1; c++)
            t[c][r] = first[r][c];
    }

    printf("original matrix is:\n");
    for(r = 0; r < r1; r++)
    {
        for(c = 0; c < c1; c++)
        {
            printf("%d\t",first[r][c]);
            printf("\n");
        }
    }

    printf("transpose of the matrix is:\n");
    for(r = 0; r < c1; r++)
    {
        for(c = 0; c < r1; c++)
        {
            printf("%d\t",t[r][c]);
            printf("\n");
        }
    }

    return 0;
}
