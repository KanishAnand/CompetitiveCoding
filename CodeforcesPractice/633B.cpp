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
    lli n, cnt = 0, no = -1;
    cin >> n;
    for (lli i = 1; i <= n; i++) {
        lli val = 5 * i, ch = 0;
        while (val % 5 == 0) {
            val /= 5;
            ch++;
        }
        cnt += ch;
        if (cnt == n) {
            no = 5 * i;
        } else if (cnt > n) {
            break;
        }
    }

    if (no == -1) {
        cout << "0" << endl;
    } else {
        cout << "5" << endl;
        for (lli i = 0; i < 5; i++) {
            cout << no << " ";
            no += 1;
        }
        cout << endl;
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