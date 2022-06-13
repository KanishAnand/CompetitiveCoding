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
lli n, a, b, ans = -1, ov = 0;

void perm(vector<lli> &v, vector<lli> &vis, lli cnt) {
    if (cnt == 6) {
        ov++;
        lli val = n, no = 1;
        for (lli i = 0; i < 6; i++) {
            if (v[i] < 5) {
                if (val >= a) {
                    val -= a;
                } else {
                    no++;
                    val = n - a;
                }
            } else {
                if (val >= b) {
                    val -= b;
                } else {
                    no++;
                    val = n - b;
                }
            }
        }

        if (ans != -1) {
            ans = min(ans, no);
        } else {
            ans = no;
        }
        return;
    }

    for (lli i = 1; i <= 6; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            v.pb(i);
            perm(v, vis, cnt + 1);
            vis[i] = 0;
            v.pop_back();
        }
    }
}

void solve() {
    cin >> n >> a >> b;
    vector<lli> vis(7, 0), v;
    perm(v, vis, 0);
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