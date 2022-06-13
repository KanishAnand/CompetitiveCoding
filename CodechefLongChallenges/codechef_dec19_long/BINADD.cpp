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
    lli t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (b == "0") {
            cout << "0" << endl;
            continue;
        }
        string c;
        if (a.length() < b.length()) {
            for (lli i = 0; i < b.length() - a.length(); i++) {
                c.pb('0');
            }
            for (lli i = 0; i < a.length(); i++) {
                c.pb(a[i]);
            }
            a = c;
        } else if (b.length() < a.length()) {
            for (lli i = 0; i < a.length() - b.length(); i++) {
                c.pb('0');
            }
            for (lli i = 0; i < b.length(); i++) {
                c.pb(b[i]);
            }
            b = c;
        }

        lli ans = 1, cnt = 0, val;
        for (lli i = 0; i < a.length(); i++) {
            lli p = a[i] - '0';
            lli q = b[i] - '0';
            if (p + q == 0) {
                cnt = 0;
            } else if (p + q == 1) {
                cnt++;
            } else {
                val = cnt + 2;
                ans = max(ans, val);
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
    rt;
}