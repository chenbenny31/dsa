#include <cstdio>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

pair<vector<int>, vector<int>> linear_sieve(int n) { // O(n)
    vector<int> spf(n + 1, 0);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        // for each i, mark i * prime where prime <= spf[i] -> each num is only marked once by its smallest prime
        for (int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
    return {primes, spf};
}

int main() {
    int n;
    scanf("%d", &n);
    auto [primes, spf] = linear_sieve(n); // c++17
    for (int p : primes) {
        printf("%d ", p);
    }
    printf("\n");
}
