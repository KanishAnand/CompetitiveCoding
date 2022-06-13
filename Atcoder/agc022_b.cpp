#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
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
    if (n == 3) {
        cout << "2 5 63" << endl;
        return;
    }
    if (n == 4) {
        cout << "2 3 4 9" << endl;
        return;
    }

    lli beg = 3;
    vector<lli> v;
    cout << "2 4 ";
    n -= 2;

    while (n > 0 && beg <= 30000) {
        v.pb(beg);
        beg += 6;
        n--;
    }

    if (v.size() % 2 == 1) {
        v.pop_back();
        n++;
    }

    beg = 8;
    while (n >= 2 && beg + 2 <= 30000) {
        cout << beg << " " << beg + 2 << " ";
        n -= 2;
        beg += 6;
    }

    beg = 6;
    while (n > 0) {
        cout << beg << " ";
        n--;
        beg += 6;
    }

    for (lli i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}