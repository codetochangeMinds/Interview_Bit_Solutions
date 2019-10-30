// write a function to merge the two sorted list

void Solution::merge(vector<int> &A, vector<int> &B) {
    int i=0;
    int j=0;
    vector<int> sol;
    while(i!=A.size() && j!=B.size()){
        if(A[i]<=B[j]){
            sol.push_back(A[i]);
            i++;
        }
        else{
            sol.push_back(B[j]);
            j++;
        }
    }
    while(i!=A.size()){
        sol.push_back(A[i]);
        i++;
    }
    while(j!=B.size()){
        sol.push_back(B[j]);
        j++;
    }
    A=sol;
}

