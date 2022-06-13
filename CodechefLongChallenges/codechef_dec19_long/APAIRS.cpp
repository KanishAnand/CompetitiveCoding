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

lli mod = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t;
    vector<lli> v;
    cin >> t;
    while (t--) {
        lli l, r, b, ans = 0;
        cin >> l >> r;
        fr(i, l, r + 1) {
            fr(j, l, r + 1) {
                vector<lli> v1, v2;
                a = i;
                b = j;
                while (a > 0) {
                    v1.pb(a % 10);
                    a /= 10;
                }
                while (b > 0) {
                    v2.pb(b % 10);
                    b /= 10;
                }
                if (v1.size() < v2.size()) {
                    lli p = v2.size() - v1.size();
                    while (p > 0) {
                        v1.pb(0);
                        --p;
                    }
                } else {
                    lli p = v1.size() - v2.size();
                    while (p > 0) {
                        v2.pb(0);
                        --p;
                    }
                }
                sort(all(v1));
                sort(all(v2));
                for (lli i = 0; i < v1.size(); i++) {
                    ans += abs(v1[i] - v2[i]);
                    ans %= mod;
                }
            }
        }
        cout << ans << endl;
    }
    rt;
}