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
    string s, t;
    cin >> s;
    cin >> t;

    set<lli> A, B;

    for (lli i = 0; i < n; i++) {
        if (s[i] == '1' && t[i] == '0') {
            A.insert(i);
        }
        if (s[i] == '0' && t[i] == '1') {
            B.insert(i);
        }
    }

    if (A.size() != B.size()) {
        cout << "-1" << endln;
        return;
    }

    lli ans = 0;

    while (sz(A) != 0 || sz(B) != 0) {
        vector<lli> tmp;
        lli flag = 0;
        lli ind = 0;
        while (1) {
            // first A;
            if (flag == 0) {
                auto it = A.lower_bound(ind);
                if (it == A.end()) {
                    break;
                }
                lli val = *it;
                ind = val + 1;
                tmp.pb(val);
                flag = 1;
            } else if (flag == 1) {
                auto it = B.lower_bound(ind);
                if (it == B.end()) {
                    break;
                }
                lli val = *it;
                ind = val + 1;
                tmp.pb(val);
                flag = 0;
            }
        }

        if (flag == 1 && tmp.size() > 0) {
            tmp.pop_back();
        }

        lli val1 = tmp.size();

        vector<lli> tmp2;
        flag = 1;
        ind = 0;

        while (1) {
            // first A;
            if (flag == 0) {
                auto it = A.lower_bound(ind);
                if (it == A.end()) {
                    break;
                }
                lli val = *it;
                ind = val + 1;
                tmp2.pb(val);
                flag = 1;
            } else if (flag == 1) {
                auto it = B.lower_bound(ind);
                if (it == B.end()) {
                    break;
                }
                lli val = *it;
                ind = val + 1;
                tmp2.pb(val);
                flag = 0;
            }
        }

        if (flag == 0 && tmp2.size() > 0) {
            tmp2.pop_back();
        }

        lli val2 = tmp2.size();

        if (val1 >= val2) {
            if (val1 > 0) {
                ans++;
            }
            lli ff = 0;
            for (lli i = 0; i < tmp.size(); i++) {
                if (ff == 0) {
                    A.erase(tmp[i]);
                    ff = 1;
                } else {
                    B.erase(tmp[i]);
                    ff = 0;
                }
            }
        } else {
            lli ff = 1;
            if (val2 > 0) {
                ans++;
            }
            for (lli i = 0; i < tmp2.size(); i++) {
                if (ff == 0) {
                    A.erase(tmp2[i]);
                    ff = 1;
                } else {
                    B.erase(tmp2[i]);
                    ff = 0;
                }
            }
        }
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}