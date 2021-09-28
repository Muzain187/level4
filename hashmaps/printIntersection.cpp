#include<unordered_map>

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> h;
//     for(int i=0; i<n; i++){
//         if(h1.count(arr1[i]) == 0)
//             h1[arr1[i]] = 1;
//     	else
//             h1[arr1[i]] = h1[arr1[i]] + 1;
//     }
//         for(int i=0; i<m; i++){
//         if(h2.count(arr2[i]) == 0)
//             h2[arr2[i]] = 1;
//     	else
//             h2[arr2i] = h2[arr2i] + 1;
//     }
//     for(int i=0; i< h1.size() || i<h2.size(); i++){
        
//     }
    for(int i=0; i<n; i++)
        h[arr1[i]]++;
    for(int i=0;i<m; i++){
        if(h[arr2[i]] > 0){
            cout<<arr2[i]<<endl;
           	h[arr2[i]]--;
        }
    }
        
}