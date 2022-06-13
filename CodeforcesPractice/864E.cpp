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

struct store {
    lli d, t, p, ind;
};

bool compare(struct store a, struct store b) {
    if (a.d < b.d) {
        return true;
    } else if (a.d == b.d) {
        return a.t < b.t;
    }
    return false;
}

void solve() {
    lli n, a, mx = -1;
    cin >> n;
    vector<struct store> v;

    for (lli i = 0; i < n; i++) {
        struct store tmp;
        cin >> tmp.t >> tmp.d >> tmp.p;
        tmp.ind = i + 1;
        if (tmp.t < tmp.d) {
            mx = max(mx, tmp.d);
            v.pb(tmp);
        }
    }

    if (sz(v) == 0) {
        cout << "0" << endl;
        cout << "0" << endl;
        return;
    }

    sort(all(v), compare);
    vector<vector<vector<lli>>> dp(
        n + 2, vector<vector<lli>>(mx + 2, vector<lli>(2, 0)));

    dp[0][v[0].t][1] = v[0].p;
    lli ans = v[0].p;

    for (lli i = 1; i < sz(v); i++) {
        for (lli j = 0; j <= mx; j++) {
            if (j + v[i].t < v[i].d) {
                dp[i][j + v[i].t][1] =
                    max(dp[i][j + v[i].t][1], dp[i - 1][j][0] + v[i].p);
                ans = max(ans, dp[i][j + v[i].t][1]);
                dp[i][j + v[i].t][1] =
                    max(dp[i][j + v[i].t][1], dp[i - 1][j][1] + v[i].p);
                ans = max(ans, dp[i][j + v[i].t][1]);
            }
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
        }
    }

    cout << ans << endln;
    vector<lli> ind;
    for (lli i = sz(v) - 1; i >= 0; i--) {
        for (lli j = mx; j >= 0; j--) {
            if (dp[i][j][1] == ans) {
                ind.pb(v[i].ind);
                ans -= v[i].p;
                break;
            }
        }
        if (ans == 0) {
            break;
        }
    }

    reverse(all(ind));
    cout << sz(ind) << endln;
    for (lli i = 0; i < sz(ind); i++) {
        cout << ind[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}