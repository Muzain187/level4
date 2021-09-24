#include<vector>
#include<queue>
using namespace std;
vector<int> kSmallest(int arr[], int n, int k) {
  
    priority_queue<int> pq;
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
    
    for(int i=k; i<n; i++){
        int max = pq.top();
        if(arr[i] < max){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    vector<int> A;
    while(pq.size() != 0){
        A.push_back(pq.top());
        pq.pop();
    }
    return A;
}