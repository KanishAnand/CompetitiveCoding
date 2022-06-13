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

vector<lli> ind(1e6 + 2, 0);
vector<vector<lli>> store(1e6 + 2);

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;

    for (lli i = 0; i < 2 * n; i++) {
        cin >> a;
        v.pb(a);
    }

    sort(all(v));
    for (lli i = 0; i < 2 * n - 1; i++) {
        store[v[i]].pb(i);
    }

    for (lli p = 0; p < 2 * n - 1; p++) {
        vector<lli> mark(2 * n + 2, 0);
        mark[p] = 1;

        lli x = v[2 * n - 1], flag = 1;

        vector<pair<lli, lli>> ans;

        for (lli i = 2 * n - 2; i >= 0; i--) {
            if (mark[i] == 1) {
                continue;
            }

            mark[i] = 1;
            lli b = x - v[i];

            while (ind[b] < sz(store[b]) && mark[store[b][ind[b]]] == 1) {
                ind[b]++;
            }

            if (ind[b] >= sz(store[b])) {
                flag = 0;
                break;
            } else {
                lli indd = store[b][ind[b]];
                mark[indd] = 1;
                ans.pb({v[i], b});
                x = v[i];
            }
        }

        if (flag == 1) {
            for (lli i = 0; i < 2 * n; i++) {
                store[v[i]].clear();
                ind[v[i]] = 0;
            }

            cout << "YES" << endln;
            cout << v[p] + v[2 * n - 1] << endln;
            cout << v[p] << " " << v[2 * n - 1] << endln;
            for (auto pr : ans) {
                cout << pr.first << " " << pr.second << endln;
            }
            return;
        }

        for (lli i = 0; i < 2 * n; i++) {
            ind[v[i]] = 0;
        }
    }

    for (lli i = 0; i < 2 * n; i++) {
        store[v[i]].clear();
        ind[v[i]] = 0;
    }
    cout << "NO" << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    rt;
}