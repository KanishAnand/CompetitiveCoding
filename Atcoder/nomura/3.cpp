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
    lli n, a;
    cin >> n;
    vector<lli> v;

    for (lli i = 0; i < n + 1; i++) {
        cin >> a;
        v.pb(a);
    }

    lli ans = 0;
    lli flag = 0;
    lli curr = 1;

    for (lli i = 0; i < n; i++) {
        if (v[i] > curr) {
            flag = 1;
            break;
        }
        ans += curr;
        curr -= v[i];
        curr *= 2;
    }

    if (v[n] > curr) {
        flag = 1;
    }

    if (flag == 1) {
        cout << "-1" << endl;
        return;
    }

    lli val = v[n];
    lli p, beg = 0;

    while (1) {
        p = curr - val;
        lli q = (curr + 1) / 2;
        if (p <= q) {
            ans -= beg * p;
            break;
        } else {
            ans -= q * beg;
            curr -= q;
            beg++;
        }
    }

    cout << ans + val << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}