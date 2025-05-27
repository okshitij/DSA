#include<stdio.h>
int search();
int main()
{
    int a[20];
    int t, i;
    printf("enter the number of elements:\n");
    scanf("%d", &t);

    printf("enter the elements in increasing order:\n");
    for(i = 0; i<t; ++i)
        scanf("%d", &a[i]);

    int x;
    printf("enter the element to be searched:\n");
    scanf("%d", &x);
    
    int value = search(a, x, 0, t-1);
    if(value == 1)
    printf("element not found");
    else
    printf("element found at index %d", value);

}

int search(int a[], int x, int low, int high)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;

        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            return search(a, x, low, mid -1); //recursively call search()
        else
            return search(a, x, mid + 1, high);
    }
    else
        return 1;
}