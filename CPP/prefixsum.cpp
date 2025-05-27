#include<iostream>

using namespace std;
void prefixsum(int *array, int n, int prefixSum[]){
    prefixSum[0] = array[0];
    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + array[i];
    }
}

int main(){
    cout << "enter the number of elements in the array"<<endl;
    int n;
    cin >> n;

    int *array;
    array = new int[n];

    int prefixSum[n];

    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    prefixsum(array, n, prefixSum);

    for(int i = 0; i < n; i++){
        cout << prefixSum[i] << " ";
    }
    
    return 0;
}