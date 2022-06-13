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
const double PI = 3.14159265358979323846264338;
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
    lli n, a, b, c;

    cin >> n;
    vector<pair<lli, lli>> store;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        store.pb({a, i});
    }

    sort(all(store));

    lli beg = 1;

    for (lli i = 0; i < n; i++) {
        v[store[i].second] = beg;
        beg++;
    }

    vector<lli> ans;

    beg = 1;
    lli start = 0;
    lli flag = 0;

    while (1) {
        if (beg > n) {
            break;
        }

        lli ind = -1;
        for (lli i = 0; i < n; i++) {
            if (v[i] == beg) {
                ind = i;
                break;
            }
        }

        lli val = ind - start;
        while (val > 0) {
            val = ind - start;
            if (val == 0) {
                break;
            }
            // for (lli i = 0; i < n; i++) {
            //     cout << v[i] << " ";
            // }
            if (val == 1) {
                ans.pb(ind - 1);
                ans.pb(ind - 1);
                if (ind == n - 1) {
                    if (ind - 3 < 0) {
                        flag = 1;
                        break;
                    } else {
                        if (store[ind - 3].first != store[ind - 2].first) {
                            flag = 1;
                            break;
                        }
                        // cout << ind << "HI" << endl;
                        // cout << ans[sz(ans) - 1] << endl;
                        ans.pb(ind - 3);
                        ans.pb(ind - 3);
                        ans.pb(ind - 4);
                        ans.pb(ind - 4);
                        a = v[ind];
                        b = v[ind - 1];
                        v[ind - 1] = a;
                        v[ind] = b;
                        ind = start;
                        continue;
                    }
                }
                a = v[ind + 1];
                b = v[ind];
                c = v[ind - 1];
                v[ind - 1] = b;
                v[ind] = a;
                v[ind + 1] = c;
                ind = start;
            } else {
                a = v[ind];
                b = v[ind - 1];
                c = v[ind - 2];
                v[ind - 2] = a;
                v[ind - 1] = c;
                v[ind] = b;
                ans.pb(ind - 2);
                ind -= 2;
            }
        }

        if (flag == 1) {
            break;
        }

        beg++;
        start++;
    }

    for (lli i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            flag = 1;
            break;
        }
    }

    if (sz(ans) > n * n) {
        flag = 1;
    }

    if (flag == 1) {
        cout << "-1" << endl;
        return;
    }

    cout << sz(ans) << endl;
    for (lli i = 0; i < sz(ans); i++) {
        cout << ans[i] + 1 << " ";
    }
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