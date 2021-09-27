#include<queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    
    for(int i=0; i<n; i++){
        
        if(maxpq.empty() && minpq.empty()){
            maxpq.push(arr[i]);
            // cout<<maxpq.top()<<endl;
        }
        
        else if(maxpq.empty())
            maxpq.push(arr[i]);
        else if(minpq.empty())
            minpq.push(arr[i]);
        
        else{
            if(minpq.top() < maxpq.top()){
                int tempmax = maxpq.top();
                int tempmin = minpq.top();
                maxpq.pop();
                minpq.pop();
                maxpq.push(tempmin);
                minpq.push(tempmax);
            }
            
        	if(arr[i] > maxpq.top())
            	minpq.push(arr[i]);
            else
                maxpq.push(arr[i]);
            
            if(maxpq.size() - minpq.size() >= 2){
                if(maxpq.size() > minpq.size()){
                    int ele = maxpq.top();
                    maxpq.pop();
                    minpq.push(ele);
                }
                else{
                    int ele = minpq.top();
                    minpq.pop();
                    maxpq.push(ele);
                }       
            }
        }
//         if(maxpq.size()==1 && minpq.size()==1){
            
            
//         }
        
        if(maxpq.size() == minpq.size()){
            int med = (maxpq.top() + minpq.top())/2;
            cout<<med<<" ";
        }
        else{
//             if(maxpq.top() > minpq.top()){
//                 int maxtemp = maxpq.top();
//                 int mintemp = minpq.top();
                
//                 int temp = maxtemp;
//                 maxtemp = mintemp;
//                 mintemp = temp;
//                 maxpq.pop();
//                 minpq.pop();
//                 maxpq.push(mintemp);
//                 minpq.push(maxtemp);
//             }
            
            if(maxpq.size() > minpq.size()){
//                 if(maxpq.top() > minpq.top()){
//                 int maxtemp = maxpq.top();
//                 int mintemp = minpq.top();
                
//                 // int temp = maxtemp;
//                 // maxtemp = mintemp;
//                 // mintemp = temp;
//                 maxpq.pop();
//                 minpq.pop();
//                 maxpq.push(mintemp);
//                 minpq.push(maxtemp);
//             	}
                cout<<maxpq.top()<<" ";
            }
            else
                cout<<minpq.top()<<" "; 
        }
                
        
    }
    
}