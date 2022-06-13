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
    v.resize(n, 0);
    string st;
    cin >> st;
    lli cnt = 2000;
    v[0] = 2000;
    fr(i, 0, n - 1) {
        if (st[i] == '=') {
            v[i + 1] = v[i];
        } else if (st[i] == 'L') {
            v[i + 1] = v[i] - 1;
        } else {
            v[i + 1] = v[i] + 1;
        }
    }

    lli val = *min_element(v.begin(), v.end());
    fr(i, 0, n) {
        cout << v[i] - val + 1 << " ";
    }
    cout << endl;
    rt;
}
