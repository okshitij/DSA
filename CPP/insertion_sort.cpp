 /*hyat original list 2 sublist madhe divide hote, sorted ani unsorted list.
apan saglyat pahila element sorted assume karto ani mag unsorted list madhun pahila element pick karun 
tyala sorted list shi compare karto ani comparison ni tyachi appropriate postition shodun tya
element la tikde insert karaycha. 
time complexity: O(n^2)*/ 

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v, int n){ //5 3 1 2 //3 5 1 2 //3 1 5 2 //1 3 5 2
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && v[j] < v[j - 1]){
            swap(v[j], v[j - 1]);
            j--; //j-- is to track the element where its going
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

    insertionSort(v, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}