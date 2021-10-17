#include <iostream>
using namespace std;

int ThreeCycle(int **edges,int n){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(edges[i][j] == 1){
                for(int k=0; k<n; k++){
					if(edges[i][k] == 1 && edges[j][k] == 1)
                        count++;
                }
            }
        }
    }
    return count;
}


int main() {
    // Write your code here
    int n,m;
    cin >> n >> m;
    int **edges = new int*[n];
    
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
            edges[i][j] = 0;
    }
    
    for(int i=0; i<m; i++){
        int f;
        int s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int ans = ThreeCycle(edges,n);
    cout << ans/6;
}