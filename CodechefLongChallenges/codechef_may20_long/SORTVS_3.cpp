#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

void solve() {
    lli n, a, m, x, y;
    cin >> n >> m;
    vector<lli> v(n + 2, 0);
    vector<vector<lli>> robo(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 1; i <= n; i++) {
        cin >> a;
        v[a - 1] = i;
    }

    for (lli i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        if (x > y) {
            swap(x, y);
        }
        robo[x][y] = 1;
    }

    vector<lli> cost(pow(2, n) + 2, -1), vis(pow(2, n) + 2, 0);

    lli beg = 0, p = 1;
    for (lli i = 0; i < n; i++) {
        if (v[i] == i + 1) {
            beg += p;
        }
        p *= 2;
    }

    cost[beg] = 0;
    deque<pair<lli, vector<lli>>> dqu;
    dqu.push_front({beg, v});

    while (!dqu.empty()) {
        pair<lli, vector<lli>> pr = dqu.front();
        lli a = pr.first;
        dqu.pop_front();
        if (vis[a] == 1) {
            continue;
        }
        // if (a == pow(2, n) - 1) {
        //     break;
        // }
        vis[a] = 1;
        vector<lli> ch = pr.second;

        for (lli i = 0; i < n; i++) {
            for (lli j = i + 1; j < n; j++) {
                lli flag1 = 0, flag2 = 0;
                if (ch[i] == i + 1) {
                    flag1 = 1;
                }
                if (ch[j] == j + 1) {
                    flag2 = 1;
                }

                lli tmp = ch[j];
                ch[j] = ch[i];
                ch[i] = tmp;

                lli val = a, dis = cost[a];

                if (ch[i] == i + 1) {
                    val += pow(2, i);
                }
                if (ch[j] == j + 1) {
                    val += pow(2, j);
                }
                if (ch[i] != i + 1 && flag1 == 1) {
                    val -= pow(2, i);
                }
                if (ch[j] != j + 1 && flag2 == 1) {
                    val -= pow(2, j);
                }

                if (robo[i][j] == 0) {
                    dis++;
                    if (cost[val] == -1 || cost[val] > dis) {
                        cost[val] = dis;
                        dqu.push_back({val, ch});
                    }
                } else {
                    if (cost[val] == -1 || cost[val] > dis) {
                        cost[val] = dis;
                        dqu.push_front({val, ch});
                    }
                }

                tmp = ch[j];
                ch[j] = ch[i];
                ch[i] = tmp;
            }
        }
    }

    lli ans = cost[pow(2, n) - 1];
    cout << ans << endl;
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