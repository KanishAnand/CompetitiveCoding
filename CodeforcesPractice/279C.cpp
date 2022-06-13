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
    lli n, m, a;
    cin >> n >> m;
    vector<lli> v, cnt(n + 2, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (lli i = 1; i < n - 1; i++) {
        if (v[i - 1] > v[i] && v[i + 1] > v[i]) {
            cnt[i] = 1;
        }
    }
    for (lli i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }

    lli l, r;

    for (lli i = 0; i < m; i++) {
        cin >> l >> r;
        if (r - l <= 1) {
            cout << "Yes" << endl;
        } else {
            if (cnt[r - 2] - cnt[l - 1] >= 1) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
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