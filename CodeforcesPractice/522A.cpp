#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

void lower(string &s) {
    for (lli i = 0; i < s.length(); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    string st1, st2, st3;
    map<string, lli> v;
    vector<vector<lli>> adj;
    cin >> n;
    adj.resize(n + 2);
    v["polycarp"] = 1;
    lli cnt = 1;
    fr(i, 0, n) {
        cin >> st1;
        cin >> st2;
        cin >> st3;
        lower(st1);
        lower(st3);
        // cout << st1 << " " << st3 << endl;
        // if (v[st3] != 0) {
        //     if (v[st1] != 0) {
        ++cnt;
        v[st1] = cnt;
        adj[v[st3]].pb(v[st1]);
        //     }
        // }
    }

    queue<lli> qu;
    lli ans, maxx = -1;
    vector<lli> level(n + 2, 0), vis(n + 2, 0);

    for (lli i = 1; i <= cnt; i++) {
        if (vis[i] == 0) {
            vis[1] = 1;
            qu.push(i);
            level[i] = 1;
            ans = 1;

            while (!qu.empty()) {
                a = qu.front();
                for (lli j = 0; j < adj[a].size(); j++) {
                    if (vis[adj[a][j]] == 0) {
                        qu.push(adj[a][j]);
                        level[adj[a][j]] = level[a] + 1;
                        ans = level[a] + 1;
                    }
                }
                qu.pop();
            }
            if (ans > maxx) {
                maxx = ans;
            }
        }
    }
    cout << maxx << endl;
    rt;
}