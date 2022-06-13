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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    sort(all(v));

    vector<set<lli>> store(n + 2);
    vector<set<lli>> store2(n + 2);

    for (lli i = 0; i < n; i++) {
        if (i >= 1) {
            store[i] = store[i - 1];
        }
        lli tmp = v[i];
        lli cnt = 0;
        while (tmp > 0) {
            lli rem = tmp % 2;
            if (rem == 1) {
                store[i].insert(cnt);
            }
            cnt++;
            tmp /= 2;
        }
    }

    for (lli i = 0; i < n; i++) {
        lli tmp = v[i];
        lli cnt = 0;
        while (v[i] > 0) {
            lli rem = v[i] % 2;
            if (rem == 1) {
                store2[i].insert(cnt);
            }
            cnt++;
            v[i] /= 2;
        }
    }

    lli ans = 0;
    for (lli i = n - 1; i >= 0; i--) {
        lli val = 0;
        for (auto it = store[i].begin(); it != store[i].end(); it++) {
            if (i == n - 1) {
                val += pow(2, *it);
            } else {
                lli p = *it;
                if (store2[i + 1].find(p) != store2[i + 1].end()) {
                    val += pow(2, *it);
                }
            }
        }
        ans += (val * val);
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