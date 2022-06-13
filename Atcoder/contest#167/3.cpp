#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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
    lli n, a, m, x;
    cin >> n >> m >> x;
    vector<vector<lli>> v(n + 2);
    vector<lli> cs;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        cs.pb(a);
        for (lli j = 0; j < m; j++) {
            cin >> a;
            v[i].pb(a);
        }
    }

    lli flag = 0, mn = 1e17;

    for (lli i = 0; i < pow(2, n); i++) {
        vector<lli> ch(m + 2, 0);
        lli val = i, cnt = 0, cost = 0;

        while (val > 0) {
            if (val % 2 == 1) {
                cost += cs[cnt];
                for (lli j = 0; j < m; j++) {
                    ch[j] += v[cnt][j];
                }
            }
            val /= 2;
            cnt++;
        }

        lli flag = 0;
        for (lli j = 0; j < m; j++) {
            if (ch[j] < x) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            mn = min(mn, cost);
        }
    }

    if (mn == 1e17) {
        cout << "-1" << endl;
    } else {
        cout << mn << endl;
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