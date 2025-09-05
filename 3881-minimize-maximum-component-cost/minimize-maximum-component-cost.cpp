#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);

        int components = n;
        if (k >= n) return 0;

        for (auto &e : edges) {
            if (unite(e[0], e[1])) {
                components--;
            }
            if (components <= k) {
                return e[2];
            }
        }
        return 0; // not possible
    }
};
