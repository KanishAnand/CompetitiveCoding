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
    lli n, m, p;
    cin >> n >> m;

    vector<lli> a, b, c;
    vector<lli> b_col(n + 2, 0), c_col(n + 2, 0), col(n + 2, 0);
    vector<vector<lli>> store(n + 2);

    for (lli i = 0; i < n; i++) {
        cin >> p;
        a.pb(p);
    }

    for (lli i = 0; i < n; i++) {
        cin >> p;
        b_col[p]++;
        b.pb(p);
    }

    for (lli i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            store[b[i]].pb(i + 1);
            col[b[i]]++;
        }
    }

    for (lli i = 0; i < m; i++) {
        cin >> p;
        c_col[p]++;
        c.pb(p);
    }

    if (b_col[c[m - 1]] == 0) {
        cout << "NO" << endl;
        return;
    }

    for (lli i = 1; i <= n; i++) {
        if (col[i] > c_col[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    lli ind;
    if (col[c[m - 1]] != 0) {
        ind = store[c[m - 1]][col[c[m - 1]] - 1];
        col[c[m - 1]]--;
    } else {
        for (lli i = 0; i < n; i++) {
            if (b[i] == c[m - 1]) {
                ind = i + 1;
                break;
            }
        }
    }

    cout << "YES" << endl;
    for (lli i = 0; i < m - 1; i++) {
        lli el = c[i];
        if (col[el] != 0) {
            cout << store[el][col[el] - 1] << " ";
            col[el]--;
        } else {
            cout << ind << " ";
        }
    }
    cout << ind;
    cout << endl;
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