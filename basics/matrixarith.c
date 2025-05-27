#include<stdio.h>
int main()
{
    int r, c, r1, c1, r2, c2, tot=0;
    int first[10][10], sec[10][10], add[10][10], sub[10][10], mul[10][10], t[10][10];
    char h;

    printf("enter the number of rows and columns of first matrix\n");
    scanf("%d %d",&r1, &c1);

    printf("enter your matrix elements\n");

    for(r=0; r<r1; r++)
    {
        for(c=0; c<c1; c++)
        { scanf("%d", &first[r][c]); }
    }

    printf("enter the number of rows and coulmns for second matrix:\n");
    scanf("%d %d", &r2, &c2);
    printf("insert your matrix elements\n");

    for(r=0; r<r2; r++)
    {
        for(c=0; c<c2; c++)
        { scanf("%d", &sec[r][c]); }
    }

    printf("Press + for addition \nPress - for subtraction \nPress * for multiplication \nPress / for transpose");
    scanf("\n%c",&h);
    switch (h)
    {
        case '+': 
        for(r = 0; r < r1; r++)
        {
            for(c = 0; c < c1; c++)
            {
                add[r][c] = first[r][c] + sec[r][c];
                printf("addition of both matrices is %d", add[r][c]);
            }
            
        }
        break;

        case '-':
        for(r = 0; r < r1; r++)
        {
            for(c = 0; c < c1; c++)
            {
                sub[r][c] = first[r][c] - sec[r][c];
                printf("subtraction of both matrices is %d", sub[r][c]);
            }
            
        }
        break;

        case '*':
        if (c1!= r2)
        printf("your givern matrices cannot be multiplied with each other\n");
        else
        {
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
                {    printf("%d\t", mul[r][c]);
                }
                printf("\n");
            }
        }
        break;

        case '/':
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
            }
             printf("\n");
        }

        printf("transpose of the matrix is:\n");
        for(r = 0; r < c1; r++)
        {
            for(c = 0; c < r1; c++)
            {
                printf("%d\t",t[r][c]);
            }    
              printf("\n");
        }
        break;
    }

    return 0;

}