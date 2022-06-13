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
    lli n, a, k, b;
    cin >> n >> k;
    vector<vector<lli>> v(k + 2);

    for (lli i = 0; i < k; i++) {
        cin >> a;
        for (lli j = 0; j < a; j++) {
            cin >> b;
            v[i].pb(b);
        }
    }

    lli beg = 1, end = n, mx;

    cout << "? ";
    cout << n << " ";
    for (lli i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
    cin >> mx;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        cout << "? ";
        cout << mid - beg + 1 << " ";
        for (lli i = beg; i <= mid; i++) {
            cout << i << " ";
        }
        cout << endl;
        lli val;
        cin >> val;
        if (val == mx) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    vector<lli> ans;

    for (lli i = 0; i < k; i++) {
        lli flag = 0;
        for (lli j = 0; j < v[i].size(); j++) {
            if (v[i][j] == beg) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ans.pb(mx);
        } else {
            cout << "? ";
            cout << n - v[i].size() << " ";
            vector<lli> mk(n + 2, 0);
            for (lli j = 0; j < v[i].size(); j++) {
                mk[v[i][j]] = 1;
            }

            for (lli j = 1; j <= n; j++) {
                if (mk[j] == 0) {
                    cout << j << " ";
                }
            }
            cout << endl;
            cin >> a;
            ans.pb(a);
        }
    }

    cout << "! ";
    for (lli i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    string st;
    cin >> st;
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