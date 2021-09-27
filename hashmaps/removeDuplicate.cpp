#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicate(int *arr,int size){
    unordered_map<int,bool> seen;
    vector<int> output;
    for(int i=0; i<size; i++){
        if(seen.count(arr[i]) > 0)
            continue;
        else{
            seen[arr[i]] = true;
            output.push_back(arr[i]);
        }
    }
    return output;
}

int main(){
    int arr[] = {0,1,1,2,2,3,2,3,4,1,5,2,6};
    vector<int> output = removeDuplicate(arr,13);
    for(int i=0; i<output.size(); i++)
        cout<<output[i]<<" ";
    cout<<endl;
}
