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
    lli n, a, p, b;
    cin >> n >> p;
    set<pair<lli, lli>> st;
    vector<lli> cnt(n + 2, 0);
    map<lli, map<lli, lli>> mp;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        if (b < a) {
            swap(a, b);
        }
        st.insert({a, b});
        mp[a][b]++;
        cnt[a]++;
        cnt[b]++;
    }

    vector<lli> store;
    for (lli i = 1; i <= n; i++) {
        store.pb(cnt[i]);
    }

    sort(all(store));

    lli ans = 0;

    for (lli i = 0; i < store.size(); i++) {
        a = store[i];
        lli val = p - a;
        auto it = lower_bound(store.begin(), store.end(), val);
        lli no = store.end() - it;
        lli ind = it - store.begin();
        if (ind <= i) {
            no--;
        }
        ans += no;
    }

    ans /= 2;

    for (auto it = st.begin(); it != st.end(); it++) {
        a = it->first;
        b = it->second;
        if (cnt[a] + cnt[b] >= p) {
            lli val = cnt[a] + cnt[b];
            val -= mp[a][b];
            if (val < p) {
                ans--;
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