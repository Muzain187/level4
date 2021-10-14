#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **edges,int n,int sv,bool *visited){
    cout << sv <<endl;
    visited[sv] = true;

    for(int i=0; i<n; i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1){
            if(visited[i])
                continue;
            printDFS(edges,n,i,visited);
        }
    }
}

void printBFS(int **edges,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front << endl;
        for(int i=0; i<n; i++){
            if(i == front)
                continue;
            if(edges[front][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    // delete []visited;
}

void BFS(int **edges,int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    for(int i=0; i<n; i++){
        if(!visited[i])
            printBFS(edges,n,i,visited);
    }
    delete []visited;
}
void DFS(int **edges,int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    for(int i=0; i<n; i++){
        if(!visited[i])
            printDFS(edges,n,i,visited);
    }
        
    delete []visited;
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

    // bool *visited = new bool[n];
    // for(int i=0; i<n; i++)
    //     visited[i] = false;
    // printDFS(edges,n,0,visited);//print the 2d matrix 
    cout<<"BFS"<<endl;
    BFS(edges,n);
    cout<<"DFS"<<endl;
    DFS(edges,n);

}