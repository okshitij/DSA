/* hyat apan original list la 2 sublist madhe divide karto. initially apan ek pivot element choose 
karto mostly leftmost element jyacha left side la tyacha peksha kami values wale elements astil
ani right side la tyahun mothe. leftmost element la as start declare karu ani rightmost la as end.
ata start la increment karaycha jar tyacha pudhchi value pivot peksha less than or equal to asel
ani increment karna thambvaycha jevah ti cond satisfy nahi karat. next step madhe apan end la decrement
karto jar tyacha adhichi value pivot peksha mothi asel ani tevah thambvaycha jevah ti cond satisfy nhi hot.
jevah donhi pointers thambtil tevah tya pointers chi value swap karaychi. start ani end tevah swap karaycha
jevah start end chya alikadhe asel, jar palikade asel tevah end ani pivot chi value swap karaychi.
hya iteration madhe aplyala pivot chi correct position sapadte :)
time complexity: best case - O(nlogn), worst case - O(n^2) */

#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int LB, int UB)
{
    int pivot = a[LB];
    int start = LB;
    int end = UB;
    while(start < end)
    {
        while(a[start] <= pivot)
            start++;
        while(a[end] > pivot)
            end--;
        if(start < end)
            swap(&a[start], &a[end]);
    }
    swap(&a[LB], &a[end]);

    return end;    
}

void QuickSort(int a[], int LB, int UB)
{
    if(LB < UB)
    {
        int position = partition(a, LB, UB);
        QuickSort(a, LB, position - 1);
        QuickSort(a, position + 1, UB);
    }
}

int main()
{
    int size;
    printf("enter the size of array: ");
    scanf("%d", &size);

    int a[size];
    printf("enter the elements in the array:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    int LB = 0;
    int UB = size - 1;
   // partition(a, LB, UB);
    QuickSort(a, LB, UB);

    printf("sorted array will be:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

/*
another short code for quicksort:

#include<stdio.h>


*/
