/*finds the smallest element in the unsorted part of the array and swaps it with the first element of the unsorted part
-time complexity - O(n^2)
-SELECTION - SELECT MINIMUM and swap
-we get the smallest element in the first iteration*/

#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> &v, int n){
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[min])
                min = j;
        } 
        swap(v[i], v[min]);
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

    selectionSort(v, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

