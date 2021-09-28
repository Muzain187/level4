
#include<unordered_map>
#include<vector>
int pairSum(int *arr, int n){

    unordered_map<int,int> ourmap;
    int count=0;
    for(int i=0; i<n; i++)
    {
    	int comp = -arr[i] ;

        if(ourmap.find(comp) != ourmap.end())
        {
            count += ourmap[comp];
        }
        ourmap[arr[i]]++;
    }
	return count;
}