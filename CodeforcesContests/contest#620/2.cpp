#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t, m;
    vector<string> v;
    vector<pair<lli, lli>> pairs;
    vector<lli> odd;
    cin >> n >> m;
    fr(i, 0, n) {
        string st;
        cin >> st;
        v.pb(st);
    }

    vector<lli> ind(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        if (ind[i] == 1) {
            continue;
        }
        // check this
        string ch = v[i];
        reverse(ch.begin(), ch.end());
        ind[i] = 1;
        lli flag = 0;
        for (lli j = 0; j < n; j++) {
            if (ind[j] == 1) {
                continue;
            }
            if (v[j] == ch) {
                ind[j] = 1;
                flag = 1;
                pairs.pb({i, j});
                break;
            }
        }
        if (flag == 0) {
            ind[i] = 0;
        }
    }

    fr(i, 0, n) {
        if (ind[i] == 0) {
            string ch = v[i];
            reverse(ch.begin(), ch.end());
            if (ch == v[i]) {
                odd.pb(i);
                ind[i] = 1;
                break;
            }
        }
    }

    lli cnt = 0;
    vector<string> ans;

    fr(i, 0, sz(pairs)) {
        ++cnt;
        ans.pb(v[pairs[i].first]);
    }
    if (sz(odd) != 0) {
        ++cnt;
        ans.pb(v[odd[0]]);
    }
    for (lli i = sz(pairs) - 1; i >= 0; i--) {
        ++cnt;
        ans.pb(v[pairs[i].second]);
    }

    cout << cnt * m << endl;
    fr(i, 0, sz(ans)) {
        cout << ans[i];
    }
    cout << endl;

    rt;
}
