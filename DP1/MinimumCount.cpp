#include<climits>
#include <bits/stdc++.h>




/*
 int helper(int ans[], int n) {
    int finalans = 0;
    
    
    int sq = sqrt(n);
    if(sq * sq == n) {
        return 1;
    }
    if(n <= 3) {
        return n;
    }
    
    int small = INT_MAX;
    // check if already present or not
    if(ans[n] != -1) {
        return ans[n];
    }
    
    for(int i = 1; i * i <= n; i++) {
        int a = helper(ans, n - (i *i));
        small = min(small, a + 1);
        ans[n] = small;
    }
    return ans[n];
}


int minCount(int n) {
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    
    return helper(ans, n);
} 
*/
// DP APPROACH
/*
int minCount(int n) {
    // count[i] - represents minimum count of squares for integer n
    if(n <= 3) { 
        return n;
    }
    int count[n + 1] ;
    count[0] = 0;
    count[1] = 1;
    count[2] = 2;
    count[3] = 3;
    for(int i = 4; i <= n; i++) { 
        int ans = i;
        for(int j = 1; j <= i/2; j++) { 
            int k = i - (j * j); 
            if(k >= 0) 
                ans = min(ans, count[k] + 1);
        }
        count[i] = ans;
    } 
    return count[n];
} 
*/