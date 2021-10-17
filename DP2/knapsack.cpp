/*int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    //base case
    if( n == 0)
        return 0;
    if(maxWeight == 0 )
        return 0;
    
    if(weights[0] > maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight);
    
    
    //if 1st element is considered
    int a = knapsack(weights+1,values+1,n-1,maxWeight-weights[0]) + values[0];
    //dont consider 1st element
    int b = knapsack(weights+1,values+1,n-1,maxWeight);
    
    return max(a,b);
}*/
int knapsack(int *weights, int *values, int n, int maxWeight,int *arr)
{
	//write your code here
    //base case**********************************************************************************************************************************************************************************************************************************************************************************************************
        return 0;
    
    if(weights[0] > maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight,arr);
    
    if(arr[0] != -1)
        return arr[0];
    
    //if 1st element is considered
    int a = knapsack(weights+1,values+1,n-1,maxWeight-weights[0],arr) + values[0];
    //dont consider 1st element
    int b = knapsack(weights+1,values+1,n-1,maxWeight,arr);
    
    arr[0] = max(a,b);
    
    return max(a,b);
}
int knapsack(int *weights, int *values, int n,int maxWeight){
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++)
        arr[i] = -1;
    return knapsack(weights,values,n,maxWeight,arr);
}
