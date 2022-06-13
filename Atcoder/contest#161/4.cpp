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
    vector<lli> str;

    for (lli i = 1; i <= 9; i++) {
        lli cnt = 0;
        queue<lli> qu;
        qu.push(i);

        while (!qu.empty()) {
            a = qu.front();
            lli p = a % 10;
            cnt++;
            str.pb(a);
            qu.pop();
            if (cnt == 1e5) {
                break;
            }

            if (p == 0) {
                qu.push(a * 10 + p);
                qu.push(a * 10 + p + 1);
            } else if (p == 9) {
                qu.push(a * 10 + p - 1);
                qu.push(a * 10 + p);
            } else {
                qu.push(a * 10 + p - 1);
                qu.push(a * 10 + p);
                qu.push(a * 10 + p + 1);
            }
        }
    }

    sort(all(str));
    cout << str[n - 1] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}