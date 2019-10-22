// Write an efficient algorithm that searches for a value in an m x n matrix.
// Consider the following matrix:
// 
//  [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// 
// Given target = 3, return 1 ( 1 corresponds to true )

// Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

int binary_search(vector<int> A,int val){
    int low=0;
    int high=A.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[mid]==val)
            return 1;
        else if(A[mid]<val)
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m =  A.size();
    int flag=0;
    int row = 0;
    for(int i=0;i<m;i++){
        int n =A[i].size()-1; 
        if(B>=A[i][0] && B<=A[i][n]){
            row=i;
            break;
        }
    }
    // cout<<row<<" breaa";
    flag = binary_search(A[row],B);
    return flag;
}

