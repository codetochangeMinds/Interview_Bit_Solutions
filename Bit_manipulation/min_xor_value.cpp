// Given a array find the min xor value 
// that can be obtained after applying the 
// xor bit operation on the pair of elements. 

// Given an array of N integers, find the pair of integers in the array which have minimum 
// XOR value. Report the minimum XOR value.


int Solution::findMinXor(vector<int> &A) {
    int min = INT_MAX;
    int size = A.size();
    // O(n^2) Approach
    // for(int i=0;i<size;i++){
    //     for(int j=i+1;j<size;j++){
    //         int xor_val = A[i]^A[j];
    //         // cout<<xor_val<<" ";
    //         if(xor_val<min)
    //             min = xor_val;
    //     }
    // }
    // return min;
    
    // O(nlogn) approach
    sort(A.begin(),A.end());
    for(int i=1;i<size;i++){
        int xor_val = A[i]^A[i-1];
        if(xor_val<min)
            min = xor_val;
    }
    return min;
}

