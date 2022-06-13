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
    lli n, a;
    cin >> n;

    lli flag = 1;
    vector<lli> v;
    map<lli, lli> mp;

    for (lli i = 0; i < 2 * n; i++) {
        cin >> a;
        mp[a]++;
        if (mp[a] % 2 == 1) {
            v.pb(a);
        }
    }

    for (auto el : v) {
        if (mp[el] % 2 == 1) {
            flag = 0;
            break;
        }
    }

    if (sz(v) != n) {
        flag = 0;
    }

    if (flag == 0) {
        cout << "NO" << endl;
        return;
    }

    sort(v.rbegin(), v.rend());
    lli no = n, sub = 0;
    set<lli> ans;
    lli p = 1;

    for (lli i = 0; i < n; i++) {
        // cout << v[i] << " " << sub << endl;
        v[i] -= sub;
        if (v[i] > 0 && v[i] % (2 * no) == 0) {
            lli val = v[i] / (2 * no);
            sub += 2 * val;
            ans.insert(val);
            if (val == 0) {
                p = 0;
            }
        } else {
            cout << "NO" << endl;
            return;
        }
        no--;
    }

    if (p == 1 && sz(ans) == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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