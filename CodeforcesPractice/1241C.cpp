#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
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
lli a, b, x, y, k;
lli lcm(lli p, lli q) {
    lli t = __gcd(p, q);
    return (p * q) / t;
}

lli check(lli no, vector<lli> v, vector<lli> pref) {
    // cout << "K" << endl;
    lli c = lcm(a, b);
    // cout << c << endl;
    lli no1 = no / c, no2, no3, val1, val2;
    if (y > x) {
        no2 = no / b;
        no3 = no / a;
        val1 = y;
        val2 = x;
    } else {
        no2 = no / a;
        no3 = no / b;
        val1 = x;
        val2 = y;
    }
    lli val = 0;
    // if (no1 >= 0) {
    val = pref[no1] * (val1 + val2);
    // }
    // cout << val << endl;
    // if (no2 + no1 - 1 >= 0) {
    // cout << pref[no2 + no1] << endl;
    // cout << val1 << endl;

    // if (no2 + no1 <= no) {
    val += (pref[no2] - pref[no1]) * val1;
    // }
    // }
    // cout << val << endl;
    // if (no2 + no1 + no3 - 1 >= 0) {
    // if (no1 + no2 + no3 <= no && no2 <= no) {
    val += (pref[no3 + no2 - no1] - pref[no2]) * val2;
    // }
    // }
    // cout << val << endl;

    val /= 100;
    return val;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, q;
    cin >> q;
    while (q--) {
        vector<lli> v, pref;
        v.pb(0);
        cin >> n;
        pref.resize(n + 2, 0);
        input(n, v);
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        sort(v.rbegin(), v.rend());
        pref[0 + 1] = v[0];
        fr(i, 1, n) {
            pref[i + 1] = pref[i] + v[i];
        }
        // binary search
        // cout << check(6, v, pref) << endl;
        lli va = check(n, v, pref);
        if (va < k) {
            cout << "-1" << endln;
        } else {
            lli beg = 1, end = n;
            while (beg <= end) {
                lli mid = (beg + end) / 2;
                lli ch = check(mid, v, pref);
                if (ch >= k) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            }
            cout << beg << endln;
        }
    }
    rt;
}
