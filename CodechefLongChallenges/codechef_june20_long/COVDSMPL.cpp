#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

lli n;
vector<vector<bool>> ans;
vector<vector<lli>> dp, dp2, dp3, dp4;

void query(lli a, lli b, lli c, lli d, lli flag) {
    lli x;
    if (flag == 1) {
        a = c;
        b = 1;
        c = n;
        d = d;
    }
    if (flag == 2) {
        c = a;
        d = n;
        a = 1;
        b = b;
    }
    if (flag == 3) {
        a = c;
        b = d;
        c = n;
        d = n;
    }

    cout << "1 " << a << " " << b << " " << c << " " << d << endl;
    cin >> x;
    if (a == 1 && b == 1 && c == n && d == n) {
        dp[n][n] = x;
        dp2[1][n] = x;
        dp3[n][1] = x;
        dp4[1][1] = x;
    }
    if (flag == 0) {
        dp[c][d] = x;
    } else if (flag == 1) {
        dp2[a][d] = x;
    } else if (flag == 2) {
        dp3[c][b] = x;
    } else if (flag == 3) {
        dp4[a][b] = x;
    }
}

void solve() {
    lli p;
    cin >> n >> p;

    ans.clear();
    dp.clear();
    dp2.clear();
    dp3.clear();
    dp4.clear();

    ans.resize(n + 2, vector<bool>(n + 2, 0));
    dp.resize(n + 2, vector<lli>(n + 2, -1));
    dp2.resize(n + 2, vector<lli>(n + 2, -1));
    dp3.resize(n + 2, vector<lli>(n + 2, -1));
    dp4.resize(n + 2, vector<lli>(n + 2, -1));

    for (lli i = 0; i <= n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
        dp2[0][i] = 0;
        dp2[i][0] = 0;
        dp3[0][i] = 0;
        dp3[i][0] = 0;
        dp4[0][i] = 0;
        dp4[i][0] = 0;
    }

    for (lli col = n; col >= 30; col--) {
        for (lli row = n; row >= 30; row--) {
            if (dp[row][col] == -1) {
                query(1, 1, row, col, 0);
            }
            if (dp[row][col] == 0) {
                for (lli ii = row; ii >= 0; ii--) {
                    for (lli jj = col; jj >= 0; jj--) {
                        dp[ii][jj] = 0;
                    }
                }
            }

            if (dp[row][col - 1] == -1) {
                query(1, 1, row, col - 1, 0);
            }
            if (dp[row][col - 1] == 0) {
                for (lli ii = row; ii >= 0; ii--) {
                    for (lli jj = col - 1; jj >= 0; jj--) {
                        dp[ii][jj] = 0;
                    }
                }
            }

            if (dp[row - 1][col] == -1) {
                query(1, 1, row - 1, col, 0);
            }
            if (dp[row - 1][col] == 0) {
                for (lli ii = row - 1; ii >= 0; ii--) {
                    for (lli jj = col; jj >= 0; jj--) {
                        dp[ii][jj] = 0;
                    }
                }
            }

            if (dp[row - 1][col - 1] == -1) {
                query(1, 1, row - 1, col - 1, 0);
            }
            if (dp[row - 1][col - 1] == 0) {
                for (lli ii = row - 1; ii >= 0; ii--) {
                    for (lli jj = col - 1; jj >= 0; jj--) {
                        dp[ii][jj] = 0;
                    }
                }
            }

            lli val1 = dp[row][col] - dp[row][col - 1];
            lli val2 = dp[row - 1][col] - dp[row - 1][col - 1];
            if (val1 != val2) {
                ans[row][col] = 1;
            }

            if (val1 == 0 || val2 == 0) {
                break;
            }
        }
    }

    for (lli col = 1; col <= 29; col++) {
        for (lli row = n; row >= 30; row--) {
            if (dp3[row][col] == -1) {
                query(row, col, 1, n, 2);
            }
            if (dp3[row][col] == 0) {
                for (lli ii = row; ii >= 0; ii--) {
                    for (lli jj = col; jj <= n; jj++) {
                        dp3[ii][jj] = 0;
                    }
                }
            }

            if (dp3[row][col + 1] == -1) {
                query(row, col + 1, 1, n, 2);
            }
            if (dp3[row][col + 1] == 0) {
                for (lli ii = row; ii >= 0; ii--) {
                    for (lli jj = col + 1; jj <= n; jj++) {
                        dp3[ii][jj] = 0;
                    }
                }
            }

            if (dp3[row - 1][col] == -1) {
                query(row - 1, col, 1, n, 2);
            }
            if (dp3[row - 1][col] == 0) {
                for (lli ii = row - 1; ii >= 0; ii--) {
                    for (lli jj = col; jj <= n; jj++) {
                        dp3[ii][jj] = 0;
                    }
                }
            }

            if (dp3[row - 1][col + 1] == -1) {
                query(row - 1, col + 1, 1, n, 2);
            }
            if (dp3[row - 1][col + 1] == 0) {
                for (lli ii = row - 1; ii >= 0; ii--) {
                    for (lli jj = col + 1; jj <= n; jj++) {
                        dp3[ii][jj] = 0;
                    }
                }
            }

            lli val1 = dp3[row][col] - dp3[row][col + 1];
            lli val2 = dp3[row - 1][col] - dp3[row - 1][col + 1];
            if (val1 != val2) {
                ans[row][col] = 1;
            }

            if (val1 == 0 || val2 == 0) {
                break;
            }
        }
    }

    for (lli col = n; col >= 30; col--) {
        for (lli row = 1; row <= 29; row++) {
            if (dp2[row][col] == -1) {
                query(n, 1, row, col, 1);
            }
            if (dp2[row][col] == 0) {
                for (lli ii = row; ii <= n; ii++) {
                    for (lli jj = col; jj >= 0; jj--) {
                        dp2[ii][jj] = 0;
                    }
                }
            }

            if (dp2[row][col - 1] == -1) {
                query(n, 1, row, col - 1, 1);
            }
            if (dp2[row][col - 1] == 0) {
                for (lli ii = row; ii <= n; ii++) {
                    for (lli jj = col - 1; jj >= 0; jj--) {
                        dp2[ii][jj] = 0;
                    }
                }
            }

            if (dp2[row + 1][col] == -1) {
                query(n, 1, row + 1, col, 1);
            }
            if (dp2[row + 1][col] == 0) {
                for (lli ii = row + 1; ii <= n; ii++) {
                    for (lli jj = col; jj >= 0; jj--) {
                        dp2[ii][jj] = 0;
                    }
                }
            }

            if (dp2[row + 1][col - 1] == -1) {
                query(n, 1, row + 1, col - 1, 1);
            }
            if (dp2[row + 1][col - 1] == 0) {
                for (lli ii = row + 1; ii <= n; ii++) {
                    for (lli jj = col - 1; jj >= 0; jj--) {
                        dp2[ii][jj] = 0;
                    }
                }
            }

            lli val1 = dp2[row][col] - dp2[row][col - 1];
            lli val2 = dp2[row + 1][col] - dp2[row + 1][col - 1];
            if (val1 != val2) {
                ans[row][col] = 1;
            }

            if (val1 == 0 || val2 == 0) {
                break;
            }
        }
    }

    for (lli col = 1; col <= 29; col++) {
        for (lli row = 1; row <= 29; row++) {
            if (dp4[row][col] == -1) {
                query(n, n, row, col, 3);
            }
            if (dp4[row][col] == 0) {
                for (lli ii = row; ii <= n; ii++) {
                    for (lli jj = col; jj <= n; jj++) {
                        dp4[ii][jj] = 0;
                    }
                }
            }

            if (dp4[row][col + 1] == -1) {
                query(n, n, row, col + 1, 3);
            }
            if (dp4[row][col + 1] == 0) {
                for (lli ii = row; ii <= n; ii++) {
                    for (lli jj = col + 1; jj <= n; jj++) {
                        dp4[ii][jj] = 0;
                    }
                }
            }

            if (dp4[row + 1][col] == -1) {
                query(n, n, row + 1, col, 3);
            }
            if (dp4[row + 1][col] == 0) {
                for (lli ii = row + 1; ii <= n; ii++) {
                    for (lli jj = col; jj <= n; jj++) {
                        dp4[ii][jj] = 0;
                    }
                }
            }

            if (dp4[row + 1][col + 1] == -1) {
                query(n, n, row + 1, col + 1, 3);
            }
            if (dp4[row + 1][col + 1] == 0) {
                for (lli ii = row + 1; ii <= n; ii++) {
                    for (lli jj = col + 1; jj <= n; jj++) {
                        dp4[ii][jj] = 0;
                    }
                }
            }

            lli val1 = dp4[row][col] - dp4[row][col + 1];
            lli val2 = dp4[row + 1][col] - dp4[row + 1][col + 1];
            if (val1 != val2) {
                ans[row][col] = 1;
            }

            if (val1 == 0 || val2 == 0) {
                break;
            }
        }
    }

    lli x;

    cout << "2" << endl;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cin >> x;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}