#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    string st;
    cin >> st;
    lli n = len(st);

    lli flag = 1;
    for (lli i = 0; i < n; i++) {
        if (st[i] != 'a') {
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        string st1 = st + 'a';
        string st2 = 'a' + st;
        lli beg = 0, end = n, tmp = 1;

        while (beg < end) {
            if (st1[beg] != st1[end]) {
                tmp = 1;
            }
            if (st2[beg] != st2[end]) {
                tmp = 2;
            }
            beg++;
            end--;
        }

        if (tmp == 1) {
            cout << st1 << endl;
        } else {
            cout << st2 << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}