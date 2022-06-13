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
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
    lli n, a, k;
    cin >> n >> k;
    lli ok = k;
    vector<lli> pos, neg;
    lli zero = 0;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            zero = 1;
        }
        if (a >= 0) {
            pos.pb(a);
        } else {
            neg.pb(abs(a));
        }
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());

    lli beg1 = 0, beg2 = 0;
    lli cnt = 0;
    lli flag = 1;

    while (k > 0) {
        if (beg1 == sz(pos)) {
            beg2++;
            cnt++;
            k--;
        } else if (beg2 == sz(neg)) {
            if (pos[beg1] == 0) {
                flag = 0;
            }
            beg1++;
            k--;
        } else {
            if (pos[beg1] >= neg[beg2]) {
                if (pos[beg1] == 0) {
                    flag = 0;
                }
                beg1++;
            } else {
                beg2++;
                cnt++;
            }
            k--;
        }
    }

    // if (flag == 0) {
    //     cout << "0" << endl;
    //     return;
    // }

    lli ans = 1;
    if (cnt % 2 == 0) {
        for (lli i = 0; i < beg1; i++) {
            ans *= pos[i];
            ans %= MOD;
        }
        for (lli i = 0; i < beg2; i++) {
            ans *= neg[i];
            ans %= MOD;
        }
        cout << ans << endl;
        return;
    }

    lli ind1 = -1, ind2 = -1;
    if (cnt % 2 == 1) {
        if (beg2 != 0 && beg1 < sz(pos)) {
            ind1 = beg1;
        }
        if (beg1 != 0 && beg2 < sz(neg)) {
            ind2 = beg2;
        }
        long double rem1 = 1, add1 = 1;
        long double rem2 = 1, add2 = 1;
        long double val1 = 0, val2 = 0;

        if (ind1 != -1) {
            add1 = pos[beg1];
            rem1 = neg[beg2 - 1];
            val1 = add1 / rem1;
        }
        if (ind2 != -1) {
            add2 = neg[beg2];
            rem2 = pos[beg1 - 1];
            if (pos[beg1 - 1] == 0) {
                ind2 = -1;
            } else {
                val2 = add2 / rem2;
            }
        }

        if (ind1 != -1 || ind2 != -1) {
            long double diff = val1 - val2;
            if (diff >= 0) {
                beg1++;
                beg2--;
            } else {
                beg1--;
                beg2++;
            }
            lli ans = 1;
            for (lli i = 0; i < beg1; i++) {
                ans *= pos[i];
                ans %= MOD;
            }
            for (lli i = 0; i < beg2; i++) {
                ans *= neg[i];
                ans %= MOD;
            }
            cout << ans << endl;
            return;
        }
    }

    if (zero == 1) {
        cout << "0" << endl;
        return;
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    beg1 = 0, beg2 = 0;
    k = ok;

    while (k > 0) {
        if (beg1 == sz(pos)) {
            beg2++;
            k--;
        } else if (beg2 == sz(neg)) {
            beg1++;
            k--;
        } else {
            if (pos[beg1] <= neg[beg2]) {
                beg1++;
            } else {
                beg2++;
            }
            k--;
        }
    }

    ans = -1;
    ans += MOD;
    for (lli i = 0; i < beg1; i++) {
        ans *= pos[i];
        ans %= MOD;
    }
    for (lli i = 0; i < beg2; i++) {
        ans *= neg[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}
