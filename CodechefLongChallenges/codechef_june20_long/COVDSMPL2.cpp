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

lli n, p;
vector<vector<bool>> ans;
lli dp[62][62][62][62];

lli calc(lli a, lli b, lli c, lli d) {
    if (dp[a][b][c][d] != -1) {
        return 0;
    }
    lli aa = abs(c - a) + 1;
    lli bb = abs(d - b) + 1;
    lli val = (2 * n - aa) * (2 * n - bb);
    lli no = p * aa * bb;
    no /= 100;
    val = val / (no + 1);
    return val;
}

lli do_query(lli a, lli b, lli c, lli d) {
    lli x;
    if (dp[a][b][c][d] != -1) {
        return dp[a][b][c][d];
    }
    cout << "1 " << a << " " << b << " " << c << " " << d << endl;
    cin >> x;
    dp[a][b][c][d] = x;
    return x;
}

void query(lli a, lli b, lli c, lli d) {
    lli x;
    if (dp[a][b][c][d] != -1) {
        return;
    }

    lli val1, val2, val3, val4, val;
    val = calc(a, b, c, d);
    val1 = calc(a, 1, c, d) + calc(a, 1, c, b - 1);
    val2 = calc(1, b, c, d) + calc(1, b, a - 1, d);
    val3 = calc(a, b, c, n) + calc(a, d + 1, c, n);
    val4 = calc(a, b, n, d) + calc(c + 1, b, n, d);

    lli mn = min({val, val1, val2, val3, val4});
    if (mn == val) {
        dp[a][b][c][d] = do_query(a, b, c, d);
    } else if (mn == val1) {
        dp[a][b][c][d] = do_query(a, 1, c, d) - do_query(a, 1, c, b - 1);
    } else if (mn == val2) {
        dp[a][b][c][d] = do_query(1, b, c, d) - do_query(1, b, a - 1, d);
    } else if (mn == val3) {
        dp[a][b][c][d] = do_query(a, b, c, n) - do_query(a, d + 1, c, n);
    } else if (mn == val4) {
        dp[a][b][c][d] = do_query(a, b, n, d) - do_query(c + 1, b, n, d);
    }
}

void fun2(lli r1, lli r2, lli col) {
    lli x;
    if (r1 > r2) {
        return;
    }
    if (r1 == r2) {
        query(r1, col, r2, col);
        x = dp[r1][col][r2][col];
        if (x == 1) {
            ans[r1][col] = 1;
        }
        return;
    }

    query(r1, col, r2, col);
    x = dp[r1][col][r2][col];

    if (x == 0) {
        return;
    } else {
        lli mid = (r1 + r2) / 2;
        fun2(r1, mid, col);
        fun2(mid + 1, r2, col);
    }
}

void fun3(lli c1, lli c2, lli row) {
    lli x;
    if (c1 > c2) {
        return;
    }
    if (c1 == c2) {
        query(row, c1, row, c2);
        x = dp[row][c1][row][c2];
        if (x == 1) {
            ans[row][c1] = 1;
        }
        return;
    }

    query(row, c1, row, c2);
    x = dp[row][c1][row][c2];

    if (x == 0) {
        return;
    } else {
        lli mid = (c1 + c2) / 2;
        fun3(c1, mid, row);
        fun3(mid + 1, c2, row);
    }
}

void fun(lli r1, lli r2, lli c1, lli c2) {
    lli x;
    if (r1 > r2) {
        return;
    }
    if (c1 > c2) {
        return;
    }

    if (c1 == c2) {
        fun2(r1, r2, c1);
        return;
    }
    if (r1 == r2) {
        fun3(c1, c2, r1);
        return;
    }

    query(r1, c1, r2, c2);
    x = dp[r1][c1][r2][c2];

    if (x == 0) {
        return;
    } else {
        lli mid1 = (r1 + r2) / 2;
        lli mid2 = (c1 + c2) / 2;
        fun(r1, mid1, c1, mid2);
        fun(r1, mid1, mid2 + 1, c2);
        fun(mid1 + 1, r2, c1, mid2);
        fun(mid1 + 1, r2, mid2 + 1, c2);
    }
}

void solve() {
    cin >> n >> p;
    ans.clear();
    ans.resize(n + 2, vector<bool>(n + 2, 0));

    for (lli i = 0; i <= 61; i++) {
        for (lli j = 0; j <= 61; j++) {
            for (lli k = 0; k <= 61; k++) {
                for (lli l = 0; l <= 61; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    fun(1, n, 1, n);
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