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
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli input(lli n, vector<lli> &ve);
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
    lli n, a, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<lli> v, redd, blue;
        redd.resize(n + 2, 0);
        blue.resize(n + 2, 0);

        v.pb(0);
        fr(i, 0, 2 * n) {
            cin >> a;
            v.pb(a);
        }

        map<lli, lli> mpr, mpb;
        lli var = -1;
        lli cnt = 0, reddc = 0, bluec = 0;

        for (lli i = 2 * n; i > n; i--) {
            if (v[i] == 1) {
                reddc++;
                lli valu = min(bluec, reddc);
                redd[cnt] = reddc - valu;
                blue[cnt] = bluec - valu;
            }
            if (v[i] == 2) {
                bluec++;
                lli valu = min(bluec, reddc);
                redd[cnt] = reddc - valu;
                blue[cnt] = bluec - valu;
            }
            if (reddc == bluec) {
                var = cnt + 1;
                continue;
            }
            if (reddc > bluec) {
                mpr[redd[cnt]] = cnt + 1;
            } else {
                mpb[blue[cnt]] = cnt + 1;
            }
            ++cnt;
        }
        reddc = 0, bluec = 0;
        lli ans = 2 * n;
        if (var == n) {
            ans = n;
        }

        for (lli i = 1; i <= n; i++) {
            if (v[i] == 1) {
                reddc++;
            }
            if (v[i] == 2) {
                bluec++;
            }
            lli pp = 1e9;
            if (reddc > bluec) {
                lli val = mpb[reddc - bluec];
                if (val == 0) {
                    continue;
                }
                pp = i + val;
            } else if (reddc < bluec) {
                lli val = mpr[bluec - reddc];
                if (val == 0) {
                    continue;
                }
                pp = i + val;
            } else {
                if (var != -1) {
                    pp = i + var;
                } else {
                    pp = i;
                }
            }
            pp = 2 * n - pp;
            if (pp < ans) {
                ans = pp;
            }
        }
        cout << ans << endl;
    }
    rt;
}