//  Find the product abc of the pythagorian triplet such that a+b+c=1000
#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    vector<int> divisors_of_500;
    for(int i=1; i*i<500; i++)
    {
        if(500%i==0)
        {
            divisors_of_500.push_back(i);
            divisors_of_500.push_back(500/i);
        }
    }
    for(int i=0; i<divisors_of_500.size(); i++)
    {
        int k=500/divisors_of_500[i];
        for(int j=1; j*j<divisors_of_500[i]; j++)
        {
            if(divisors_of_500[i]%j==0 && gcd(j, divisors_of_500[i]/j-j)==1 && 2*j*j>divisors_of_500[i])
            {
               int n=j;
               int m=divisors_of_500[i]/j-j;
               cout<<k*(n*n-m*m)<<" "<<k*(2*m*n)<<" "<<k*(m*m+n*n)<<endl;
               cout<<k*k*k*(n*n-m*m)*(2*m*n)*(m*m+n*n)<<endl;
               return 0;
            }
        }
    }
}