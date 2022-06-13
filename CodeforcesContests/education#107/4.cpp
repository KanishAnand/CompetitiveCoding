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
    lli n, k;
    cin >> n >> k;

    lli mx = k - 1;
    vector<set<lli>> st(mx + 1);
    for (lli i = 0; i <= mx; i++) {
        for (lli j = 0; j <= mx; j++) {
            st[i].insert(j);
        }
    }

    vector<lli> final;
    final.pb(0);

    lli ind = 0;
    while (1) {
        lli val = final[ind];
        if (val != mx) {
            auto it = st[val].begin();
            final.pb(*it);
            st[val].erase(it);
            ind++;
        } else {
            if (sz(st[val]) != 1) {
                auto it = st[val].begin();
                it++;
                final.pb(*it);
                st[val].erase(it);
                ind++;
            } else {
                final.pb(0);
                break;
            }
        }
    }

    ind = 0;
    lli no = sz(final);
    for (lli i = 0; i < n; i++) {
        char ch = (char)('a' + final[ind]);
        cout << ch;
        ind++;
        if (ind == no) {
            ind = 1;
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