/* works on divide and conquer approach, uses recursion
1. divide: the array recursively into two halves until each array has only one element
2. conquer: sort the divided arrays 

time complexity - O(nlogn)*/

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &v, int LB, int mid, int UB){
    int i = LB;
    int j = mid + 1;
    int k = LB;

    vector<int> temp;
    while(i <= mid && j <= UB){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(v[i]);
        i++;
    }

    while(j <= UB){
        temp.push_back(v[j]);
        j++;
    }

    for(int i = LB; i <= UB; i++){
        v[i] = temp[i - LB];
    }
    
}

//used recursion to divide the array into 2 halves and merge them in the end
void mergeSort(vector<int> &v, int LB, int UB){
    int mid;
    if(LB < UB){ 
        mid = (LB + UB)/2;
        mergeSort(v, LB, mid);
        mergeSort(v, mid + 1, UB);
        merge(v, LB, mid, UB);
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

    int LB = 0; // lower bound
    int UB = n - 1; // upper bound

    mergeSort(v, LB, UB);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}