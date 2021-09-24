void heapSort(int arr[], int n) {
    // Write your code
    //build heap
    int i=1;
    while(i < n){
        int childIndex = i;
        while(childIndex > 0 ){
            int pi = (childIndex-1)/2;
            if(arr[childIndex] < arr[pi]){
                int temp = arr[childIndex];
                arr[childIndex] = arr[pi];
                arr[pi] = temp;
            }
            else
                break;
            childIndex = pi;
        }
    	i++;
    }
    
    //sort 
    
    int size = n;
    while(size > 1){
        int temp = arr[size-1];
        arr[size-1] = arr[0];
        arr[0] = temp;
        size--;
        
   		int pi=0;
        int lci=(2*pi)+1;
        int rci=(2*pi)+2;
      
        while(lci < size) {
			int minIndex = pi;
			if(arr[minIndex] > arr[lci]) {
				minIndex = lci;
			}
			if(rci <size && arr[rci] < arr[minIndex]) {
				minIndex = rci;
			}
			if(minIndex == pi) {
				break;
			}
			int temp = arr[minIndex];
			arr[minIndex] = arr[pi];
			arr[pi] = temp;
		
			pi = minIndex;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
    }
    
//     int size=n;
    

//         // int minIndex=pi;
//     while(size > 1){
//         int temp = arr[size-1];
//     	arr[size-1] = arr[0];
//     	arr[0] = temp;
//     	size--;
//         int pi=0;
//         while(pi < size){
//             int minIndex = pi;
//             int lci=(2*pi)+1,rci=(2*pi+2);
//             if(lci < size){
//                 if(arr[lci] < arr[minIndex])
//                     minIndex = lci;
//                 if(rci<size && arr[rci] < arr[minIndex])
//                     minIndex = rci;
//             }
//             else
//                 break;
//         	if(minIndex == pi)
//             	break;

//             int temp2 = arr[pi];
//             arr[pi] = arr[minIndex];
//             arr[minIndex] = temp2;
            
//             pi = minIndex;
//         }
    // }
    
}