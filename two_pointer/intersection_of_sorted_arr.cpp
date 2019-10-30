// Find the intersection of two sorted arrays.
// OR in other words,
// Given 2 sorted arrays, find all the elements 
// which occur in both the arrays.
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i=0;
    int j=0;
    vector<int> sol;
    while(i<A.size() && j<B.size()){
        while(A[i]<B[j] && i<A.size()){
            i++;
        }
        // cout<<i;
        if(A[i]==B[j]){
            sol.push_back(B[j]);
            i++;
            j++;
        }
        else
            j++;
    }
    // cout<<"hello";
    return sol;
}

