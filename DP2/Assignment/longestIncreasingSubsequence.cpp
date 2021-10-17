int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    
    //create an output array of size n
    int *output = new int[n];
    output[0] = 1;
    for(int i=1; i<n; i++){
        output[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(arr[j] >= arr[i])
                continue;
            else{
                int possibleAns = output[j]+1;
                if(output[i] < possibleAns)
                    output[i] = possibleAns;
            }
        }
    }
    int best = 0;
    for(int i=0; i<n; i++){
        if(best < output[i])
            best = output[i];
    }
    return best;
}