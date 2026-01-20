#include <cstdio>
#include <vector>

using std::vector;

class WeightedQuickUnionUF {
private:
    vector<int> parent;
    vector<int> sz;
    int cnt;

public:
    WeightedQuickUnionUF(int n) : parent(n), sz(n, 1), cnt(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int count() const { return cnt; }

    int find(int p) const {
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool connected(int p, int q) const { // O(logn)
        return find(p) == find(q);
    }
    
    void unite(int p, int q) { // O(logn)
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }

        if (sz[rootP] < sz[rootQ]) {
            parent[rootP] = rootQ;
            sz[rootQ] += sz[rootP];
        } else {
            parent[rootQ] = rootP;
            sz[rootP] += sz[rootQ];
        }
        cnt--;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    WeightedQuickUnionUF uf(n);

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
