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

lli h, w, INF = 1e9;
vector<string> store;
vector<vector<lli>> dp;

lli calc(int r, int c) {
    if (dp[r][c] != INF) {
        return dp[r][c];
    }

    lli a = INF, b = INF;

    if (r + 1 < h) {
        a = calc(r + 1, c);
        dp[r + 1][c] = a;

        if ((r + 1 + c) % 2 == 1) {
            if (store[r + 1][c] == '+') {
                a++;
            } else {
                a--;
            }
        } else {
            if (store[r + 1][c] == '+') {
                a--;
            } else {
                a++;
            }
        }
    }

    if (c + 1 < w) {
        b = calc(r, c + 1);
        dp[r][c + 1] = b;
        if ((r + 1 + c) % 2 == 1) {
            if (store[r][c + 1] == '+') {
                b++;
            } else {
                b--;
            }
        } else {
            if (store[r][c + 1] == '+') {
                b--;
            } else {
                b++;
            }
        }
    }

    if (a == INF) {
        return b;
    } else if (b == INF) {
        return a;
    }

    if ((r + c) % 2 == 0) {
        return max(a, b);
    } else {
        return min(a, b);
    }
}

void solve() {
    cin >> h >> w;

    string st;
    for (lli i = 0; i < h; i++) {
        cin >> st;
        store.pb(st);
    }

    dp.resize(h + 2, vector<lli>(w + 2, INF));
    dp[h - 1][w - 1] = 0;
    lli val = calc(0, 0);

    if (val > 0) {
        cout << "Takahashi" << endl;
    } else if (val < 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
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