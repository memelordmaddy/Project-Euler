// find the sum of squares of digits of a number, repeates unit it reaches 1 or 89. Find the number of numbers that reach 89 for numbers upto 10^7
#include<bits/stdc++.h>
using namespace std;
long long square_sum_of_digit(long long n)
{
    long long sum = 0;
    while(n>0)
    {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;

}
int main()
{
    vector<short> v(567, 0);
    long long count_1=1;
    long long count_89=1;
    v[0] = 0; 
    v[1] = 1;
    v[89] = 2;
    for(long long i=2; i<=567; i++)
    {   
        vector<long long> temp;
        if(v[i] == 0)
        {
            long long n = i;
            while(v[n] == 0)
            {   
                temp.push_back(n);
                
                n = square_sum_of_digit(n);
            }
            if(v[n] == 1)
            {
                for(auto j: temp)
                {
                    v[j] = 1;
                    count_1++;
                }
                
            }
            else if(v[n] == 2)
            {
                for(auto j: temp)
                {
                    v[j] = 2;
                     count_89++;
                }
               
            }
            
        }

    }
    for(int i=568; i<=10000000; i++)
    {
        if(v[square_sum_of_digit(i)] == 1)
        {
            count_1++;
        }
        else if(v[square_sum_of_digit(i)] == 2)
        {
            count_89++;
        }
    }
    cout<<count_89<<endl;
}