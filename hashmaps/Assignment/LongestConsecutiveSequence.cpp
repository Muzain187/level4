#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> m;
    for(int i=0; i<n; i++){
        m[arr[i]] = true;
    }
    vector<int> output;
    
    for(int i=0; i<n; i++){
        
        if(!m.count(arr[i]-1)){
            
            int num = arr[i];
            vector<int> v;
            v.push_back(num);
            
            while(m.count(++num) > 0){
                v.push_back(num);
    
            }
            
            if(v.size() > output.size()){
                
                if(output.size()!=0)
                	output.clear();
                
                for(int i=0;i<v.size();i++)
                    output.push_back(v[i]);
            }
        }
    }
    return output;
    
}