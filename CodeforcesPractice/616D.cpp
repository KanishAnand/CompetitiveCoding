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
    lli n, a, k;
    cin >> n >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    map<lli, lli> mp;
    lli begptr = 0, endptr = -1, val = 0, ans = -1, ansl, ansr;

    while (1) {
        if (val <= k) {
            if (endptr - begptr > ans) {
                ansl = begptr;
                ansr = endptr;
                ans = endptr - begptr;
            }
            endptr++;
            if (endptr >= n) {
                break;
            }
            if (mp[v[endptr]] == 0) {
                val++;
            }
            mp[v[endptr]]++;
        } else {
            mp[v[begptr]]--;
            if (mp[v[begptr]] == 0) {
                val--;
            }
            begptr++;
        }
    }

    cout << ansl + 1 << " " << ansr + 1 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}