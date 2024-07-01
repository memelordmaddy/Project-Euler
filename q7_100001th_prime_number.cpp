// find the 100001th prime number
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<long long int> primes;
    primes.push_back(2);
    while(primes.size()<10001)
    {
        for(long long int i=primes[primes.size()-1]+1; ; i++)
        {
            bool is_prime=true;
            for(int j=0; j<primes.size(); j++)
            {
                if(i%primes[j]==0)
                {
                    is_prime=false;
                    break;
                }
            }
            if(is_prime)
            {
                primes.push_back(i);
                break;
            }
        }
    }
    cout<<primes[10000];
}