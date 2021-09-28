#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
// int binarySearch(int *arr,int si,int ei,int x){
//     if(ei >= si){
//         int mid = (si+ei)/2;
//         if(arr[mid] == x)
//             return mid;
//         if(mid <= x){
//             return binarySearch(arr,mid+1,ei,x);
//         }
//         else if(mid > x){
//             return binarySearch(arr,si,mid-1,x);
//         }
//     }
//     return -1;
// }

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    //sort(arr, arr + n);
    // int count=0;
    // for(int i=n-1; i>=0; i--){
    //     for(int j=i-1; j>=0; j--){
    //     	if(arr[i]-arr[j] == k)
    //         	count++;
    //     }
    // }
    // return count;
    
    // int count=0;
    // for(int i=0;i<n;i++){
    //     if(binarySearch(arr,i,n-1,arr[i]+k) != -1)
    //         count++;
    // }
    // return count;
    unordered_map<int,int> umap;
    int count=0;
    for(int i=0; i<n; i++)
    {
    	int x = arr[i]+k ;
        int y = arr[i]-k;
//         != ourmap.end()
        if(umap.find(x) != umap.end())
        {
            count += umap[x];
        }
        if(umap.find(y) != umap.end() && k!=0)
        {
            count += umap[y];
        }
        umap[arr[i]]++;
    }
    
/*    for(int i=0;i<n;i++){
         if(umap.find(arr[i]+k) != umap.end()){
             count += umap[arr[i]+k];
             umap[arr[i]+k] = 0;
         }
         if(umap.find(arr[i]-k) != umap.end()){
             count += umap[arr[i]-k];
            umap[arr[i]-k] = 0;   
         }
         umap[arr[i]] = 0;
     
     }*/
   
    return count;
}

/*#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> m;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int complement=arr[i]+k;
        count+=m[complement];
        if(k!=0){
            complement=arr[i]-k;
            count+=m[complement];
        }
        m[arr[i]]++;
    }
    return count;
}
*/