#include <cstdio>
#include <vector>

using std::vector;

vector<int> sieve(int n) { // O(nloglogn)
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) { // starting i * i: all k * i (k < i) have been marked
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> primes = sieve(n);
    printf("%d primes up to %d\n", (int)primes.size(), n);
    for (int p : primes) {
        printf("%d ", p);
    }
    printf("\n");
    return 0;
}
