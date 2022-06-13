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

void solve() {
    string st;
    cin >> st;

    vector<lli> v;
    vector<lli> confirm;
    for (lli i = 0; i < len(st); i++) {
        if (st[i] == 'o') {
            confirm.pb(i);
            v.pb(i);
        } else if (st[i] == '?') {
            v.pb(i);
        }
    }

    lli n = sz(v), ans = 0;
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            for (lli k = 0; k < n; k++) {
                for (lli l = 0; l < n; l++) {
                    map<lli, lli> tmp;
                    tmp[v[i]]++;
                    tmp[v[j]]++;
                    tmp[v[k]]++;
                    tmp[v[l]]++;
                    lli flag = 1;
                    for (auto el : confirm) {
                        if (tmp[el] == 0) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1) {
                        ans++;
                    }
                }
            }
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