#include<stdio.h>
int main()
{
    int n, i, sum = 0;
    printf("enter the number of elements:\n");
    scanf("%d", &n);

    int a[n];
    printf("enter the elements in the array:\n");

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(i=0; i<n; i++)
        sum += a[i];

    printf("%d", sum);

    return 0;
}