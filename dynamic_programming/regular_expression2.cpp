// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).
// isMatch("aa","a") → 0
// isMatch("aa","aa") → 1
// isMatch("aaa","aa") → 0
// isMatch("aa", "a*") → 1
// isMatch("aa", ".*") → 1
// isMatch("ab", ".*") → 1
// isMatch("aab", "c*a*b") → 1


int Solution::isMatch(const string A, const string B) {
    int size_of_A = A.length();
    int size_of_B = B.length();
    
    // to reduce the space complexity we have 
    // taken the size of the dp array as 2*size_of_pattern
    // because we only need the 2 rows at any point of time
    bool dp[2][size_of_B+1];
    
    // case of empty string A or empty string B
    dp[0][0]=true;
    dp[1][0]=false;
    // base case
    for(int j=1;j<=size_of_B;j++){
        if(B[j-1]=='*')
            dp[0][j]=dp[0][j-2];
        else
            dp[0][j]=false;
    }
    
    // fill the table 
    // prefix is our subproblems and thus we will 
    // start filling our table from smaller prefix
    // i,j is used to iterate in the text and the pattern resp
    // if(text[i]== pattern[j] or pattern[j]=='.')
    //  recurse on the smaller prefix
    // else if(pattern[j]=='*')
    // then it may be case that * represents empty string so,
    // recurse on the smaller prefix whose length is 2 less 
    //  but it may be the case that * may represent the non zero 
    // occurence of the character preceding to the *
    // if that is the case then check the text[i] and pattern[j-1]
    // either they both should be same or the pattern[j-1]=='.' i.e 
    // wild character, now we would check whether text[i] and pattern[j]
    // is a match or text[i-1] and pattern[j] is a match 
    // CAUTION: Just we are iterating from i=1 but string indexing 
    // starts from 0, so in this above mentioned approach we should replace
    // i by i-1 while indexing in the string. 
    for(int i=1;i<=size_of_A;i++){
        for(int j=1;j<=size_of_B;j++){
            if(A[i-1]==B[j-1] || B[j-1]=='.')
                dp[1][j]=dp[0][j-1];
            else if(B[j-1]=='*'){
                dp[1][j]=dp[1][j-2];
                if(A[i-1]==B[j-2] || B[j-2]=='.'){
                    dp[1][j] = dp[1][j] || dp[0][j];
                }
            }
            else
                dp[1][j]=false;
        }
        // copy the value to row0 that we will 
        // be needing in the next iteration
        for(int j=0;j<=size_of_B;j++){
            dp[0][j]=dp[1][j];
        }
    }
    
    // return the value for the longest prefix of A and B
    if(dp[1][size_of_B])
        return 1;
    else
        return 0;
}
