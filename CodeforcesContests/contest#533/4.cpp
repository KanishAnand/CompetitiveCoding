#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

vector<string> store;
vector<lli> s;
lli n, m;

void solve() {
    lli a, p, b;
    cin >> n >> m >> p;

    s.pb(0);
    for (lli i = 1; i <= p; i++) {
        cin >> a;
        s.pb(a);
    }

    string st;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        store.pb(st);
    }

    vector<vector<pair<lli, lli>>> v(p + 2);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (store[i][j] != '.' && store[i][j] != '#') {
                lli val = store[i][j] - '0';
                v[val].pb({i, j});
            }
        }
    }

    while (1) {
        lli val = 0;
        for (lli i = 1; i <= p; i++) {
            queue<pair<lli, pair<lli, lli>>> qu;
            for (auto pp : v[i]) {
                qu.push({0, {pp.first, pp.second}});
            }

            char no = (char)(i + '0');
            vector<pair<lli, lli>> tmp;

            while (!qu.empty()) {
                auto el = qu.front();
                qu.pop();
                lli dis = el.first;
                if (dis == s[i]) {
                    break;
                }
                a = el.second.first;
                b = el.second.second;

                if (a != 0 && store[a - 1][b] == '.') {
                    store[a - 1][b] = no;
                    qu.push({dis + 1, {a - 1, b}});
                    tmp.pb({a - 1, b});
                }

                if (a != n - 1 && store[a + 1][b] == '.') {
                    store[a + 1][b] = no;
                    qu.push({dis + 1, {a + 1, b}});
                    tmp.pb({a + 1, b});
                }

                if (b != 0 && store[a][b - 1] == '.') {
                    store[a][b - 1] = no;
                    qu.push({dis + 1, {a, b - 1}});
                    tmp.pb({a, b - 1});
                }

                if (b != m - 1 && store[a][b + 1] == '.') {
                    store[a][b + 1] = no;
                    qu.push({dis + 1, {a, b + 1}});
                    tmp.pb({a, b + 1});
                }
            }

            v[i] = tmp;
            val += tmp.size();
        }

        if (val == 0) {
            break;
        }
    }

    vector<lli> ans(p + 2, 0);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (store[i][j] != '.' && store[i][j] != '#') {
                lli val = store[i][j] - '0';
                ans[val]++;
            }
        }
    }

    for (lli i = 1; i <= p; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}