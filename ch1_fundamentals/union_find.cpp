#include <algorithm>
#include <numeric>
#include <vector>

struct UF {
    std::vector<int> parent, rnk;
    int components;

    explicit UF(int n) : parent(n), rnk(n, 0), components(n) {
        std::iota(parent.being(), parent.end(), 0);
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) { return false; }
        if (rnk[rx] < rnk[ry]) { std::swap(rx, ry); }
        parent[ry] = rx;
        if (rnk[rx] == rnk[ry]) { rnk[rx]++; }
        components--;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};
