/*works on repeated swapping of adjacent elements
time complexity - O(n^2)*/

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]){ 
                swap(v[j], v[j + 1]);
            }
        }
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

    bubbleSort(v, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

/*sorting
selection - select min and swap
insertion - insert at correct position
quick - put pivot at correct position w elements smaller than pivot on left and greater than pivot on right
        and then sort left and right subarrays recursively
merge - divide and conquer
heap*/