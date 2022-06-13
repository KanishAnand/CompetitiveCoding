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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    string st;
    cin >> st;

    lli n = len(st);
    lli flag = 1;

    for (lli i = 1; i < n; i++) {
        if (st[i] != st[i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        cout << "0" << endl;
    } else {
        lli beg = 0, end = n - 1, palindrome = 1;
        while (beg < end) {
            if (st[beg] != st[end]) {
                palindrome = 0;
                break;
            }
            beg++;
            end--;
        }

        if (palindrome == 0) {
            cout << n << endl;
        } else {
            cout << n - 1 << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}