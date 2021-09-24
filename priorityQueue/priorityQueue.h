#include<bits/stdc++.h>
using namespace std;


//Min heap
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
    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;
    }
};

//Max heap
#include<vector>
class PriorityQueue_MaxHeap {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue_MaxHeap() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size()-1;
        
        while(childIndex > 0){
        	int parentIndex = (childIndex-1)/2;
            
            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
            // parentIndex = (childIndex-1)/2;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty())
            return 0;
        return pq.at(0);
    }

    int removeMax() {
        // Implement the removeMax() function here
        
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int pi=0;

        int lci=(2*pi+1),rci=(2*pi+2);
        while(lci < pq.size()){
            int maxIndex = pi;
            
            if(pq[lci] > pq[maxIndex])
                maxIndex = lci;
            if(rci<pq.size() && pq[rci] >= pq[maxIndex])
                maxIndex = rci;

            if(pi == maxIndex)
                break;
            
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[pi];
            pq[pi] = temp;

            pi = maxIndex;
            lci=(2*pi)+1;
        	rci=(2*pi)+2;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};