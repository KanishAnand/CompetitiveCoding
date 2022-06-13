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
        vector<lli> ans;
        lli len = st.size();
        lli cnt = 0;
        for (lli i = 0; i <= len - 5; i++) {
            if (st[i] == 't' && st[i + 1] == 'w' && st[i + 2] == 'o' &&
                st[i + 3] == 'n' && st[i + 4] == 'e') {
                st[i + 2] = 'a';
                ans.pb(i + 3);
                cnt++;
            }
        }

        for (lli i = 0; i <= len - 3; i++) {
            if (st[i] == 'o' && st[i + 1] == 'n' && st[i + 2] == 'e') {
                ans.pb(i + 2);
                ++cnt;
            }
        }
        for (lli i = 0; i <= len - 3; i++) {
            if (st[i] == 't' && st[i + 1] == 'w' && st[i + 2] == 'o') {
                ans.pb(i + 2);
                ++cnt;
            }
        }
        cout << cnt << endl;
        lli p = ans.size();
        for (lli i = 0; i < p; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    rt;
}
