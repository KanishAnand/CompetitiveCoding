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
    string st;
    cin >> st;
    lli n = st.length();
    lli beg = 1, end = n;
    lli ans = end;

    vector<vector<lli>> pref(n + 2, vector<lli>(26, 0));
    for (lli i = 0; i < n; i++) {
        if (i != 0) {
            pref[i] = pref[i - 1];
        }
        pref[i][st[i] - 'a']++;
    }

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli flag = 0;
        for (lli i = 0; i < 26; i++) {
            flag = 0;
            for (lli j = 0; j <= n - mid; j++) {
                if ((st[j] - 'a') != i &&
                    pref[j + mid - 1][i] - pref[j][i] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }

        if (flag == 0) {
            ans = mid;
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}