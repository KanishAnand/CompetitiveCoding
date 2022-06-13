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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli k, n;
    string st;
    cin >> st >> k;
    n = st.length();

    vector<vector<lli>> precalc(n + 2, vector<lli>(n + 2, 0));
    for (lli i = 0; i < n; i++) {
        for (lli j = i; j < n; j++) {
            lli beg = i, end = j, val = 0;
            while (beg < end) {
                if (st[beg] != st[end]) {
                    val++;
                }
                beg++;
                end--;
            }
            precalc[i][j] = val;
        }
    }

    lli inf = 1e5;
    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, inf));

    for (lli i = 0; i < n; i++) {
        dp[i][1] = precalc[0][i];
        for (lli p = 1; p <= k; p++) {
            for (lli j = 0; j < i; j++) {
                dp[i][p] = min(dp[i][p], dp[j][p - 1] + precalc[j + 1][i]);
            }
        }
    }

    lli mn = inf, no;
    for (lli i = 1; i <= k; i++) {
        if (dp[n - 1][i] < mn) {
            mn = dp[n - 1][i];
            no = i;
        }
    }

    cout << mn << endl;
    // cout << no << endl;
    vector<lli> v;

    for (lli i = n - 1; i >= 0;) {
        // cout << mn << " " << no << " " << i << endl;
        if (no == 1) {
            v.pb(i);
            v.pb(0);
            break;
        }
        for (lli j = 0; j < i; j++) {
            if (dp[j][no - 1] + precalc[j + 1][i] == mn) {
                v.pb(i);
                v.pb(j + 1);
                mn -= precalc[j + 1][i];
                no--;
                i = j;
                break;
            }
        }
    }

    reverse(all(v));

    for (lli i = 0; i < sz(v) - 1; i += 2) {
        string tmp = "";
        for (lli j = v[i]; j <= v[i + 1]; j++) {
            tmp += st[j];
        }
        lli beg = 0, end = len(tmp) - 1;
        while (beg < end) {
            if (tmp[beg] != tmp[end]) {
                tmp[end] = tmp[beg];
            }
            beg++;
            end--;
        }
        cout << tmp;
        if (i != sz(v) - 2) {
            cout << "+";
        }
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}