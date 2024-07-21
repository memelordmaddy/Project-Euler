// find the value of n<=1000000 for which n/phi(n) is maximum, where phi(n) denote the euler totient function
// n/phi(n) = pi (p/p-1) for all p|n and x/x-1 is a decreasing function
#include<bits/stdc++.h>  
using namespace std;
int main()
{
    long n=1000000;
    vector<bool> is_prime(n+1,true );
    is_prime[0]=is_prime[1]=false;  
    long long op=1;
    for(long i=2;i<=n ;i++)
    {
        if(is_prime[i])
        {   op*=i;
            if(op>n)
            {
                op/=i;
                break;
            }
            for(long j=i*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    }
    cout<<op;
    

}