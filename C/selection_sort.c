/* hyat suddha list 2 sublist madhe divide hote sorted ani unsorted.
initially sorted list empty aste. unsorted list madhna saglyat chota number select karaycha ani tyala 
unsorted list chya first element sobat swap karaycha.
total passes list chi size - 1 ani first pass madhe aplyala saglyat chota element prapt hoto
time complexity: best and worst case - O(n^2)*/

#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size)
{
  for (int i = 0; i < size-1; i++) // size-1 karan first pass madhe i chi value 0 asnar. passes saathi loop
  {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) // least element find karayla loop
    {
      if (array[j] < array[min_idx])
        min_idx = j;
    }
    swap(&array[min_idx], &array[i]);
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

  selectionSort(arr, size);

  printf("\nSorted array in Ascending Order:\n");
  for (int i = 0; i < size; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}