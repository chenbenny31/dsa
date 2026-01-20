#include <cstdio>
#include <vector>

using std::vector;

class QuickFindUF {
private:
    vector<int> id;
    int cnt;

public:
    QuickFindUF(int n) : id(n), cnt(n) {
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    int count() const { return cnt; }

    int find(int p) const { return id[p]; }

    bool connected(int p, int q) const { // O(1)
        return id[p] == id[q];
    }

    void unite(int p, int q) { // O(n)
        int pID = id[p];
        int qID = id[q];
        if (pID == qID) {
            return;
        }
        for (int i = 0; i < (int)id.size(); i++) { // id.size() return size_t
            if (id[i] == pID) {
                id[i] = qID;
            }
        }
        cnt--;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    QuickFindUF uf(n);

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
