#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

stack<lli> st;
vector<lli> vis, v, level;
vector<vector<lli>> adj;
lli k, n, m;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 1 && level[a] - level[val] > 1) {
            lli pp = level[a] - level[val] + 1;
            if (pp <= k) {
                lli p = a;
                v.pb(p);
                while (p != val) {
                    st.pop();
                    p = st.top();
                    v.pb(p);
                }
                cout << "2" << endl;
                cout << sz(v) << endl;
                for (lli i = 0; i < v.size(); i++) {
                    cout << v[i] << " ";
                }
                cout << endl;
                exit(0);
            }
        }
    }

    if (st.size() >= k) {
        while (!st.empty()) {
            lli p = st.top();
            v.pb(p);
            st.pop();
        }
        cout << "1" << endl;
        lli cnt = 0;
        lli vv = k / 2 + k % 2;
        for (lli i = 0; i < v.size(); i += 2) {
            cout << v[i] << " ";
            cnt++;
            if (cnt == vv) {
                break;
            }
        }
        cout << endl;
        exit(0);
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            level[val] = level[a] + 1;
            st.push(val);
            dfs(val);
            if (st.empty() != 1) {
                st.pop();
            }
            vis[val] = 2;
        }
    }
}

void solve() {
    lli a, b;
    cin >> n >> m >> k;
    adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    if (m == n - 1) {
        vector<lli> v1, v2;
        queue<lli> qu;
        qu.push(1);
        vis[1] = 1;
        v1.pb(1);
        vector<bool> flag(n + 2, 0);
        flag[1] = 0;

        while (!qu.empty()) {
            a = qu.front();
            qu.pop();
            for (auto val : adj[a]) {
                if (vis[val] == 0) {
                    qu.push(val);
                    vis[val] = 1;
                    if (flag[a] == 0) {
                        flag[val] = 1;
                        v2.pb(val);
                    } else {
                        flag[val] = 0;
                        v1.pb(val);
                    }
                }
            }
        }

        cout << "1" << endl;
        if (sz(v2) > sz(v1)) {
            lli cnt = 0;
            lli val = k / 2 + k % 2;
            for (lli i = 0; i < sz(v2); i++) {
                cout << v2[i] << " ";
                cnt++;
                if (cnt == val) {
                    break;
                }
            }
            cout << endl;
        } else {
            lli cnt = 0;
            lli val = k / 2 + k % 2;
            for (lli i = 0; i < sz(v1); i++) {
                cout << v1[i] << " ";
                cnt++;
                if (cnt == val) {
                    break;
                }
            }
            cout << endl;
        }
    } else {
        level.resize(n + 2, 0);
        vis[1] = 1;
        level[1] = 1;
        st.push(1);
        dfs(1);
        vis[1] = 2;
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