#include <stdio.h> //pyramidal pattern

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    char a[row][col];
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<2*row; j++)
        {
            if(j<row-i-1 || j>= row+i)
                printf(" \t");
            else
                printf("*\t");
        }
        printf("\n");
    }
    
    
    return 0;
}
