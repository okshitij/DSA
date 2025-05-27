#include<iostream>
#include<vector>
#include<set>

using namespace std;

void descending(vector<int> &v){
    //set<int, greater<int>> s; --> to store in descending order
    //unordered_set<int> s; --> to store in random order
    set<int> s; // to store in ascending order

    for(int i = 0; i < v.size(); i++){
        s.insert(v[i]);
    }

    for(auto x : s){
        cout << x << " ";
    }
}

int main(){
    vector<int> v;
    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    descending(v);

    return 0;
}