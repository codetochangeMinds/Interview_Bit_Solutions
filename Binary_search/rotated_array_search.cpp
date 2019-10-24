// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

// You are given a target value to search. If found in the array, return its index, otherwise return -1.

// You may assume no duplicate exists in the array.


// the function find the pivot element
// pivot is the element which is greater than both 
// its neighboring element, by finding the pivot element 
// we can see the two sorted subarray i.e arr[0..pivot] 
// && arr[pivot+1 ... size-1]
int find_pivot(const vector<int> &A,int low, int high){
    int mid = low +(high-low)/2;
    while(low<=high){
        if(A[mid]>A[mid+1] && A[mid]>A[mid-1])
            return mid;
        else if(A[mid]<A[low])
            return find_pivot(A,low,mid-1);
        else
            return find_pivot(A,mid+1,high);
    }
    return -1;
}
// function to find the binary search using the recursive method
int binary_search(const vector<int> &A,int low, int high, int val){
    int mid = low +(high-low)/2;
    while(low<=high){
        if(A[mid]==val)
            return mid;
        else if(A[mid]<val)
            return binary_search(A,mid+1,high,val);
        else
            return binary_search(A,low,mid-1,val);
    }
    return -1; 
}

// function to search the target element in the rotated array or 
// the shifted array which was intially sorted. 
int Solution::search(const vector<int> &A, int B) {
    int size = A.size()-1;
    int pivot = find_pivot(A,0,size);
    if(pivot==-1){
        return binary_search(A,0,size,B);
    }
    else{
        int search_1 = binary_search(A,0,pivot,B);
        int search_2 = binary_search(A,pivot+1,size,B);
        if(search_1!=-1)
            return search_1;
        else
            return search_2;
    }
}

