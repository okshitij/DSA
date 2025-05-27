#include <stdio.h>
int main() 
{
    int n;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Even numbers are:\n");
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
            printf("%d ", a[i]);
    }
    printf("\nOdd numbers are:\n");
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==1)
            printf("%d ", a[i]);
    }    

    return 0;
}   