int Solution::solve(const vector<int> &A) {
	// the time complexity for the code is O(n^2) 
    int n = A.size();
    int arr[n];
    // sort the array 
    for(int i=0;i<n;i++)
        arr[i]=A[i];
    sort(arr,arr+n);
    if(n<=2)
        return n;
    // create a 2d table, dp[i][j] denotes the length of the 
    // sequence with its first two elements as the arr[i] and arr[j]
    int dp[n][n];
    for(int i=0;i<n;i++)
        dp[i][n-1]=2;
    // itialize the length of the lap as 2
    int lap=2;
    for(int j=n-2;j>=1;j--){
        int i=j-1, k=j+1;
        while(i>=0 && k<n){
            if(arr[i]+arr[k]==2*arr[j]){
                dp[i][j]=dp[j][k]+1;
                lap = max(lap,dp[i][j]);
                i--; k++;
            }
            else if(arr[i]+arr[k]<2*arr[j]){
                k++;
            }
            else{
                dp[i][j]=2;
                i--;
            }
        }
        while(i>=0){
            dp[i][j]=2;
            i--;
        }
    }
    return lap;
}

