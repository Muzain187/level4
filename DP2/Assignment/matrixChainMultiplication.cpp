#include<climits>
int matrixChainMultiplication(int *arr,int i,int j){
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    for (k = i; k < j; k++)
    {
        count = matrixChainMultiplication(arr, i, k)
            	+ matrixChainMultiplication(arr, k+1 , j)
                + arr[i - 1] * arr[k] * arr[j];
 
        if (count < min)
            min = count;
    }

    return min;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    // return matrixChainMultiplication(arr,1,n-1);
    
    int m[n+1][n+1];
 
    int i, j, k, L, q;
 
    /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */
 
    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n];
}