
#define MAX 1005
int solve(string S,string T,int m,int n){
  // int m = strlen(S), n = strlen(T);

	// declaring 2D array of m + 1 rows and
	// n + 1 columns dynamically
	int dp[m+1][n+1];

	// T string is empty
	for (int i = 0; i <= m; i++)
		dp[i][0] = 1;

	// S string is empty
	for (int i = 0; i <= n; i++)
		dp[0][i] = MAX;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char ch = S[i-1];
			int k;
			for (k = j-1; k >= 0; k--)
				if (T[k] == ch)
					break;

			// char not present in T
			if (k == -1)
				dp[i][j] = 1;
			else
			dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
		}
	}

	int ans = dp[m][n];
	if (ans >= MAX)
		ans = -1;

	return ans;
}


int solve(string s, string v) {
    // Write your code here
    return solve(s,v,s.length(),v.length());
}