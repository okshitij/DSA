#include<stdio.h>

int main()
{
    int r, c, r1, c1;
    int mat[10][10];
     int sum=0;
    printf("enter the number of rows and columns:\n");
    scanf("%d %d", &r1, &c1);
    printf("enter the element matrix:\n");
    for(r=0; r<r1; r++)
    {
        for(c=0; c<c1; c++)
        { scanf("%d", &mat[r][c]); }
    }

    if(r1 != c1)
    printf("sum of diagonal no possible");

    else
    {
        for(r=0; r<r1; r++)
        {
            for(c=0; c<c1; c++)
            {
                if((r+c) == (r1- 1))
                sum = sum + mat[r][c];
            }
        }
         printf("sum is: %d", sum);
    }

    return 0;
}
