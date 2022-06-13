#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

lli mod = 998244353;

lli power(lli a, lli b) {
    lli ans = 1, x = a;
    while (b > 0) {
        if (b % 2 == 1) {
            ans *= x;
            ans %= mod;
        }
        b /= 2;
        x = (x * x) % mod;
    }
    return ans;
}

lli fun(lli num, lli den) {
    lli val = power(den, mod - 2);
    val = (val * num) % mod;
    return val;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, k;
    map<lli, lli> mp;
    vector<vector<lli>> v;
    v.resize(1000005);
    cin >> n;
    fr(i, 0, n) {
        cin >> k;
        fr(j, 0, k) {
            cin >> a;
            mp[a]++;
            v[a].pb(k);
        }
    }

    lli ans = 0;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        lli val = (*it).first;
        lli cnt = (*it).second;
        for (lli i = 0; i < v[val].size(); i++) {
            lli val2 = v[val][i];
            lli num = cnt;
            lli den = (n * n) % mod;
            den = (den * val2) % mod;
            ans += fun(num, den);
            ans %= mod;
        }
    }
    cout << ans << endl;
    rt;
}