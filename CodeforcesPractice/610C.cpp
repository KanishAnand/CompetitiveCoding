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

vector<vector<lli>> fun(lli n) {
    if (n == 0) {
        vector<vector<lli>> v(1);
        v[0].pb(1);
        return v;
    }

    lli no = pow(2, n);
    vector<vector<lli>> store(no);
    auto prev = fun(n - 1);

    lli i = 0;

    for (lli j = 0; j < prev.size(); j++) {
        for (lli k = 0; k < prev[0].size(); k++) {
            store[i].pb(prev[j][k]);
        }
        for (lli k = 0; k < prev[0].size(); k++) {
            store[i].pb(prev[j][k]);
        }
        i++;
    }

    for (lli j = 0; j < prev.size(); j++) {
        for (lli k = 0; k < prev[0].size(); k++) {
            store[i].pb(prev[j][k]);
        }
        for (lli k = 0; k < prev[0].size(); k++) {
            store[i].pb(-prev[j][k]);
        }
        i++;
    }
    return store;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<vector<lli>> ans = fun(n);

    for (lli i = 0; i < ans.size(); i++) {
        for (lli j = 0; j < ans[0].size(); j++) {
            if (ans[i][j] == 1) {
                cout << "+";
            } else {
                cout << "*";
            }
        }
        cout << endl;
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