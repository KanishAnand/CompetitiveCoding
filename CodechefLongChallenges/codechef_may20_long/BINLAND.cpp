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

void solve() {
    lli n, a, q;
    cin >> n >> q;
    vector<string> store;
    lli beg = 0;
    vector<vector<lli>> dp(30002, vector<lli>(12, 0));
    string st;

    while (q--) {
        cin >> st;
        if (st == "remove") {
            beg++;
        } else if (st == "add") {
            string ch;
            cin >> ch;
            store.pb(ch);
        } else {
            lli c, d;
            cin >> c >> d;
            c--, d--;
            for (lli i = 0; i < n; i++) {
                dp[beg][i] = 0;
            }

            dp[beg][c] = 1;
            for (lli i = beg + 1; i < store.size(); i++) {
                for (lli j = 0; j < n; j++) {
                    lli sm = 0;
                    if (j == 0) {
                        if (store[i - 1][j] == store[i][j]) {
                            sm += dp[i - 1][j];
                            sm %= MOD;
                        }
                        if (store[i - 1][j + 1] == store[i][j]) {
                            sm += dp[i - 1][j + 1];
                            sm %= MOD;
                        }
                    } else if (j == n - 1) {
                        if (store[i - 1][j - 1] == store[i][j]) {
                            sm += dp[i - 1][j - 1];
                            sm %= MOD;
                        }
                        if (store[i - 1][j] == store[i][j]) {
                            sm += dp[i - 1][j];
                            sm %= MOD;
                        }
                    } else {
                        if (store[i - 1][j - 1] == store[i][j]) {
                            sm += dp[i - 1][j - 1];
                            sm %= MOD;
                        }
                        if (store[i - 1][j] == store[i][j]) {
                            sm += dp[i - 1][j];
                            sm %= MOD;
                        }
                        if (store[i - 1][j + 1] == store[i][j]) {
                            sm += dp[i - 1][j + 1];
                            sm %= MOD;
                        }
                    }
                    dp[i][j] = sm;
                }
            }

            cout << dp[store.size() - 1][d] << endl;
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