// consider nim games with (a, 2a, 2c) number of sticks where a<= 2^30. find the number of instances where the first player looses.
// inorder for a^2a^2c =0 to occur, a should not have consecutive 1s in its binary representation. Hence the answer is the fibonacci series.
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    
    long long dp[30];
    dp[1]=2;
    dp[2]=3;
    for(int i=3; i<=30; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[30]<<endl;
}