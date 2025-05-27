/*step 1: build max heap using heapify
step 2: then swap the first element(node) with the last and after swap consider the last element to be sorted
        and remove it
step 3: repeat step 1 and step 2

time complexity - O(nlogn)*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &v, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && v[left] > v[largest])
        largest = left;
    
    if(right < n && v[right] > v[largest])
        largest = right;

    if(largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }

}

void heapSort(vector<int> &v, int n){
    for(int i = n/2 - 1; i <= 0; i--)
        heapify(v, n, i);
    
    for(int i = n - 1; i >= 0; i--){
        swap(v[0], v[i]);
        
        heapify(v, i, 0);
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

    heapSort(v, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}