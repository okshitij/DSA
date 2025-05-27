#include <stdio.h> 
void sort(int n, int* ptr) 
{    int i, j, t; 
    for (i = 0; i < n; i++) 
    { 
        for (j = i + 1; j < n; j++)
        { 
            if (*(ptr + j) < *(ptr + i)) 
            {
                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
    for (i = 0; i < n; i++) 
        printf("%d ", *(ptr + i)); 
} 
  
int main() 
{ 
    int n;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of array:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort(n, a); 
    return 0; 
} 