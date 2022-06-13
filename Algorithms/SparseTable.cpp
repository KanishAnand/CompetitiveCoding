#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define len(x) (int)(x.length())
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

int n;
vector<int> v;
int logn = 20;
vector<vector<int>> minSparseTable;

void build() {
    for (int i = 0; i < n; i++) {
        minSparseTable[i][0] = v[i];
    }

    for (int j = 1; j <= logn; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            minSparseTable[i][j] = min(minSparseTable[i][j - 1], minSparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = log2(R - L + 1);
    int mn = min(minSparseTable[L][j], minSparseTable[R - (1 << j) + 1][j]);
    return mn;
}

void solve() {
    int a;
    cin >> n;
    minSparseTable.resize(n + 2, vector<int>(logn + 2));

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    build();
    query(1, 2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}