long long int count(int n, int s, vector<vector<long long int>>&dp){
    // base case
    if(n==0)
        return (s==0);
    // return if already calculated or the value
    // is available in the memoization table
    if(dp[n][s]!=-1)
        return dp[n][s];
    // if(s==0){
    //     dp[n][s]=1;
    //     return dp[n][s];
    // }
    // handle the case for the all remaining digits
    long long int ans=0;
    for(int i=0;i<=9;i++){
        if(s-i>=0)
           ans+=count(n-1,s-i,dp)%1000000007; 
        else 
            break;
    }
    dp[n][s]=ans%1000000007;
    return dp[n][s]%1000000007;
}

int Solution::solve(int A, int B) {
    long long int sol=0;
    // dp array initialization  
    vector<vector<long long int>> dp;
    for(int i=0;i<A;i++){
        vector<long long int> temp;
        for(int j=0;j<B;j++){
          temp.push_back(-1);
        }
        dp.push_back(temp);
    }
    // handle the case for the starting digit
    for(int i=1;i<=9;i++){
      if(B-i>=0)
        sol+=count(A-1,B-i,dp)%1000000007;
    }
  return sol%1000000007;
}

