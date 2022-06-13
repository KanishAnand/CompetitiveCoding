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
    lli n, a, m, x, y;
    cin >> n >> m;
    vector<lli> v(n + 2, 0);
    vector<vector<lli>> robo(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 1; i <= n; i++) {
        cin >> a;
        v[a - 1] = i;
    }

    if (m == 0) {
        lli cnt = 0;
        for (lli i = 0; i < n; i++) {
            while (v[i] != i + 1) {
                lli tmp = v[v[i] - 1];
                v[v[i] - 1] = v[i];
                v[i] = tmp;
                cnt++;
            }
        }
        cout << cnt << endl;
        return;
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

    lli ll = 54321;
    vector<lli> cost(ll + 2, -1), vis(ll + 2, 0);
    vector<vector<lli>> arr(ll + 2);

    lli beg = 0, p = 1;
    for (lli i = 0; i < n; i++) {
        // if (v[i] == i + 1) {
        //     beg += p*v[i];
        // }
        beg += p * v[i];
        p *= 10;
    }

    arr[beg] = v;
    cost[beg] = 0;
    deque<lli> dqu;
    dqu.push_front(beg);

    while (!dqu.empty()) {
        lli a = dqu.front();
        dqu.pop_front();
        if (vis[a] == 1) {
            continue;
        }
        // if (a == pow(2, n) - 1) {
        //     break;
        // }
        vis[a] = 1;
        vector<lli> ch = arr[a];

        for (lli i = 0; i < n; i++) {
            for (lli j = i + 1; j < n; j++) {
                // lli flag1 = 0, flag2 = 0;
                // if (ch[i] == i + 1) {
                //     flag1 = 1;
                // }
                // if (ch[j] == j + 1) {
                //     flag2 = 1;
                // }

                lli tmp = ch[j];
                ch[j] = ch[i];
                ch[i] = tmp;

                lli val = 0;
                lli dis = cost[a];

                // if (ch[i] == i + 1) {
                //     val += pow(10, i);
                // }
                // if (ch[j] == j + 1) {
                //     val += pow(10, j);
                // }
                // if (ch[i] != i + 1 && flag1 == 1) {
                //     val -= pow(10, i);
                // }
                // if (ch[j] != j + 1 && flag2 == 1) {
                //     val -= pow(10, j);
                // }
                lli pp = 1;
                for (lli kk = 0; kk < n; kk++) {
                    val += pp * ch[kk];
                    pp *= 10;
                }

                if (robo[i][j] == 0) {
                    dis++;
                    if (cost[val] == -1 || cost[val] > dis) {
                        cost[val] = dis;
                        dqu.push_back(val);
                        arr[val] = ch;
                    }
                } else {
                    if (cost[val] == -1 || cost[val] > dis) {
                        cost[val] = dis;
                        dqu.push_front(val);
                        arr[val] = ch;
                    }
                }

                tmp = ch[j];
                ch[j] = ch[i];
                ch[i] = tmp;
            }
        }
    }

    lli val = 0, b = 1;
    p = 1;
    for (lli i = 0; i < n; i++) {
        val += p * b;
        p *= 10;
        b++;
    }

    lli ans = cost[val];
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
