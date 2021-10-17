/*int editDistance(string s1, string s2) {
	// Write your code here
    
    //base case 
    if(s1.size() == 0 || s2.size() == 0)
        return max(s1.size(),s2.size());
    
    //if first index is same
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1),s2.substr(1)) ;
    
    //else we have 3 operations
    // Insert, Delete and update
    
    int x = editDistance(s1.substr(1),s2) + 1;
    int y = editDistance(s1,s2.substr(1)) + 1;
    int z = editDistance(s1.substr(1),s2.substr(1)) + 1;
    
    return min(x,min(y,z));
    
}*/
int editDistance(string s1, string s2,int **arr) {
    //base case 
    int m = s1.size();
    int n = s2.size();
    
    if(m == 0 || n == 0)
        return max(m,n);
    
    //if first index is same
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1),s2.substr(1),arr) ;
    
    if(arr[m][n] != -1)
        return arr[m][n];
    
    //else we have 3 operations
    // Insert, Delete and update
    
    int x = editDistance(s1.substr(1),s2,arr) + 1;
    int y = editDistance(s1,s2.substr(1),arr) + 1;
    int z = editDistance(s1.substr(1),s2.substr(1),arr) + 1;
    
    int output = min(x,min(y,z));
    arr[m][n] = output;
    
    return output;
}
int editDistance(string s1, string s2){
    int m = s1.size(),n = s2.size();
    int **arr = new int*[m+1];
    for(int i=0; i<= m; i++){
        arr[i] = new int[n+1];
    	for(int j = 0; j <= n; j++) {
			arr[i][j] = -1;
		}
    }
    return editDistance(s1,s2,arr);
}

