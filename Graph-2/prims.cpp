#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited,int *weight,int n){
    int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weight[i] < weight[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int **edges,int n){
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];
    
    for(int i=0; i<n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
	weight[0] = 0;
    for(int i=0; i<n-1; i++){
    
        	int a = findMinVertex(visited,weight,n);
            visited[a] = true;
            for(int j=0; j<n; j++){
              
                if(edges[a][j] != 0 && !visited[j]){
                    if(weight[j] > edges[a][j] ){
                        weight[j] = edges[a][j];
                        parent[j] = a;
                    }
                }
            }
    
    }
    for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << " "<< i << " " << weight[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}
}

int main() {
    // Write your code here
    int n,E;
    cin >> n >> E;
  	int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<E; i++){
        int s,d,w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    
    prims(edges,n);
}