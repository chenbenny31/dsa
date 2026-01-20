#include <cstdio>
#include <vector>

using std::vector;

class QuickUnionUF {
private:
    vector<int> parent;
    int cnt;

public:
    QuickUnionUF(int n) : parent(n), cnt(n) {
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

    bool connected(int p, int q) const { // O(n)
        return find(p) == find(q);
    }

    void unite(int p, int q) { // O(n)
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        parent[rootP] = rootQ;
        cnt--;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    QuickUnionUF uf(n);

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
