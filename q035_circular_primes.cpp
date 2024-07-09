// a circular prime is a prime whose digits on circular rotation generate primes. find the numbe rof circular primes below one million
#include<bits/stdc++.h>
using namespace std;
int main()
{
    const long int MAXN = 1000000;
    vector<bool> primes(MAXN + 1, true);
    vector<long int> p;
    primes[0]=false; primes[1]=false;
    for(long int i = 2; i <= MAXN; i++)
    {
        if(primes[i])
        {p.push_back(i);
            for(long int j = i*2; j <= MAXN; j += i)
            {
                primes[j]= false;
            }
        }
    }
    long count=0;
    for(long int i: p)
    {   
        int no_digits= floor(log10(i))+1;
        if(no_digits==1)
        {
            count++;
            continue;
        }
        else
        {
            for(int j=1; j<no_digits; j++)
            { long int k=i;
                i= i/10 + (i%10)*pow(10, no_digits-1);
                
                if(!primes[i])
                {   i=k;
                    break;
                }
                if(j==no_digits-1)
                {   //cout<<i<<" ";
                    i=k;
                    count++;
                }
                
            }
        }
    }
    cout<<count<<endl;
}