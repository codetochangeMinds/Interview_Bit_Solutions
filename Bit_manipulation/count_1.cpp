// find the number of the set bit 
// in the binary representation of the int A
int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count =0;
    while(A!=0){
        if(A%2==1)
            count++;
        A= A/2;
    }
    // cout<<" ";
    return count;
}

