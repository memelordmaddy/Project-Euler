// find the largest palindrome made from the product of two 3-digit numbers.
#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(long long int n){
    int rev = 0;
    int temp = n;
    while(temp > 0){
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == n;
}
int main()
{long long m=0; 
    for(int i=100; i<1000; i++){
        for(int j=100; j<1000; j++){
            if(is_palindrome(i*j)){
                if(i*j>m){
                    m=i*j;
                }
            }
        }
    }
    cout<<m;
    
}