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
    lli n, a;
    vector<lli> v, ve;
    map<lli, lli> mp;
    cin >> n;
    fr(i, 0, n) {
        cin >> a;
        if (mp[a] == 0) {
            v.pb(a);
        }
        mp[a]++;
    }
    fr(i, 0, v.size()) {
        ve.pb(mp[v[i]]);
    }
    sort(ve.rbegin(), ve.rend());

    lli lim = ve[0];
    lli ans = -1;
    for (lli i = lim; i >= 1; i--) {
        lli sum = 0;
        sum += i;
        lli beg = 1, val = i / 2;
        if (i % 2 == 1) {
            if (sum > ans) {
                ans = sum;
            }
            continue;
        }
        while (beg < ve.size() && ve[beg] >= val) {
            sum += val;
            if (val % 2 == 1) {
                break;
            }
            val /= 2;
            beg++;
        }
        if (sum > ans) {
            ans = sum;
        }
    }

    cout << ans << endl;
    rt;
}
