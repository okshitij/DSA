/*only used in sorted array
time complexity - O(logn)*/

#include<iostream>
#include <vector>

using namespace std;

int search(vector<int> v, int key, int low, int high){

    if(high >= low){
        int mid = low + (high - low) / 2;

        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] > key){
            return search(v, key, low, mid - 1); //in iterative code: high = mid - 1
        }
        else{
            return search(v, key, mid + 1, high); //in iterative code: low = mid + 1
        }

    }
    else
        return 1;

}

int main(){
    int n; 
    cout << "enter the size of array" << endl;
    cin >> n;

    vector<int> v(n);
    cout << "enter the elements of array" << endl;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int key;
    cout << "enter the element to be searched" << endl;
    cin >> key;

    int result = search(v, key, 0, n-1);
    if(result == 1){
        cout << "element not found" << endl;
    }
    else{
        cout << "element found at index " << result << endl;
    }

    return 0;
}