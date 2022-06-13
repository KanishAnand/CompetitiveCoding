#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a, m, v, b;
    cin >> n >> m >> v;
    if (m < n - 1) {
        cout << "-1" << endl;
        return;
    }

    lli val = (n * (n - 1)) / 2;
    val -= (n - 2);
    if (m > val) {
        cout << "-1" << endl;
        return;
    }

    vector<pair<lli, lli>> edg;

    for (lli i = 1; i < n; i++) {
        edg.pb({i, i + 1});
        m--;
    }

    lli beg = 1, fin = 3;

    while (m > 0) {
        if (fin == n) {
            beg++;
            fin = beg + 2;
        }
        edg.pb({beg, fin});
        fin++;
        m--;
    }

    for (lli i = 0; i < edg.size(); i++) {
        a = edg[i].first;
        b = edg[i].second;
        if (a == n - 1) {
            a = v;
        } else if (a == v) {
            a = n - 1;
        }
        if (b == n - 1) {
            b = v;
        } else if (b == v) {
            b = n - 1;
        }
        cout << a << " " << b << endln;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}