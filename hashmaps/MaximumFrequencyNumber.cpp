#include<unordered_map>
#include<vector>
int highestFrequency(int arr[], int n) {

 vector<int> v;
    unordered_map<int,int> m;
	for(int i=0; i<n; i++){
        if(m.count(arr[i]) == 0){
        	m[arr[i]] = 1;
            v.push_back(arr[i]);
        }
        else
            m[arr[i]] = m[arr[i]] + 1;
    }
    
	int freq = m.count(v[0]);
    int value = v[0];
    
    for(int i=0; i<v.size(); i++){
        if(m[v[i]] > freq){
            freq = m[v[i]];
            value = v[i];
        }
    }
    return value;

}