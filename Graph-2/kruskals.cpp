#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
        int source;
        int destination;
        int weight;
};

int findParent(int v,int *parent){
    if(v == parent[v])
        return v;
    return findParent(parent[v],parent);
}
bool compare(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}

void kruskals(Edge *input,int n,int E){
    sort(input,input+E,compare);
    
    Edge *output = new Edge[n-1];
    
    int *parent = new int(n);
    for(int i=0; i<n; i++)
        parent[i] = i;
        
    int count = 0;
    int i = 0;
    while(count < n-1){
        Edge current = input[i];
        
        int sourceParent = findParent(current.source,parent);
        int destParent = findParent(current.destination,parent);
        
        if(sourceParent != destParent){
            output[count] = current;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    for(int i=0; i<n-1; i++){
        int v1 = output[i].source;
        int v2 = output[i].destination;
        int W = output[i].weight;
        
        if(v1 < v2){
            cout << v1 << " "<< v2 << " "<< W <<endl;
        }
        else
        	cout << v2 << " "<< v1 << " "<< W <<endl;
        
    }
        
}



int main() {
    // Write your code here
    int n,E;
    cin >> n >> E;
    
    Edge *input = new Edge[E];
    for(int i=0; i<E; i++){
        int s,d,w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }
    
    kruskals(input,n,E);
    
}