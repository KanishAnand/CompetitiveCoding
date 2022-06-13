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
    int n, a;
    cin >> n;
    vector<int> v;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        mp[a]++;
    }

    int flag = 0, lim = 30, flag2 = 0;
    vector<int> ans, ans1;

    for (int i = 0; i < n; i++) {
        int p = 1;
        for (int j = 0; j <= lim; j++) {
            int a = v[i] + 2 * p;
            int b = v[i] + p;
            if (a > INT_MAX) {
                continue;
            }
            if (mp[a] != 0 && mp[b] != 0) {
                flag = 1;
                ans.pb(v[i]);
                ans.pb(a);
                ans.pb(b);
                break;
            }
            if (flag2 == 0 && mp[b] != 0) {
                flag2 = 1;
                ans1.pb(v[i]);
                ans1.pb(b);
            }
            p *= 2;
        }
        if (flag == 1) {
            break;
        }
    }

    if (flag == 1) {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else if (flag2 == 1) {
        cout << ans1.size() << endl;
        for (int i = 0; i < ans1.size(); i++) {
            cout << ans1[i] << " ";
        }
        cout << endl;
    } else {
        cout << "1" << endl;
        cout << v[0] << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}