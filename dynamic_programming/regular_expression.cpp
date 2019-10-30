// Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

//     ’?’ : Matches any single character.
//     ‘*’ : Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

int Solution::isMatch(const string A, const string B) {
    int size_of_A = A.length();
    int size_of_B = B.length();
    
    // to reduce the space complexity we have 
    // taken the size of the dp array as 2*size_of_pattern
    // because we only need the 2 rows at any point of time
    bool dp[2][size_of_B+1];
    
    // case of empty string1 or empty string2
    dp[0][0]=true;
    dp[1][0]=false;
    // base case
    for(int j=1;j<=size_of_B;j++){
        if(B[j-1]=='*')
            dp[0][j]=dp[0][j-1];
        else
            dp[0][j]=false;
    }
    
    // fill the table 
    // prefix is our subproblems and thus we will 
    // start filling our table from smaller prefix
    // i,j is used to iterate in the text and the pattern resp
    // if(text[i]== pattern[j] or pattern[j]=='?')
    //  recurse on the smaller prefix
    // else if(pattern[j]=='*')
    // then * may represents empty sequence so check whether the 
    // text[i] and pattern[j-1] matches or 
    // it may represents a sequence of non zero length
    // so check whether the text[i-1] and the pattern[j] matches
    // if they matches then we can include that character in the *
    // CAUTION: Just we are iterating from i=1 but string indexing 
    // starts from 0, so in this above mentioned approach we should replace
    // i by i-1 while indexing in the string. 
    for(int i=1;i<=size_of_A;i++){
        for(int j=1;j<=size_of_B;j++){
            if(A[i-1]==B[j-1] || B[j-1]=='?')
                dp[1][j]=dp[0][j-1];
            else if(B[j-1]=='*')
                dp[1][j] = dp[0][j] || dp[1][j-1];
            else
                dp[1][j]=false;
        }
        for(int j=0;j<=size_of_B;j++){
            dp[0][j]=dp[1][j];
        }
    }
    
    // return the value for the longest prefix of A 
    // and B
    if(dp[1][size_of_B])
        return 1;
    else
        return 0;
}
