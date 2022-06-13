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
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

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
    lli n, a, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string st, cmp = "";
    st = s.substr(0, k);

    fr(i, 0, n / k) {
        cmp += st;
    }
    fr(i, 0, n % k) {
        cmp += st[i];
    }
    cout << n << endl;

    if (cmp >= s) {
        cout << cmp << endl;
    } else {
        string ans = "";
        ans = s.substr(0, k);
        for (lli i = k - 1; i >= 0; i--) {
            if (ans[i] == '9') {
                ans[i] = '0';
            } else {
                ans[i]++;
                break;
            }
        }
        string cmp1 = "";
        fr(i, 0, n / k) {
            cmp1 += ans;
        }
        fr(i, 0, n % k) {
            cmp1 += ans[i];
        }
        cout << cmp1 << endl;
    }
    rt;
}