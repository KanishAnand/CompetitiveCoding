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
vector<vector<lli>> adj;
vector<lli> v, vis;
stack<lli> st;
lli cur = 0;

lli fun(lli a) {
    // if (vis[a] != 0) {
    // }
    if (adj[a].size() == 0) {
        if (a == v[cur]) {
            ++cur;
            vis[a] = 2;
            st.pop();
            return 2;
        } else {
            vis[a] = 0;
            return 0;
        }
    }
    fr(i, 0, adj[a].size()) {
        if (vis[adj[a][i]] == 0) {
            vis[adj[a][i]] = 1;
            st.pb(a);
            vis[a] = fun(a);
            if (vis[a] == 2) {
                st.pb(a)
            } else {
                st.pop();
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, k = 0;
    cin >> n;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);

    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    fr(i, 1, n + 1) {
        if (adj[i].size() == 0) {
            ++k;
        }
    }

    fr(i, 0, k) {
        cin >> a;
        v.pb(a);
    }

    fun(1);
    if (cur == k) {
    } else {
        cout << "-1" << endl;
    }
    rt;
}
