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
    lli n, a, one = 0, two = 0;
    vector<lli> v;
    cin >> n;
    fr(i, 0, n) {
        cin >> a;
        if (a == 1) {
            one++;
        } else {
            two++;
        }
    }

    if (one >= 1) {
        if (two != 0) {
            cout << "2 ";
            two--;
        }
        cout << "1 ";
        one--;
        fr(i, 0, two) {
            cout << "2 ";
        }
        fr(i, 0, one) {
            cout << "1 ";
        }
        cout << endl;
    } else {
        fr(i, 0, two) {
            cout << "2 ";
        }
        cout << endl;
    }
    rt;
}
