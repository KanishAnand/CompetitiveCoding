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
    vector<lli> v;
    cin >> t;
    while (t--) {
        string st;
        cin >> st;
        lli len = st.length();

        if (len >= 2 && st[len - 2] == 'p' && st[len - 1] == 'o') {
            cout << "FILIPINO" << endl;
        } else if (len >= 4 && st[len - 4] == 'd' && st[len - 3] == 'e' &&
                   st[len - 2] == 's' && st[len - 1] == 'u') {
            cout << "JAPANESE" << endl;
        } else if (len >= 4 && st[len - 4] == 'm' && st[len - 3] == 'a' &&
                   st[len - 2] == 's' && st[len - 1] == 'u') {
            cout << "JAPANESE" << endl;
        } else if (len >= 5 && st[len - 5] == 'm' && st[len - 4] == 'n' &&
                   st[len - 3] == 'i' && st[len - 2] == 'd' &&
                   st[len - 1] == 'a') {
            cout << "KOREAN" << endl;
        }
    }

    rt;
}
