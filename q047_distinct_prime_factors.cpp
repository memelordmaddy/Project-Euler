// find the first four consecutive integers with exactly four distinct prime factors
#include<bits/stdc++.h>
using namespace std;

int main()
{
    const int MAXN = 1000000;
    vector<int> primes(MAXN + 1, 0);
    for(int i = 2; i <= MAXN; i++)
    {
        if(primes[i] == 0)
        {
            for(int j = i; j <= MAXN; j += i)
            {
                primes[j]++;
            }
        }
    }
    for(int i = 1; i <= MAXN - 3; i++)
    {
        if(primes[i] == 4 && primes[i+1] == 4 && primes[i+2] == 4 && primes[i+3]==4)
        {
            cout << "First number: " << i << endl;
            break;
        }
    }

    return 0;
}
