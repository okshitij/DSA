/*in this choose a pivot position either first or last or middle depending on your convenience
we choose first element as pivot in this code
declare first element as start and last as end
increment start if its next value is less than or equal to the pivot value, stop when condition doesnt satisfy
decrement end if its earlier value is greater than pivot value, stop when condition doesnt satisfy
if start < end, swap start and end
else swap pivot and end
in every iteration we find the correct position of pivot element
do this recursievly to sort the array

time complexity - O(n^2)*/

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &v, int LB, int UB){
    int pivot = v[LB];
    int start  = LB;
    int end = UB;

    while(start < end){
        if(v[start] <= pivot){
            start++;
        }
        if(v[end] > pivot){
            end--;
        }
        if(start < end){
            swap(v[start], v[end]);
        }
        swap(v[LB], v[end]);
    }

    return end;
}

void quickSort(vector<int> &v, int LB, int UB){
    if(LB < UB){
        int pivot = partition(v, LB, UB);
        quickSort(v, LB, pivot - 1); // sorts left subarray
        quickSort(v, pivot + 1, UB); // sorts right subarray 
    }

}

int main(){
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int LB = 0;
    int UB = n - 1;

    quickSort(v, LB, UB);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}