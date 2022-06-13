#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define len(x) (int)(x.length())

vector<vector<int>> dp;

void solve() {
    int n, a;
    cin >> n;
    vector<vector<int>> v(n + 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            v[i].pb(a);
        }
    }

    //base case
    dp.resize(pow(10, n + 1), vector<int>(n + 1, -1));
    for (int col = 0; col < pow(10, n + 1); col++) {
        dp[col][0] = 0;
    }

    int fin = -1;
    for (int i = 1; i < n + 1; i++) {
        for (int col = 0; col < pow(10, n + 1); col++) {
            int tmp = col;
            vector<int> tmp_v;

            while (sz(tmp_v) != n + 1) {
                tmp_v.pb(tmp % 10);
                tmp /= 10;
            }

            for (int last = 0; last <= 9; last++) {
                int prev_col = last, p = 10, flag = 1, no = last;
                for (int row = 0; row < n; row++) {
                    int val = v[row][i - 1] - no - tmp_v[row] - tmp_v[row + 1];
                    if (val < 0 || val > 9) {
                        flag = 0;
                        break;
                    }
                    no = val;
                    prev_col += val * p;
                    p *= 10;
                }

                if (flag == 1 && dp[prev_col][i - 1] != -1) {
                    dp[col][i] = prev_col;
                    if (i == n) {
                        fin = col;
                    }
                    break;
                }
            }
            if (fin != -1) {
                break;
            }
        }
    }

    vector<int> ans;
    int ind = n;
    while (sz(ans) != n + 1) {
        ans.pb(fin);
        fin = dp[fin][ind];
        ind--;
    }

    reverse(all(ans));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << ans[j] % 10;
            ans[j] /= 10;
        }
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}