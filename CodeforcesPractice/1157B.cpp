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
    lli n, a;
    vector<lli> v;
    cin >> n;
    string st;
    cin >> st;
    v.pb(0);
    fr(i, 0, 9) {
        cin >> a;
        v.pb(a);
    }
    lli beg = -1, end = -1;

    for (lli i = 0; i < st.length(); i++) {
        lli p = st[i] - '0';
        if (v[p] > p) {
            if (beg == -1) {
                beg = i;
                end = i;
            } else {
                end = i;
            }
        } else if (v[p] == p) {
            if (beg != -1) {
                end = i;
            }
        } else if (beg != -1) {
            end = i - 1;
            break;
        }
    }

    for (lli i = 0; i < st.length(); i++) {
        lli p = st[i] - '0';
        if (i >= beg && i <= end) {
            cout << v[p];
        } else {
            cout << p;
        }
    }
    cout << endl;
    rt;
}