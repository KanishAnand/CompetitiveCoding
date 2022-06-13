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
    vector<lli> v1, v2;
    cin >> n;
    string st;
    cin >> st;
    string st2 = st;
    // for black;
    lli cnt1 = 0, cnt2 = 0;
    for (lli i = 1; i < n; i++) {
        if (st[i - 1] != 'B') {
            st[i - 1] = 'B';
            if (st[i] == 'B') {
                st[i] = 'W';
            } else {
                st[i] = 'B';
            }
            cnt1++;
            v1.pb(i);
        }
    }

    for (lli i = 1; i < n; i++) {
        if (st2[i - 1] != 'W') {
            st2[i - 1] = 'W';
            if (st2[i] == 'B') {
                st2[i] = 'W';
            } else {
                st2[i] = 'B';
            }
            cnt2++;
            v2.pb(i);
        }
    }

    if (st[n - 1] == 'B' && st2[n - 1] == 'W') {
        if (cnt1 < cnt2) {
            cout << cnt1 << endl;
            fr(i, 0, v1.size()) {
                cout << v1[i] << " ";
            }
            cout << endl;
        } else {
            cout << cnt2 << endl;
            fr(i, 0, v2.size()) {
                cout << v2[i] << " ";
            }
            cout << endl;
        }
    } else if (st[n - 1] == 'B') {
        cout << cnt1 << endl;
        fr(i, 0, v1.size()) {
            cout << v1[i] << " ";
        }
        cout << endl;
    } else if (st2[n - 1] == 'W') {
        cout << cnt2 << endl;
        fr(i, 0, v2.size()) {
            cout << v2[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
    rt;
}
