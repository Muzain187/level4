#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int>q;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){ // only one for is required
        q.push(arr[i]);
        pq.push(arr[i]);
    }
    int counter=0;
    while(!pq.empty()){
         if(arr[q.front()] == pq.top()){
            q.pop();
        	pq.pop();
         	counter+=1;
            k--;
            if(counter == k){
                return counter+1;
            }
        }
        else{
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
        // if(q.front()==pq.top()){
        //     if(k==0){
        //         return counter+1;
        //     }
        //     else{
        //         counter++;
        //         q.pop();
        //         pq.pop();
        //         k--;
        //     }
        // }
        // else{
        //     q.push(q.front());
        //     q.pop();
        //     if(k==0){
        //         k=q.size()-1;
        //     }
        //     else{
        //         k--;
        //     }
        // }
    return counter;
    
    }
