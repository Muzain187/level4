#include<string>
/*
Time complexity: O(N * M)
Space complexity: O(N * M)
where N and M are the rows and columns respectively of the board
*/
int validPoint(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool dfs(vector<vector<char>> &board, vector<vector<bool>> &used, string &word, int x,int y, int wordIndex, int n, int m) {
    if (wordIndex == 11) {
        return true;
    }
    used[x][y] = true;
    bool found = false;
    int dXdY[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for (int i = 0; i < 8; ++i) {
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if (validPoint(newX, newY, n, m) && board[newX][newY] == word[wordIndex] &&!used[newX][newY]) {
            found = found | dfs(board, used, word, newX, newY, wordIndex + 1, n, m);
        }
    }
    used[x][y] = false;
    return found;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    bool foundPath = false;
    string word = "CODINGNINJA";
    vector<vector<bool>> used(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                foundPath = dfs(board, used, word, i, j, 1, n, m);
                if (foundPath) break;
            }
        }
        if (foundPath) break;
    }
    return foundPath;
}










//******************************************** OR **************************************************

bool hasPath_DFS(vector<vector<char>> &board,int n,int m,int ri,int ci,string str,bool **visited){
    bool flag = false;
    visited[ri][ci] = true;
    
    if(str.length() == 0){
        // flag = true;
        return true;
    }
    
    if(ri-1 >=0 && ci-1 >= 0){
        if(board[ri-1][ci-1] == str[0] && !visited[ri-1][ci-1])
            flag = flag || hasPath_DFS(board,n,m,ri-1,ci-1,str.substr(1),visited);
    }
    if(ri-1 >=0 && ci >= 0){
        if(board[ri-1][ci] == str[0] && !visited[ri-1][ci])
            flag = flag || hasPath_DFS(board,n,m,ri-1,ci,str.substr(1),visited);
    }
    if(ri-1 >=0 && ci+1 >= 0 && ci+1 < m){
        if(board[ri-1][ci+1] == str[0] && !visited[ri-1][ci+1])
            flag = flag || hasPath_DFS(board,n,m,ri-1,ci+1,str.substr(1),visited);
    }
    if(ri >=0 && ci-1 >= 0){
        if(board[ri][ci-1] == str[0] && !visited[ri][ci-1])
            flag = flag || hasPath_DFS(board,n,m,ri,ci-1,str.substr(1),visited);
    }
    if(ri >=0 && ci+1 >= 0 && ci+1 < m){
        if(board[ri][ci+1] == str[0] && !visited[ri][ci+1])
            flag = flag || hasPath_DFS(board,n,m,ri,ci+1,str.substr(1),visited);
    }
    if(ri+1 >=0 && ci-1 >= 0 && ri+1 < n){
        if(board[ri+1][ci-1] == str[0] && !visited[ri+1][ci-1])
            flag = flag || hasPath_DFS(board,n,m,ri+1,ci-1,str.substr(1),visited);
    }
    if(ri+1 >=0 && ci >= 0 && ri+1 < n){
        if(board[ri+1][ci] == str[0] && !visited[ri+1][ci])
            flag = flag || hasPath_DFS(board,n,m,ri+1,ci,str.substr(1),visited);
    }
    if(ri+1 >=0 && ci+1 >= 0 && ci+1 < m && ri+1 < n){
        if(board[ri+1][ci+1] == str[0] && !visited[ri+1][ci+1])
            flag = flag || hasPath_DFS(board,n,m,ri+1,ci+1,str.substr(1),visited);
    }
    
    visited[ri][ci] = false;
    return flag;
}

void initialize(bool **visited,int N,int M){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    string c = "CODINGNINJA";
    // int i,j;
    
    bool **visited=new bool*[n];
    for(int i=0; i<n; i++){
        visited[i]=new bool[m];
    }
    initialize(visited,n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'C'){
                bool ans = hasPath_DFS(board,n,m,i,j,c.substr(1),visited);
                if(ans)
                    return true;
                // initialize(visited,n,m);
            }
        }
    }
   	return false;
}