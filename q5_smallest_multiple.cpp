//find the smallest number that is divisible by all numbers from 1 to 20
#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
long long int lcm(long long int a,long long  int b){
    return a*b/gcd(a, b);
}
int main()
{
   
    int lasagu=1;
    for(int i=1; i<=20; i++){
        lasagu=lcm(lasagu, i);
    }
    cout<<lasagu;
}