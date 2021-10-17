#include <iostream>
using namespace std;

void Island_DFS(int **edges,int n,int sv,bool *visited){
    visited[sv] = true;
    for(int i=0; i<n; i++){
        
        if(i == sv)
            continue;
        
        if(edges[sv][i] == 1 && !visited[i])
            Island_DFS(edges,n,i,visited);
    }
}

int DFS(int **edges,int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    
    int island = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            island += 1;  
            Island_DFS(edges,n,i,visited);   
        }
    }
   return island;
}

int main() {
    // Write your code here
    int n,e;
    cin >> n >> e;
    
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
            edges[i][j] = 0;
    }
    
    for(int i=0; i<e; i++){
        int f;
        int s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int ans = DFS(edges,n);
    cout << ans;
}