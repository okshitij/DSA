#include <stdio.h>

void merge(int A[], int mid, int left, int right)
{
    int i, j, k, B[10];
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = left; i <= right; i++)
     A[i] = B[i]; 
}

void mergeSort(int A[], int left, int right){
    int mid;
    if(left<right){
        mid = (left + right) /2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, mid, left, right);
    }
}

int main()
{
  int size;
  printf("\n Enter size of array");
  scanf("%d",&size);
  int arr[size];
   printf("\nEnter Elements\n");
   for (int i = 0; i < size; i++)
  {
    scanf("%d",&arr[i]);
  }
    mergeSort(arr, 0, size-1);

    printf("Sorted array: \n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
    return 0;
}

