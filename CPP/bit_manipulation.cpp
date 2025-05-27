/*AND TABLE - 
OR TABLE - 
XOR TABLE - */


#include<iostream>

using namespace std;

void printBinary(int n){
    for(int i = 10; i >= 0; i--){
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

void checkEvenOdd(int n){
    if(n & 1)
        cout << "Odd";
    else
        cout << "Even";
    cout << endl;
}

void countSetBits(int n){
    int count = 0;
    while(n){
        count += (n & 1);
        n = n >> 1; // right shift n by 1
    }
    cout << "the set bits are: " << count << endl;
}

void countSetBits2(int n){
    cout << __builtin_popcount(n);
    cout << endl;
}

void checkPowerOfTwo(int n){
    if(n & (n - 1))
        cout << "Not a power of 2";
    else
        cout << "Power of 2";
    cout << endl;
}

void checkKthBitSet(int n, int k){
    if(n & (1 << k)) // 1<<k is 1 shifted k times
        cout << "Set";
    else 
        cout << "Not Set";
    cout << endl;
}

void setKthBit(int n, int k){
    cout << (n | (1 << k));
    cout << endl;
}

void unsetKthBit(int n, int k){
    cout << (n & ~(1 << k));
    cout << endl;
}

void toggleKthBit(int n, int k){
    cout << (n ^ (1 << k));
    cout << endl;
}

void divideByTwoPowerK(int n, int k){
    cout << (n >> k);
    cout << endl;
}

void multiplyByTwoPowerK(int n, int k){
    cout << (n << k);
    cout << endl;
}

void swap(int a, int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;;
}



int main(){
    int n;
    cin >> n;
    printBinary(n);
    checkEvenOdd(n);
    countSetBits(n);
    checkPowerOfTwo(n);
    checkKthBitSet(n, 2);
    setKthBit(n, 2);
    unsetKthBit(n, 2);
    toggleKthBit(n, 2);
    divideByTwoPowerK(n, 1);


}