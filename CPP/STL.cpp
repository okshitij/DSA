#include<iostream>
#include<bits/stdc++.h> //library used for Standard template library(STL)

/*vector is like a dynamic array with the ability of resizing itself when an element is added or deleted
use this instead of dynamic memory allocation*/

/*deque is a doubly ended queue, which allows insertion and deletion at both the ends(push_back, push_front, pop_back, pop_front)*/

/*list implements doubly linked list*/

/*pair is a container that is used to store two values of any type.
first element is referred as first and second element as second*/

/*4002*/

using namespace std;

int main(){

    vector<int> v;

    for(int i = 1; i <= 5; i++){
        v.push_back(i);
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    sort(v.begin(), v.end());

    cout << v.front() << " " << v.back() << endl;
    
    v.pop_back();
    
    cout << v.front() << " " << v.back() << endl;
    
    cout << v.size() << " " << v.capacity() << endl;
    v.clear();
    cout << v.size() << " " << v.capacity() << endl;

    vector<int> v2(4, 1);
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    
    cout << "---------------------------------------------------" << endl;

    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    cout << d.front() << " " << d.back() << endl;

    d.pop_back();
    d.pop_front();

    cout << "---------------------------------------------------" << endl; 

    list<int> l;
    

    //pair<int, char> p;
    //map<int, char> m;
    //set<int> s;
    //unordered_map<int, char> um; -> implementation is based on hash table
    

    



    return 0;
}