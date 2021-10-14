/*
long staircase(int n,int *arr){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    
    if(arr[n] != -1)
        return arr[n];
    
    long x = staircase(n-1,arr);
    long y = staircase(n-2,arr);
    long z = staircase(n-3,arr);
    
    arr[n] = x+y+z;
    
    return x+y+z;
}*/

long staircase(int n)
{
	//Write your code here
	long *arr = new long[n+1];
    // for(int i=0;i<n+1;i++)
    //     arr[i] = -1;
    // return staircase(n,arr);
    if(n == 0)
        return 1;
    if(n == 1 || n == 2)
        return n;
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i< n+1; i++){
       arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}