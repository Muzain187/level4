#include <iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> dfs(int** graph, int n, int sv, int ev, bool* visited)
{
    if(sv == ev)
    {
        vector<int> ans;
        ans.push_back(sv);
        //ans.push_back(ev);
        
        return ans;
    }
    
    vector<int> ans;
    visited[sv] = true;
    for(int i=0; i<n; i++)
    {
        if(graph[sv][i] == 1)
        {
            if(visited[i])
                continue;
          
            ans = dfs(graph, n, i, ev, visited);
            if(ans.size() != 0)
            {
            	ans.push_back(sv);
                return ans;
            }
            
        }
    }
    return ans;
}



int main() 
{
    // Write your code here
    int v,e;
    cin>>v>>e;
    
    int** graph = new int*[v];
    for(int i=0 ;i<v; i++)
    {
        graph[i] = new int[v];
        
        for(int k=0; k<v; k++)
        {
            graph[i][k] = 0;
        }
    }
    
    
    for(int i=0; i<e; i++)
    {
        int p,q;
        cin>>p>>q;
        
        graph[p][q] = 1;
        graph[q][p] = 1;
    }
    
    int sv,ev;
     cin>>sv>>ev;
    bool* visited = new bool[v];
    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }
    vector<int> ans = dfs(graph, v, sv, ev, visited);
	for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}

/*
stack<int> Stack;

void getPath(int **edges,int n,int sv,int ev,int *visited){
    visited[sv] = 1;
    Stack.push(sv);
    
    if(sv == ev){
        while(Stack.size() != 0){
        	cout<< Stack.top() << " ";
        	Stack.pop();
    	}
        return;
    }
    
    for(int i=0; i<n; i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i])
            getPath(edges,n,i,ev,visited);
    }
}


int main() {
    // Write your code here
	int V, E;
  	cin >> V >> E;


  	int **edges=new int*[V];
  //intialization
  	for(int i=0;i<V;i++){
    	edges[i]=new int[V];
    	for(int j=0;j<V;j++)
      		edges[i][j]=0;
  	}

  	for(int i=0;i<E;i++){
    	int a,b;
    	cin>>a>>b;
    	edges[a][b]=1;
    	edges[b][a]=1;
  	}

     int s,e;
     cin>>s>>e;
     int* visited=new int[V];
     for(int i=0;i<V;i++)
    	visited[i]=0;
    
    getPath(edges,V,s,e,visited);
    
}
*/