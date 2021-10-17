#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> print_DFS(int **edges,int n,int sv,bool *visited,vector<int> &v){
    visited[sv] = true;
    
    v.push_back(sv);
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<n; i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i])
            print_DFS(edges,n,i,visited,v);
    }
    return v;
}


vector<vector<int>> DFS(int **edges,int n,vector<vector<int>> ans){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> v;
            ans.push_back(print_DFS(edges,n,i,visited,v));
        }
    }
    return ans;
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
    
    vector<vector<int>> ans;
    
    vector<vector<int>> output = DFS(edges,n,ans);
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }
}