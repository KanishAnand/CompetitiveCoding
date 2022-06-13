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
    lli n, a, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<lli> v, ch;
        map<lli, lli> mp;
        fr(i, 0, n) {
            cin >> a;
            if (a % 2 == 0) {
                if (mp[a] == 0) {
                    ch.pb(a);
                }
                mp[a] = 1;
            }
        }
        if (ch.size() == 0) {
            cout << "0" << endl;
            continue;
        }
        sort(all(ch));
        lli cnt = 0;
        for (lli i = ch.size() - 1; i >= 0; i--) {
            lli p = ch[i];
            if (mp[p] == 1) {
                mp[p] = 0;
                while (p % 2 == 0) {
                    mp[p] = 0;
                    p /= 2;
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }
    rt;
}
