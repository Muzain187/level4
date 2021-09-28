#include<iostream>
#include<unordered_map>
#include<string>
#include<map>
using namespace std;

int main(){
    // unordered_map<string,int> map;
    map<string,int> Map;
    Map["ayyub"] = 23;
    Map["muzain"] = 20;
    Map["fazil"] = 3;
    Map["bushra"] = 26;
    Map["anwar"] = 29;

    map<string,int> :: iterator it = Map.begin();
    while(it != Map.end()){
        cout<<"Key "<<it->first<<" Value "<<it->second<<endl;
        it++;
    }
    map<string,int> :: iterator it2 = Map.find("muzain");
    cout<<it2->first<<" "<<it2->second;
}