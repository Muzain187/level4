int maxMoneyLooted(int *arr, int n,int *a)
{
	//Write your code here
    if(n <= 0)
        return 0;
    
    if(a[n] != -1)
        return a[n];
    
    int b = maxMoneyLooted(arr+1,n-1,a);
    int c = arr[0] + maxMoneyLooted(arr+2,n-2,a);
    
    int output = max(b,c);
    a[n] = output;
    
    return output;
}
int maxMoneyLooted(int *arr,int n){
    int *a = new int[n+1];
    for(int i=0; i<=n; i++)
        a[i] = -1;
    return maxMoneyLooted(arr,n,a);
}