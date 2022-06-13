#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 998244353;

lli dp[32768][15][15];

void solve() {
    lli n, a;
    cin >> n;
    string st;
    cin >> st;
    vector<lli> mp(n + 2, 0);
    for (lli i = 0; i < n; i++) {
        if (st[i] == '1') {
            mp[i + 1] = 1;
        }
    }

    //base case
    for (lli i = 0; i < n; i++) {
        lli tmp_mask = pow(2, i);
        dp[tmp_mask][i][0] = 1;
    }

    for (lli mask = 1; mask < pow(2, n); mask++) {
        for (lli prev = 1; prev <= n; prev++) {
            lli tmp_no = pow(2, prev - 1);
            if ((mask & tmp_no) == 0) {
                continue;
            }
            for (lli curr = 1; curr <= n; curr++) {
                lli tmp_no = pow(2, curr - 1);
                if ((mask & tmp_no) != 0) {
                    continue;
                }
                lli new_mask = (mask ^ tmp_no);
                if (curr % prev == 0 && mp[curr / prev] == 1) {
                    for (lli cost = 1; cost < n; cost++) {
                        dp[new_mask][curr - 1][cost] += dp[mask][prev - 1][cost - 1];
                        dp[new_mask][curr - 1][cost] %= MOD;
                    }
                } else {
                    for (lli cost = 0; cost < n; cost++) {
                        dp[new_mask][curr - 1][cost] += dp[mask][prev - 1][cost];
                        dp[new_mask][curr - 1][cost] %= MOD;
                    }
                }
            }
        }
    }

    lli all_one = pow(2, n) - 1;
    for (lli cost = 0; cost < n; cost++) {
        lli ans = 0;
        for (lli last_no = 1; last_no <= n; last_no++) {
            ans += dp[all_one][last_no - 1][cost];
            ans %= MOD;
        }
        cout << ans << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}