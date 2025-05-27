

#include <stdio.h>

void insertionSort(int array[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int key = array[i]; // key is first element of the unsorted array
    int j = i - 1; 
    while (key < array[j] && j >= 0) // loop for comparison
    {
        array[j + 1] = array[j];
        --j;
    }
    array[j + 1] = key;
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

  insertionSort(arr, size);

  printf("Sorted array in ascending order:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}