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

string a, b, c;

lli fun(string ch) {
    if (a != ch && b != ch && c != ch) {
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    cin >> a >> b >> c;
    if (fun("ABC")) {
        cout << "ABC" << endl;
    } else if (fun("ARC")) {
        cout << "ARC" << endl;
    } else if (fun("AGC")) {
        cout << "AGC" << endl;
    } else if (fun("AHC")) {
        cout << "AHC" << endl;
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