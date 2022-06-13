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
    cin >> n;
    while (n--) {
        lli b, c;
        cin >> a >> b >> c;
        vector<lli> v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        sort(all(v));
        a = v[0];
        b = v[1];
        c = v[2];
        lli ans;
        if (a == b && a != c) {
            a++;
            b++;
            if (b != c) {
                c--;
            }
            ans = b - a + c - b + c - a;
        } else if (a != b && b == c) {
            b--;
            c--;
            if (a != b) {
                a++;
            }
            ans = b - a + c - b + c - a;
        } else if (a == b && b == c) {
            ans = 0;
        } else {
            a = min(b, a + 1);
            c = max(b, c - 1);
            ans = b - a + c - b + c - a;
        }
        cout << ans << endl;
    }
    rt;
}
