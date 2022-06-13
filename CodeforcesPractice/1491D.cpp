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
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli q, u, v;
    cin >> q;

    while (q--) {
        cin >> u >> v;

        if (v < u) {
            cout << "NO" << endl;
            continue;
        }

        lli uCnt = 0, vCnt = 0;
        vector<lli> uBits, vBits;
        for (lli i = 0; i <= 30; i++) {
            uCnt += u % 2;
            vCnt += v % 2;
            uBits.pb(u % 2);
            vBits.pb(v % 2);
            u /= 2;
            v /= 2;
        }

        if (vCnt > uCnt) {
            cout << "NO" << endl;
            continue;
        }

        lli flag = 1;
        for (lli i = 30; i >= 0; i--) {
            if (vBits[i] == 1 && uCnt == 0) {
                flag = 0;
                break;
            }
            if (vCnt > uCnt) {
                flag = 0;
                break;
            }
            if (vBits[i] == 1) {
                vCnt--;
            }
            if (uBits[i] == 1) {
                uCnt--;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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