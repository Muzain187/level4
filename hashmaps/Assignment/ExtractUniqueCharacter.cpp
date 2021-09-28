#include<unordered_map>
#include<string>
using namespace std;
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,bool> m;
    string s="";
    
    for(int i=0;i<str.length(); i++){
        if(m.count(str[i]) > 0)
            continue;
        else{
        	m[str[i]] = true;
            s += str[i];
        }
    }
	return s;
}