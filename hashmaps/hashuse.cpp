#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    // create the map
    unordered_map<string,int> ourmap;
    //string is key and int is our value 
    ourmap["a"] = 97;
    ourmap["b"] = 100;

    cout<<ourmap["a"]<<endl;

    cout<<ourmap.count("a")<<endl;
    string key;
    cout<<"Enter Key to find whether it is exist or not ";
    cin>>key;
    if(ourmap.count(key) > 0)
        cout<<"Key is present in hash "<<ourmap.count(key)<<endl;
    else
        cout<<"Key is not present in hash"<<endl;



}