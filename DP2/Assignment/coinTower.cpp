#include <string>
string findWinner(int n,int x,int y) {
    int dp[2000000];
    dp[1]=1;
    dp[x]=1; dp[y]=1;
    for(int i=2;i<=n;i++) {
        if(!dp[i]) // if beerus is not winning at i
        {
            dp[i]=dp[i-1]^1; // beerus can always remove 1 coin and be at the dp[i-1]
            if(i-x>=1)//beerus can always remove x coin and be at the dp[i-x]
            {
                dp[i]=max(dp[i],dp[i-x]^1);
            }
            if(i-y>=1)//beerus can always remove x coin and be at the dp[i-y] 
            {
                dp[i]=max(dp[i],dp[i-y]^1); 
            }
        }
    }
    string sol; 
    if(dp[n]) 
        sol="Beerus";
    else
        sol="Whis";
    return sol;
}

// bool findWinner_helper(int x, int y, int n)
// {
//     int dp[n + 1];
 
    
//     dp[0] = true;
//     dp[1] = false;
 
    
//     for (int i = 2; i <= n; i++) {
 
        
//         if (i - 1 >= 1 and !dp[i - 1])
//             dp[i] = true;
//         else if (i - x >= 1 and !dp[i - x])
//             dp[i] = true;
//         else if (i - y >=1 and !dp[i - y])
//             dp[i] = true;
 
        
//         else
//             dp[i] = false;
//     }
 
   
//     return dp[n];
// }
// string findWinner(int n, int x, int y)
// {
// 	// Write your code here .
//     if(findWinner_helper(n,x,y) == false)
//         return "Beerus";
//     else
//         return "Whis";
// }