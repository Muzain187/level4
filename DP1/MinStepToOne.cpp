#include<climits>


int countMinStepsToOne(int n,int *arr){
    if(n <= 1)
		return 0;
    
    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    
    if(arr[n-1] != -1)
        x = arr[n-1];
    else
    	x = countMinStepsToOne(n-1,arr);
    
    if(n%2 == 0){
        if(arr[n%2] != -1)
            y = arr[n%2];
        else
    		y = countMinStepsToOne(n/2,arr);
        
    }
    if(n%3 == 0){
        if(arr[n%3] != -1)
            z = arr[n%3];
        else
        	z = countMinStepsToOne(n/3,arr);
    }
    arr[n] = min(x,min(y,z)) + 1;
    return arr[n];
}
//.

int countMinStepsToOne(int n)
{
	//Write your code here
    int *arr = new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i] = -1;
    }
    return countMinStepsToOne(n,arr);
    
    
}