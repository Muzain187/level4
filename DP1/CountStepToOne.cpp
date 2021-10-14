#include<climits>
int countStepsToOne(int n)
{
	//Write your code here
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 0;
    for(int i=2;i<n+1;i++){
        int x = arr[i-1];
        int y = INT_MAX;
        int z = INT_MAX;
        
        if(i%2 == 0)
            y = arr[i/2];
        if(i%3 == 0)
            z = arr[i/3];
        
        int output = min(x,min(y,z));
        arr[i] = output + 1;
    }
    return arr[n];
}