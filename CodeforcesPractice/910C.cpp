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
    lli n, a;
    cin >> n;
    string st;
    vector<lli> v(11, 0);
    vector<lli> isstart(11, 0);

    for (lli i = 0; i < n; i++) {
        cin >> st;
        isstart[st[0] - 'a'] = 1;
        reverse(all(st));
        lli p = 1;
        for (lli j = 0; j < st.length(); j++) {
            v[st[j] - 'a'] += p;
            p *= 10;
        }
    }

    vector<lli> val(10, -1);

    vector<pair<lli, lli>> store;

    for (lli i = 0; i < 10; i++) {
        store.pb({v[i], i});
    }

    sort(store.rbegin(), store.rend());
    lli zero = 0, beg = 1, ans = 0;

    for (lli i = 0; i < store.size(); i++) {
        lli chr = store[i].second;
        if (isstart[chr] == 0 && zero == 0) {
            val[chr] = 0;
            zero = 1;
        } else {
            val[chr] = beg;
            beg++;
        }
    }

    for (lli i = 0; i < 10; i++) {
        ans += val[i] * v[i];
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