#include <iostream>
#include<climits>
using namespace std;

int minimumDistance(int *distance,bool *visited,int n){
    int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}


void dijkstra(int **edges,int n){
    bool *visited = new bool[n];
    int *distance = new int[n];
    
    for(int i=0; i<n; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    
    distance[0] = 0;
    for(int i=0; i<n-1; i++){
        int u = minimumDistance(distance,visited,n);
        visited[u] = true;
        for(int j=0; j<n; j++){
           	if(edges[u][j] != 0 && !visited[j]){
                int current_distance = distance[u] + edges[u][j];
                if(distance[j] > current_distance)
                    distance[j] = current_distance;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        cout << i <<" " << distance[i] << endl;
    }
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
        int s,d,w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    
    dijkstra(edges,n);
}