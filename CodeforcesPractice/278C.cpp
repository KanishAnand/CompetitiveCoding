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
vector<lli> king;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

lli merge(lli a, lli b) {
    king[b] = king[a];
}

void solve() {
    lli n, a, m, k, b;
    cin >> n >> m;
    king.resize(m + 2);
    vector<lli> vis(m + 2, 0);

    for (lli i = 1; i <= m; i++) {
        king[i] = i;
    }

    lli zero = 0;

    for (lli i = 0; i < n; i++) {
        cin >> k;
        if (k == 0) {
            zero++;
            continue;
        }

        cin >> a;
        vis[a] = 1;
        lli p = find(a);
        for (lli j = 0; j < k - 1; j++) {
            cin >> b;
            vis[b] = 1;
            lli q = find(b);
            if (p != q) {
                merge(p, q);
            }
        }
    }

    lli ans = 0;

    for (lli i = 1; i <= m; i++) {
        if (vis[i] == 0) {
            continue;
        }
        a = find(i);
        if (a == i) {
            ans++;
        }
    }

    if (ans != 0) {
        ans--;
    }
    cout << ans + zero << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}