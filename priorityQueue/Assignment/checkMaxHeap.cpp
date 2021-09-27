bool isMaxHeap(int arr[], int n) {
    // Write your code here
    if(n == 0)
        return true;
    int pi=0;
    int lci = 2*pi+1;
    int rci = lci + 1;
    if(lci < n){
        int maximum = pi;
        
        if(arr[lci] > arr[maximum])
            maximum = lci;
        if(arr[rci] > arr[maximum])
            maximum = rci;
        if(pi != maximum)
            return false;
        else
            return isMaxHeap(arr+1,n-1);
    }
    return true;
}