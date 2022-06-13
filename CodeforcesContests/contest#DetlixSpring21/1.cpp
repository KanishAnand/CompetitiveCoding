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
#define sz(x) (int)(x.size())
#define len(x) (int)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    int n, a, m;
    cin >> n >> m;
    string st;
    cin >> st;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.pb(st[i] - '0');
    }

    while (m--) {
        int flag = 1;
        vector<int> tmp = v;

        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                continue;
            }

            int cnt = 0;
            if (i > 0 && v[i - 1] == 1) {
                cnt++;
            }
            if (i < n - 1 && v[i + 1] == 1) {
                cnt++;
            }

            if (cnt == 1) {
                flag = 0;
                tmp[i] = 1;
            }
        }
        v = tmp;

        if (flag == 1) {
            break;
        }
    }

    for (auto el : v) {
        cout << el;
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    rt;
}