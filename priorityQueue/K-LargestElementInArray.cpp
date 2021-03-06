#include<queue>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<k; i++)
        pq.push(input[i]);
    
    for(int i=k; i<n; i++){
        int max = input[i];
        if(max > pq.top()){
            pq.pop();
            pq.push(max);
        }
    }
    
    vector<int> A;
    while(!pq.empty()){
        A.push_back(pq.top());
        pq.pop();
    }
	return A;
}
