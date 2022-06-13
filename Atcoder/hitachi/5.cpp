/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 10;

vector<int> g[N];

void bipartition(int u, int p, vector<vector<int>>& bipartitions, int id);

int main() {
    fast_cin();
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<vector<int>> numbers(3);
    for (int i = 1; i <= n; ++i) {
        numbers[i % 3].pb(i);
    }
    vector<vector<int>> bipartitions(2);
    bipartition(1, 0, bipartitions, 0);
    if (bipartitions[0].size() >= bipartitions[1].size()) {
        swap(bipartitions[0], bipartitions[1]);
    }
    vector<int> p(n + 1);
    if (bipartitions[0].size() >= numbers[1].size() and
        bipartitions[1].size() >= numbers[2].size()) {
        for (int i = 0; i < 2; ++i) {
            for (auto& u : bipartitions[i]) {
                if (!numbers[i + 1].empty()) {
                    p[u] = numbers[i + 1].back();
                    numbers[i + 1].pop_back();
                } else {
                    p[u] = numbers[0].back();
                    numbers[0].pop_back();
                }
            }
        }
    } else {
        for (int i = 0; i < 2; ++i) {
            for (auto& u : bipartitions[i]) {
                for (int j = 0; j < 3; ++j) {
                    if (!numbers[j].empty()) {
                        p[u] = numbers[j].back();
                        numbers[j].pop_back();
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

void bipartition(int u, int p, vector<vector<int>>& bipartitions, int id) {
    bipartitions[id].pb(u);
    for (auto& v : g[u]) {
        if (v != p) {
            bipartition(v, u, bipartitions, id ^ 1);
        }
    }
}
