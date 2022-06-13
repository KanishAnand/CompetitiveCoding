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
    lli n, ans = 10;
    string st;
    cin >> st;
    for (lli j = 0; j <= 999999; j++) {
        lli i = j;
        lli sum = i % 10, sum2 = 0;
        i /= 10;
        sum += i % 10;
        i /= 10;
        sum += i % 10;
        i /= 10;

        sum2 += i % 10;
        i /= 10;
        sum2 += i % 10;
        i /= 10;
        sum2 += i % 10;
        if (sum != sum2) {
            continue;
        }
        lli beg = 5, cnt = 0;
        i = j;
        while (beg >= 0) {
            if (st[beg] - '0' != i % 10) {
                ++cnt;
            }
            i /= 10;
            --beg;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    rt;
}