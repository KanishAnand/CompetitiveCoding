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
    lli n, m, a;
    cin >> n >> m;
    vector<vector<lli>> v(n + 2);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> a;
            v[i].pb(a);
        }
    }

    lli p = n / 2 + n % 2;
    lli q = m / 2 + m % 2;
    lli ans = 0;

    for (lli i = 0; i < p; i++) {
        for (lli j = 0; j < q; j++) {
            lli ii = n - 1 - i;
            lli jj = m - 1 - j;

            vector<lli> ch;
            ch.pb(v[i][j]);

            if (jj != j) {
                ch.pb(v[i][jj]);
            }
            if (i != ii) {
                ch.pb(v[ii][j]);
            }
            if (i != ii && j != jj) {
                ch.pb(v[ii][jj]);
            }

            lli mn = -1;
            for (lli i = 0; i < ch.size(); i++) {
                lli no = 0;
                for (lli j = 0; j < ch.size(); j++) {
                    no += abs(ch[i] - ch[j]);
                }
                if (mn == -1) {
                    mn = no;
                }
                mn = min(mn, no);
            }
            ans += mn;
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}