#include<cmath>
/*int balancedBTs(int n,int *arr) {
    // Write your code here
    if(n <= 1)
        return 1;

    int mod = pow(10,9)+7;
    
    if(arr[n-1] != -1)
        return arr[n-1];
    if(arr[n-2] != -1)
        return arr[n-2];
    
    int x = balancedBTs(n-1,arr);
    int y = balancedBTs(n-2,arr);
    
    int temp1 = (int)( ((long)x) * x  % mod);
    int temp2 = (int)( (2 * ((long)x) * y) % mod);
    
    arr[n] = (temp1+temp2)%mod;
    
   	return (temp1+temp2)%mod;
}*/

int balancedBTs(int n) {
    // Write your code here
    int *arr = new int[n+1];
    // for(int i=0;i<n+1;i++)
    //     arr[i] = -1;
    
    // return balancedBTs(n,arr);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3; i<n+1; i++){
        int mod = pow(10,9)+7;
        int x = arr[i-1];
        int y = arr[i-2];
        int temp1 = (int)(((long)x) * x %mod);
        int temp2 = (int)( (2 * ((long)x) * y) % mod);
        
        arr[i] = (temp1+temp2) % mod;
    }
    return arr[n];
}