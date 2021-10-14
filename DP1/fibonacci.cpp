#include<iostream>
using namespace std;

//Dynamic Programing
int fibo_DP(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i<=n; i++)
        ans[i] = ans[i-1] + ans[i-2];
    
    return ans[n];
}

//Memoization 
int fibonacci(int n,int *arr){
    if(n <= 1)
        return n;

    if(arr[n] != -1){
        return arr[n];
    }
    int a = fibonacci(n-1,arr);
    int b = fibonacci(n-2,arr);
    arr[n] = a+b;

    return arr[n];
}

int main(){
    int n = 5;
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }
    cout<<fibo_DP(n);
}