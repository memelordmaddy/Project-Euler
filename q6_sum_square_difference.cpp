// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
#include<iostream>
using namespace std;
int main()
{
    long long s1=0, s2=0;
    for(int i=1; i<=100; i++){
        
        s1+=i*i;
    }
    s2 = 5050*5050;
    cout<<s2-s1;
}