#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> umap;
    int maxlen = 0;
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=i;j<n;j++){
            curr += arr[j];
            if(curr == 0)
                maxlen = max(maxlen,j-i+1);
        }
    }
    return maxlen;
}
// OR 



int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> freq;
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (m < i + 1) {
                m = i + 1;
            }
        } 
        else if (freq.count(arr[i]) > 0) {
            if (m < i - freq[arr[i]]) {
                 m = i - freq[arr[i]];
            }
        } 
        else {
            freq[arr[i]] = i;
        }
    }
    return m;
}