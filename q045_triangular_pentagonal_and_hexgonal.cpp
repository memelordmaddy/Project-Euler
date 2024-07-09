// find the first number after 40755 that is triangular, hexagonal, and pentagonal
// all alternate triangular numbers are hexagonal. Check if a triangular number is hexagonal
#include <iostream>
#include <cmath>

using namespace std;

bool is_square(long long int n) {
    int len_n = 0;
    long long int temp = n;
    
    while (temp > 0) {
        temp >>= 1;
        len_n++;
    }

    int k = (len_n - 1) / 2;
    long long int m = 1LL << k;
    long long int two_raised_to_i = 1LL << (k - 1);

    for (int i = k - 1; i >= 0; --i) {
        if ((m + two_raised_to_i) * (m + two_raised_to_i) <= n) {
            m += two_raised_to_i;
        }
        two_raised_to_i >>= 1;
    }

    return m * m == n;
}

long long int floor_sqrt(long long int n) {
    int len_n = 0;
    long long int temp = n;
    
    // Calculate bit length of n
    while (temp > 0) {
        temp >>= 1;
        len_n++;
    }

    int k = (len_n - 1) / 2;
    long long int m = 1LL << k;
    long long int two_raised_to_i = 1LL << (k - 1);

    for (int i = k - 1; i >= 0; --i) {
        if ((m + two_raised_to_i) * (m + two_raised_to_i) <= n) {
            m += two_raised_to_i;
        }
        two_raised_to_i >>= 1;
    }

    return m;
}

int main() {
    long long int k = 287;
    while (true) {  
        long long int a = 1 + 12 * k * (k + 1);
        if (is_square(a)) {
            if ((floor_sqrt(a) + 1) % 6 == 0) {
                cout<<k<<" ";
                cout << k * (k + 1) / 2 << endl;
                break;
            }
        }
        k += 2;
    }
    return 0;
}
