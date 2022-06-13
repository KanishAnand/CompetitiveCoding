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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void print_vec(vector<lli> &v) {
    lli n = sz(v);
    for (lli i = 0; i < n; i++) {
        cout << v[i];
        if (i != n - 1) {
            cout << ".";
        }
    }
    cout << endln;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> dig;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        dig.pb(a);
    }

    vector<lli> v;
    v.pb(1);
    print_vec(v);

    for (lli i = 1; i < n; i++) {
        if (dig[i] == 1) {
            v.pb(1);
        } else {
            vector<lli> tmp;
            lli ind;
            for (lli j = sz(v) - 1; j >= 0; j--) {
                if (v[j] == dig[i] - 1) {
                    ind = j;
                    break;
                }
            }

            for (lli j = 0; j < ind; j++) {
                tmp.pb(v[j]);
            }

            tmp.pb(dig[i]);
            v = tmp;
        }

        print_vec(v);
    }
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