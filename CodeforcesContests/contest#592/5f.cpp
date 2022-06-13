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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, k;
    vector<lli> v;
    cin >> n >> k;
    input(n, v);
    sort(all(v));
    lli beg = 0, end = n - 1;

    while (k > 0 && beg < end) {
        if (beg + 1 <= n - end) {
            if (beg < n - 1) {
                lli val = v[beg + 1] - v[beg];
                if (val * (beg + 1) <= k) {
                    k -= val * (beg + 1);
                    beg++;
                } else {
                    break;
                }
            }
        } else {
            if (end > 0) {
                lli val = v[end] - v[end - 1];
                if (val * (n - end) <= k) {
                    k -= val * (n - end);
                    end--;
                } else {
                    break;
                }
            }
        }
    }

    if (beg >= end || beg == n - 1 || end == 0) {
        cout << "0" << endl;
        rt;
    }
    lli ans = v[end] - v[beg];

    if (beg + 1 <= n - end) {
        lli t = k / (beg + 1);
        ans -= t;
        k -= t * (beg + 1);
    } else {
        lli t = k / (n - end);
        ans -= t;
        k -= t * (n - end);
    }
    lli an = max(ans, (lli)0);
    cout << an << endl;

    rt;
}
