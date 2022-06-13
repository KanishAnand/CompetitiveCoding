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
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, mx = -1, val;
    vector<lli> v, ve;
    cin >> n;
    v.resize(n + 2, 0);
    map<lli, lli> mp;

    lli odd = 0;
    fr(i, 0, n) {
        cin >> a;
        ve.pb(a);
        if (a % 2 == 1) {
            ++odd;
        } else {
            lli cnt = 0;
            while (a % 2 == 0) {
                ++cnt;
                a /= 2;
            }
            mp[cnt]++;
            if (mp[cnt] > mx) {
                mx = mp[cnt];
                val = cnt;
            }
            v[i] = cnt;
        }
    }

    if (odd >= n - odd) {
        cout << n - odd << endl;
        fr(i, 0, n) {
            if (ve[i] % 2 == 0) {
                cout << ve[i] << " ";
            }
        }
        cout << endl;
    } else {
        if (odd >= mp[val]) {
            cout << n - odd << endl;
            fr(i, 0, n) {
                if (ve[i] % 2 == 0) {
                    cout << ve[i] << " ";
                }
            }
            cout << endl;
        } else {
            cout << n - mp[val] << endl;
            fr(i, 0, n) {
                if (v[i] != val) {
                    cout << ve[i] << " ";
                }
            }
            cout << endl;
        }
    }
    rt;
}
