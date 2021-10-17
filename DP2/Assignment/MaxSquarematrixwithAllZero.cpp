int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    int **dp = new int*[n];
    for (int i = 0; i < n; i++)
	{
		dp[i] = new int[m];
	}
    
    for(int j=0; j<m; j++){
        if(arr[0][j] == 1)
                dp[0][j] = 0;
        else
                dp[0][j] = 1;
    }
    for(int i=1; i<n; i++){
        if(arr[i][0] == 1)
                dp[i][0] = 0;
        else
                dp[i][0] = 1;
    }
    int max = 0;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == 1)
                dp[i][j] = 0;
            else{
                int a = dp[i-1][j-1];
                int b = dp[i][j-1];
                int c = dp[i-1][j];
                int ans = min(a,min(b,c)) + 1;
                dp[i][j] = ans;
                if(max < ans)
                    max = ans;
            }
        }
    }
    return max;
}
    