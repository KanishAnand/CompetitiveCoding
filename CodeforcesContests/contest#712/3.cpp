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
    lli n;
    cin >> n;
    string st;
    cin >> st;

    if (st[0] != '1' || st[n - 1] != '1') {
        cout << "NO" << endl;
        return;
    }

    lli cnt = 0;
    for (lli i = 0; i < n; i++) {
        if (st[i] == '0') {
            cnt++;
        }
    }

    if (cnt % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    if ((n - cnt) % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    vector<char> a(n), b(n);

    lli flag = 0;
    for (lli i = 0; i < n; i++) {
        if (st[i] == '0') {
            if (flag == 0) {
                a[i] = '(';
                b[i] = ')';
            } else {
                a[i] = ')';
                b[i] = '(';
            }
            flag = 1 - flag;
        }
    }

    lli p = n - cnt, c = 0;
    flag = 0;

    for (lli i = 0; i < n; i++) {
        if (st[i] == '0') {
            continue;
        }
        if (c == p / 2) {
            flag = 1;
        }
        if (flag == 0) {
            a[i] = '(';
            b[i] = '(';
        } else {
            a[i] = ')';
            b[i] = ')';
        }

        c++;
    }

    cout << "YES" << endl;
    for (lli i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;
    for (lli i = 0; i < n; i++) {
        cout << b[i];
    }
    cout << endl;
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