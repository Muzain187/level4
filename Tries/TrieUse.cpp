#include<iostream>
#include"Tries.cpp"
#include<string>

using namespace std;
int main(){
    Trie t;
    t.insertWord("ashraf");
    t.insertWord("muzain");
    cout<<t.search("ashraf");

}