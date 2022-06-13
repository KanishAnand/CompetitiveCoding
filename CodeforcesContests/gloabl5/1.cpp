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
    lli n, a;
    vector<lli> v;
    cin >> n;
    lli cnt = 0, sum1 = 0, sum2 = 0;
    while (n--) {
        cin >> a;
        v.pb(a);
        if (a % 2 == 0) {
            sum1 += a / 2;
        } else {
            sum2 += a / 2;
        }
    }
    lli val = (sum1 + sum2) * (-1), pos = 0, neg = 0;
    if (val < 0) {
        pos = 0;
        neg = val * (-1);
    } else {
        pos = val;
        neg = 0;
    }

    fr(i, 0, v.size()) {
        a = v[i];
        if (a % 2 == 0) {
            cout << a / 2 << endl;
        } else {
            if (neg != 0) {
                if (a > 0) {
                    cout << a / 2 << endl;
                } else {
                    a--;
                    neg--;
                    cout << a / 2 << endl;
                }
            } else if (pos != 0) {
                if (a > 0) {
                    a++;
                    pos--;
                    cout << a / 2 << endl;
                } else {
                    cout << a / 2 << endl;
                }
            } else {
                cout << a / 2 << endl;
            }
        }
    }

    rt;
}
