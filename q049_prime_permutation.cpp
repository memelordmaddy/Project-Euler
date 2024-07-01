// find a four digit prime number such that two othe rnumber obtained by permuting its digit are also prime and they form an AP
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> primes;
    vector<bool> is_prime(10000, true);
    is_prime[0] = false;

    // Sieve of Eratosthenes to find all primes up to 10000
    for (long long int i = 1; i < 10000; i++) {
        if (is_prime[i]) {
            primes.push_back(i + 1);
            for (long long int j = 2 * (i + 1) - 1; j < 10000; j += i + 1) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 168; i < primes.size(); i++) {
        int a, b, c, d;
        d = primes[i] % 10;
        c = (primes[i] / 10) % 10;
        b = (primes[i] / 100) % 10;
        a = (primes[i] / 1000) % 10;

        set<int> s;
        s.insert(primes[i]);
        s.insert(a * 1000 + c * 100 + b * 10 + d);
        s.insert(c * 1000 + b * 100 + a * 10 + d);
        s.insert(c * 1000 + a * 100 + b * 10 + d);
        s.insert(b * 1000 + a * 100 + c * 10 + d);
        s.insert(b * 1000 + c * 100 + a * 10 + d);

        vector<int> aba;
        for (int x : s) {
            if (is_prime[x - 1] && x > 1000) {
                aba.push_back(x);
            }
        }
        if(aba.size() < 3) continue;
        sort(aba.begin(), aba.end());

        bool foundAP = false;
        for (int j = 0; j < aba.size() - 2; j++) {
            for (int k = j + 1; k < aba.size() - 1; k++) {
                for (int l = k + 1; l < aba.size(); l++) {
                    if (aba[k] - aba[j] == aba[l] - aba[k]) {
                        foundAP = true;
                        cout << "AP found: " << aba[j] << ", " << aba[k] << ", " << aba[l] << endl;
                    }
                }
            }
        }
        
        if (foundAP) {
            cout << "Prime corresponding to AP: " << primes[i] << endl;
        }
    }

    return 0;
}
