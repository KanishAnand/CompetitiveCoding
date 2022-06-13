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
    lli n, a, b, cnt = 0, total = 0;
    cin >> n >> a >> b;

    vector<lli> v;

    for (lli i = 1; i <= n; i++) {
        v.pb(i);
    }
    while (n > 0) {
        total++;
        n /= 2;
    }
    total--;

    lli flag = 0;
    while (1) {
        vector<lli> tmp;
        cnt++;
        for (lli i = 0; i < v.size(); i++) {
            if ((v[i] == a && v[i + 1] == b) || (v[i] == b && v[i + 1] == a)) {
                flag = 1;
                break;
            }
            if (v[i] == a || v[i + 1] == a) {
                tmp.pb(a);
            } else if (v[i] == b || v[i + 1] == b) {
                tmp.pb(b);
            } else {
                tmp.pb(v[i]);
            }
            i++;
        }
        if (flag == 1) {
            break;
        }
        v = tmp;
    }

    if (cnt == total) {
        cout << "Final!" << endl;
    } else {
        cout << cnt << endl;
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