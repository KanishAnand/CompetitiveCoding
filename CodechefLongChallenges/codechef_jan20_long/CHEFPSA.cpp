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

lli mod = 1e9 + 7;
lli power(lli x, lli y) {
    // (x^y) % mod
    lli ans = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return ans;
}

lli invmod(lli a) {
    return power(a, mod - 2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t;
    cin >> t;

    while (t--) {
        cin >> n;
        lli sum = 0;
        vector<lli> v;
        map<lli, lli> mp;
        fr(i, 0, 2 * n) {
            cin >> a;
            sum += a;
            mp[a]++;
            v.pb(a);
        }

        if (n == 1) {
            if (v[0] == v[1]) {
                cout << "1" << endln;
            } else {
                cout << "0" << endln;
            }
            continue;
        }

        if (sum % (n + 1) != 0) {
            cout << "0" << endln;
            continue;
        }

        lli val = sum / (n + 1);

        if (mp[val] < 2) {
            cout << "0" << endln;
            continue;
        }
        mp[val] -= 2;

        sort(all(v));
        lli cnt = 0, denom = 1;

        lli fc = 1;
        vector<lli> fac;
        fac.pb(1);
        for (lli i = 1; i <= n; i++) {
            fc *= i;
            fc %= mod;
            fac.pb(fc);
        }

        lli flag = 0;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            lli p = (*it).first;
            if (mp[p] != mp[val - p]) {
                cout << "0" << endln;
                flag = 1;
                break;
            }

            if (p == val - p) {
                if (it->second % 2 == 1) {
                    cout << "0" << endln;
                    flag = 1;
                    break;
                }
                denom *= fac[(it->second) / 2];
                denom %= mod;
            } else {
                cnt += mp[p];
                denom *= fac[it->second];
                denom %= mod;
            }
            mp[p] = 0;
            mp[val - p] = 0;
        }

        if (flag == 1) {
            continue;
        }

        lli ans = fac[n - 1];
        ans *= invmod(denom);
        ans %= mod;
        lli o = power(2, cnt);
        o %= mod;
        ans *= o;
        ans %= mod;

        cout << ans << endln;
    }
    rt;
}
