#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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
    lli n, a, q, l, r;
    cin >> n >> q;
    vector<lli> sum(n + 5, 0);
    vector<pair<lli, lli>> store;

    for (lli i = 0; i < q; i++) {
        cin >> l >> r;
        store.pb({l, r});
        sum[l] += 1;
        sum[r + 1] += -1;
    }

    lli val = 0, total = 0;

    for (lli i = 0; i <= n; i++) {
        val += sum[i];
        sum[i] = val;
        if (sum[i] != 0) {
            total++;
        }
    }

    vector<lli> one(n + 5, 0), two(n + 5, 0);

    for (lli i = 0; i <= n; i++) {
        if (sum[i] == 1) {
            one[i]++;
        }
        if (sum[i] == 2) {
            two[i]++;
        }
    }

    for (lli i = 1; i <= n; i++) {
        one[i] += one[i - 1];
        two[i] += two[i - 1];
    }

    lli l1, r1, l2, r2;
    lli mnn = 1e10;

    for (lli i = 0; i < q; i++) {
        l1 = store[i].first;
        r1 = store[i].second;
        lli val1 = one[r1] - one[l1 - 1];

        for (lli j = i + 1; j < q; j++) {
            l2 = store[j].first;
            r2 = store[j].second;
            lli val2 = one[r2] - one[l2 - 1];
            lli val3 = 0;

            if (l1 <= l2) {
                if (l2 <= r1) {
                    lli p = min(r1, r2);
                    val3 = two[p] - two[l2 - 1];
                }
            } else {
                if (l1 <= r2) {
                    lli p = min(r1, r2);
                    val3 = two[p] - two[l1 - 1];
                }
            }

            lli ans = val1 + val2 + val3;
            // cout << val1 << " " << val2 << " " << val3 << endl;
            // cout << ans << endl;
            mnn = min(mnn, ans);
        }
    }

    // cout << total << endl;
    cout << total - mnn << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}