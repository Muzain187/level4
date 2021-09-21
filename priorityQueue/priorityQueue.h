#include<bits/stdc++.h>
using namespace std;

class priorityQueue{
    vector<int> pq;

    public:
    priorityQueue(){

    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty)
            return 0;
        else{
            return pq[0];
        }
    }
};