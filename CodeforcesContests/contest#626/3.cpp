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
    lli n, a;
    cin >> n;
    string st;
    cin >> st;
    lli op = 0, cl = 0;

    // check -1
    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == '(') {
            op++;
        } else {
            cl++;
        }
    }

    if (op != cl) {
        cout << "-1" << endl;
        return;
    }

    op = 0, cl = 0;
    lli ans = 0;
    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == '(') {
            op++;
            if (cl != 0) {
                ans++;
                cl--;
                op--;
                continue;
            }
        } else {
            cl++;
        }

        if (cl > op) {
            // cl -= op;
            // op = 0;
            ans++;
            // op += cl;
            // cl++;
        }
        if (op >= cl) {
            op -= cl;
            cl = 0;
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}