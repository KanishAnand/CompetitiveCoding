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
    lli n, a;
    cin >> n;
    vector<vector<lli>> v;
    vector<lli> ind, ln;
    v.resize(n + 2);
    lli cnt = 0;

    fr(i, 0, n) {
        lli l;
        cin >> l;
        ln.pb(l);
        fr(j, 0, l) {
            cin >> a;
            v[i].pb(a);
        }
        lli mx = v[i][l - 1], flag = 0;

        for (lli j = l - 2; j >= 0; j--) {
            if (v[i][j] < mx) {
                flag = 1;
                break;
            } else {
                mx = v[i][j];
            }
        }
        if (flag == 1) {
            ++cnt;
        } else {
            ind.pb(i);
        }
    }
    lli ans = 0;

    ans += cnt * n;
    ans += (n - cnt) * cnt;
    vector<lli> st, st1;

    fr(i, 0, ind.size()) {
        lli val = ln[ind[i]];
        st1.pb(v[ind[i]][0]);
        st.pb(v[ind[i]][val - 1]);
    }

    sort(all(st));
    sort(all(st1));

    for (lli i = 0; i < st.size(); i++) {
        auto it = upper_bound(st1.begin(), st1.end(), st[i]);
        if (it != st1.end()) {
            lli val = st1.end() - it;
            ans += val;
        }
    }

    cout << ans << endl;
    rt;
}