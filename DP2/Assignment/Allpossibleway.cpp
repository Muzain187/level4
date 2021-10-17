#include<math.h>
int getAllWays(int a,int b,int c){
    int val = a - pow(c,b);
    if(val == 0)
        return 1;
    if(val < 0)
        return 0;
    
    int ans = getAllWays(val,b,c+1) + getAllWays(a,b,c+1);
    return ans;
}

int getAllWays(int a, int b) {
	// Write your code here
    return getAllWays(a,b,1);
}