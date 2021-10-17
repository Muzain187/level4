#include<vector>
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	int i, w;
      vector<vector<int>> K(n + 1, vector<int>(maxWeight + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= maxWeight; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] +
                                K[i - 1][w - weights[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][maxWeight];
}