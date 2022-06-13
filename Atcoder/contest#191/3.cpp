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
    lli h, w;
    cin >> h >> w;
    string st;
    vector<string> s;

    for (lli i = 0; i < h; i++) {
        cin >> st;
        s.pb(st);
    }

    lli ans = 0;

    lli prev = -1, mn = h + 2;

    for (lli i = 0; i < w; i++) {
        for (lli j = 0; j < h; j++) {
            if (s[j][i] == '#') {
                mn = min(mn, j);
                if (j != prev) {
                    ans++;
                    if (j != prev && j > mn) {
                        ans++;
                    }
                    prev = j;
                }
                break;
            }
        }
    }

    cout << ans << endl;

    prev = -1;
    lli mx = -1;

    for (lli i = 0; i < w; i++) {
        for (lli j = h - 1; j >= 0; j--) {
            if (s[j][i] == '#') {
                mx = max(mx, j);
                if (j != prev) {
                    ans++;
                    if (j != prev && j < mx) {
                        ans++;
                    }
                    prev = j;
                }
                break;
            }
        }
    }

    cout << ans << endl;

    prev = -1;
    for (lli i = 0; i < h; i++) {
        for (lli j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                if (j != prev) {
                    ans++;
                    if (prev != -1) {
                        ans++;
                    }
                    prev = j;
                }
                break;
            }
        }
    }

    prev = -1;
    for (lli i = 0; i < h; i++) {
        for (lli j = w - 1; j >= 0; j--) {
            if (s[i][j] == '#') {
                if (j != prev) {
                    ans++;
                    if (prev != -1) {
                        ans++;
                    }
                    prev = j;
                }
                break;
            }
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