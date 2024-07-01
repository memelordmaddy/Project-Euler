// find the sum all even fibonacci numbers belwo four million
#include<iostream>
using namespace std;
int main()
{
    unsigned long long int sum=2;
    long long a=1; 
    long long b=2;
    while(b<4000000)
    {
        long long c=a+b;
        if(c%2==0)
        {
            sum+=c;
        }
        a=b;
        b=c;
    }
    cout<<sum;

}