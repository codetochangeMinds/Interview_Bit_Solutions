// Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 
// 2 indices i and j such that A[i] - A[j] = k, i != j.
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Try doing this in less than linear space complexity.
int Solution::diffPossible(vector<int> &A, int B) {
    int i=0;
    int j=1;
    // use two pointer to traverse the array
    while(i!=A.size()-1 && j!=A.size()){
        if(A[j]-A[i]==B && i!=j)
            return 1;
        else if(A[j]-A[i]>B)
            i++;
        else
            j++;
    }
    return 0;
}

