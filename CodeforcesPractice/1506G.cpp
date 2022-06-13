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
    string st;
    cin >> st;

    lli n = len(st);
    vector<lli> vis(26, 1);

    vector<set<lli>> store(26);

    for (lli i = 0; i < n; i++) {
        vis[st[i] - 'a'] = 0;
        store[st[i] - 'a'].insert(i);
    }

    string ans = "";
    lli store_ind = -1;

    while (1) {
        lli flag = 0;

        for (lli i = 25; i >= 0; i--) {
            if (vis[i]) {
                continue;
            }

            while (1) {
                auto it = store[i].begin();
                if (*(it) < store_ind) {
                    store[i].erase(it);
                } else {
                    break;
                }
            }

            lli ind = *(store[i].begin()), tmp = 1;

            for (lli j = 0; j < 26; j++) {
                if (vis[j] == 1) {
                    continue;
                }
                auto it = store[j].end();
                it--;
                lli ind2 = *it;
                if (ind2 < ind) {
                    tmp = 0;
                    break;
                }
            }

            if (tmp == 1) {
                ans += (char)(i + 'a');
                store_ind = ind;
                vis[i] = 1;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            break;
        }
    }

    cout << ans << endl;
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