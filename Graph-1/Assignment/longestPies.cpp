

int DFS(vector<vector<int>> &cake,int i,int j,int n,bool **visited){
    visited[i][j] = true;
    
    //4 cases
    int count = 0;
    if(i-1 >=0 && cake[i-1][j] == 1 && !visited[i-1][j])
        count += DFS(cake,i-1,j,n,visited);
    
    if(i+1 < n && cake[i+1][j] == 1 && !visited[i+1][j])
        count += DFS(cake,i+1,j,n,visited);
    
    if(j-1 >=0 && cake[i][j-1] == 1 && !visited[i][j-1])
        count += DFS(cake,i,j-1,n,visited);
    
    if(j+1 < n && cake[i][j+1] == 1 && !visited[i][j+1])
        count += DFS(cake,i,j+1,n,visited);
    
    return count + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    bool **visited = new bool*[n];
    for(int i=0; i<n; i++){
        visited[i] = new bool[n];
        for(int j=0; j<n; j++)
            visited[i][j] = false;
    }
    int Max = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                int ans = DFS(cake,i,j,n,visited);
                Max = max(ans,Max);
            }
        }
    }
    return Max;
}