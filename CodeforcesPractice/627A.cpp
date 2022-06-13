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
    lli n, a, s, x;
    vector<lli> v;
    cin >> s >> x;
    if ((s - x) % 2 != 0 || s - x < 0) {
        cout << "0" << endl;
        rt;
    }

    lli cnt = 0, xo = x, tmp = x, tmp2 = (s - x) / 2;

    while (tmp > 0 || tmp2 > 0) {
        lli r1 = tmp % 2;
        lli r2 = tmp2 % 2;
        if (r1 + r2 == 2) {
            cout << "0" << endl;
            rt;
        }
        tmp /= 2;
        tmp2 /= 2;
    }

    while (x > 0) {
        if (x % 2 == 1) {
            ++cnt;
        }
        x /= 2;
    }

    lli ans = pow(2, cnt);
    if (s == xo) {
        ans -= 2;
    }
    cout << ans << endl;
    rt;
}