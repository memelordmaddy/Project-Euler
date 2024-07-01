// find the prime number which can be written as the sum of the most consecutive primes below one million
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> prime_sum;
    vector<bool> is_prime(1000000, true);
    is_prime[0]=false;
    long long prev=0;
    prime_sum.push_back(0);
    for(long long int i=1; prime_sum[prime_sum.size()-1]<1000000; i++)
    {
        if(is_prime[i])
        {
            prime_sum.push_back(prev + i+1);
            prev=prime_sum[prime_sum.size()-1];
            for(long long int j=2*(i+1)-1; j<1000000; j+=i+1)
            {
                is_prime[j]=false;
            }
        }
    }
    /*
    for(int i=0; i<prime_sum.size(); i++)
    {
        cout<<prime_sum[i]<<" ";
    }*/
    vector<pair<int, int>> visiting_order;
    for (int i = 0; i < prime_sum.size(); ++i) {
        for (int j = i + 1; j < prime_sum.size(); ++j) {
            visiting_order.push_back({i, j});
        }
    }
    sort(visiting_order.begin(), visiting_order.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return abs(a.first - a.second) > abs(b.first - b.second);
    });
    for (const auto& p : visiting_order)
     {
        int i = p.first;
        int j = p.second;
        if(abs(prime_sum[i]-prime_sum[j])<1000000 && is_prime[abs(prime_sum[i]-prime_sum[j])-1])
        {
            cout<<abs(prime_sum[i]-prime_sum[j]);
            // <<" "<<i<<" "<<j<<endl;
            break;
        }
    }
    return 0;
}