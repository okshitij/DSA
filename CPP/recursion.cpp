#include<iostream>
#include<vector>

using namespace std;

int sum(int n){
    if(n == 0)
        return 0;
    
    return n + sum(n - 1);
}

int fact(int n){
    if(n == 0)
        return 1;
    
    return n * fact(n - 1);
}

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

//bottom up approach - tabulation -> DP
int fibo(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Build the result bottom-up
    }
    
    return dp[n];
}



int main(){
    int n;
    cin >> n;

    cout << sum(n) << endl;
    cout << fact(n) << endl;
    cout << fib(n) << endl;
    cout << fibo(n) << endl;


    return 0;
}
