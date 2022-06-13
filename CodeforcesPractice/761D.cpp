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
    lli n, a, l, r;
    cin >> n >> l >> r;
    vector<lli> va, vp, vb(n + 2);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        va.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        vp.pb(a);
    }

    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        v.pb({vp[i], va[i]});
    }

    sort(all(v));
    lli val = l - v[0].second, flag = 0;
    vb[1] = l;

    for (lli i = 1; i < n; i++) {
        lli p = v[i].second + val + 1;
        if (p <= r) {
            if (p >= l) {
                val++;
            } else {
                p = l;
                val = p - v[i].second;
            }
        } else {
            flag = 1;
            break;
        }

        vb[i + 1] = p;
    }

    if (flag == 1) {
        cout << "-1" << endl;
    } else {
        for (lli i = 0; i < n; i++) {
            cout << vb[vp[i]] << " ";
        }
        cout << endl;
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