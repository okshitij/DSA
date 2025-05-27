#include<stdio.h>
#include<stdlib.h> // for malloc(), calloc(), realloc()
#include<string.h>

/*
memory allocation - malloc(): ptr = (datatype*)malloc(n*sizeof(datatype));
void ptr to allocated mem
values at allocated mem are initialized to garbage values

contiguous memory allocation - calloc(): ptr = (datatype*)calloc(n, sizeof(datatype));
void ptr to allocated mem
values at allocated mem are initialized to 0

realloc(): ptr = (datatype*)realloc(ptr, n*sizeof(datatype));
*/

int main()
{
    int *ptr1;
    ptr1 = (int*)malloc(3 * sizeof(int)); //dynamic array of size 3
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &ptr1[i]);
    }

    for(int i = 0; i < 3; i++)
    {
        printf("%d ", ptr1[i]);
    }

    ptr1 = (int*)realloc(ptr1, 6*sizeof(int)); //adhi che values retain nahi karat. parat input karave lagtat
    for(int i = 0; i < 6; i++)
    {
        scanf("%d", &ptr1[i]);
    }

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", ptr1[i]);
    }

    int *ptr2;
    ptr2 = (int*)calloc(3, sizeof(int));

    free(ptr1);
    free(ptr2);


    return 0;
}