#include<iostream>
using namespace std;

void print(int **edges,int n,int sv,bool *visited){
    cout << sv;
    visited[sv] = true;

    for(int i=0; i<n; i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1){
            if(visited[i])
                continue;
            print(edges,n,i,visited);
        }
    }
}

int main(){
    int n,e;
    cout<<"Enter the noof Vertices and edges ";
    cin>>n>>e;

    //creating n*n 2d matrix;
    //initializing every data to zero
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
            edges[i][j] = 0;
    }

    //taking edges between every node
    for(int i=0; i<e; i++){
        int f;//first
        int s;//second
        cout<<"Enter two vertices ";
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    //for printing the graph

    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    print(edges,n,0,visited);//print the 2d matrix 

}
