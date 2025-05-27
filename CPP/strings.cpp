#include<iostream>
#include<string>

using namespace std;

void reverse(){
    string s;
    cin >> s;

    int start = 0, end = s.length() - 1;
    while(start < end)
        swap(s[start++], s[end--]);

    cout << s;
}

int main(){
    reverse();

    



    return 0;
}