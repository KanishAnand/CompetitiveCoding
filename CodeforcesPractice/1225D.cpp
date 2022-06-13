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
    lli n, a, k, ans = 0;
    cin >> n >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        lli val = v[i], no = 1, no2 = 1;
        for (lli j = 2; j <= sqrt(val); j++) {
            lli cnt = 0;
            while (val % j == 0) {
                val /= j;
                cnt++;
            }
            cnt %= k;
            no *= pow(j, cnt);
            no2 *= pow(j, (k - cnt) % k);
        }

        if (val != 1) {
            no *= val;
            no2 *= pow(val, k - 1);
        }

        if (mp[no2] != 0) {
            cout << i << " " << v[i] << " " << no << " " << no2 << " "
                 << mp[no2] << endl;
        }
        ans += mp[no2];
        mp[no]++;
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