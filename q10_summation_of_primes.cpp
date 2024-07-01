// find the sum of all the primes below two million.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<bool> a(2000000, true);
    a[0]=false;
    long long sum=0;
    for(int i=1; i<2000000; i++)
    {
        if(a[i])
        {
            sum+=i+1;
            for(long long int j=2*(i+1)-1; j<2000000; j+=i+1)
            {
                a[j]=false;
            }
        }
    }
    cout<<sum;
    
}