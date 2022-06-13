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
    lli n, a = -1, b = -1;
    cin >> n;
    vector<lli> v1(n + 2, 0), v(n + 2, 1), v2(n + 2, 0);
    string st;
    cin >> st;

    fr(i, 1, n) {
        if (st[i] == st[i - 1]) {
            if (v2[i - 1] != 0 || v1[i - 1] != 0) {
                v1[i] = 1;
            }
            v[i] = v[i - 1] + 1;
        } else {
            v2[i] = v[i - 1];
        }
    }

    lli sum = 0;
    fr(i, 0, n) {
        // cout << v1[i] << " " << v2[i] << endl;
        sum += v1[i] + v2[i];
    }
    lli ans = (n * (n - 1)) / 2 - sum;
    cout << ans << endl;
    rt;
}