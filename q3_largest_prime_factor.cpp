// find the largest prime factor of 600851475143
#include<iostream>
using namespace std;
int main()
{
    long long int n = 600851475143;
    long long int i = 2;
    while(i * i < n){
        while(n % i == 0){
            n = n / i;
        }
        i++;
    }
    cout<<n;
    return 0;
}