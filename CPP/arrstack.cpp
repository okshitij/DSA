#include<iostream>

using namespace std;

#define MAX 100

class stack {
    int* arr;
    int top;

    public:
    stack(){
        arr = new int[MAX];
        top = -1;
    }

    void push(int x){
        if(top == MAX-1){
            cout << "stack overflow" << endl;
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    void pop(){
        if(top == -1){
            cout << "stack underflow" << endl;
        }
        else{
            top--;
        }
    }

    int Top(){
        if(top == -1){
            cout << "no element in stack" << endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    bool empty(){
        return top == -1;
    }

};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    


    return 0;
    
}