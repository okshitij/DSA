#include<stdio.h> // time complexity: best case - O(1), worst case - O(n)

int main()
{
    int n, i, x, found = 0;
    printf("enter the number of elements:\n");
    scanf("%d", &n);

    int a[n];
    printf("enter the elements in the array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("enter the element you want to search:\n");
    scanf("%d", &x);
    for(i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            printf("element is found at the index: %d\n", i);
            found++;
        }
    }

    if(found == 0)
        printf("element not found\n");

    return 0;
}