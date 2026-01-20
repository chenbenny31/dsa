#include <cstdio>
#include <vector>

using std::vector;

class UF {
private:
    vector<int> id;
    vector<int> rank;
    int cnt;

public:
    UF(int n): id(n), rank(n, 1), cnt(n) {
        for(int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    int count() const { return cnt; }

    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]]; // path compression by halving
            p = id[p];
        }
        return p;
    }

    bool connected(int p, int q) { // O(log*(n))
        return find(p) == find(q);
    }

    void unite(int p, int q) { // O(log*(n))
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }

        if (rank[rootP] < rank[rootQ]) {
            id[rootP] = rootQ;
        } else if (rank[rootP] > rank[rootQ]) {
            id[rootQ] = rootP;
        } else {
            id[rootQ] = rootP;
            rank[rootP]++;
        }
        cnt--;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    UF uf(n);

    int p, q;
    while (scanf("%d %d", &p, &q) == 2) {
        if (uf.connected(p, q)) {
            continue;
        }
        uf.unite(p, q);
        printf("%d %d\n", p, q);
    }
    printf("%d components\n", uf.count());
    return 0;
}
