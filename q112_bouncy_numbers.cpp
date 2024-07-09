// a bouncy number is a number whose digits are neither increasing nor decreasing. find the least number for which the proportion of bouncy numbers is exactly 99%
#include<bits/stdc++.h>
using namespace std;
bool is_increasing(long int n){
    string s = to_string(n);
    for(int i=0; i<s.size()-1; i++){
        if(s[i] > s[i+1]){
            return false;
        }
    }
    return true;
}
bool is_decreasing(long int n){
    string s = to_string(n);
    for(int i=0; i<s.size()-1; i++){
        if(s[i] < s[i+1]){
            return false;
        }
    }
    return true;
}
bool is_bouncy(long int n){
    return !is_increasing(n) && !is_decreasing(n);
}
int main()
{   long int count=0;
    long int i=0;
    while(1){
        i++;
        if(is_bouncy(i)){
            count++;
        }
        if(count*100 == i*99){
            cout<<i;
            break;
        }
    }

}