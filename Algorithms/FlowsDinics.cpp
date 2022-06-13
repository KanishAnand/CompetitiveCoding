// https://codeforces.com/problemset/problem/653/D
// for also getting value of flow of edges/ accessing edges of flow graph see https://codeforces.com/contest/546/problem/E
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
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);

struct Dinic {
    struct Edge {
        lli to, rev;
        lli c, oc;
        lli flow() { return max(oc - c, 0LL); }  // if you need flows
    };

    vector<lli> lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(lli n) : lvl(n), ptr(n), q(n), adj(n) {}

    // push edges with 0 based indexing
    void addEdge(lli a, lli b, lli c, lli rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }

    lli dfs(lli v, lli t, lli f) {
        if (v == t || !f) return f;
        for (lli& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (lli p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }

    lli calc(lli s, lli t) {
        lli flow = 0;
        q[0] = s;
        for (lli L = 0; L < 31; L++)
            do {  // 'lli L=30' maybe faster for random data
                lvl = ptr = vector<lli>(sz(q));
                lli qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    lli v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (lli p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(lli a) { return lvl[a] != 0; }
};

struct Edge {
    lli a, b, c;
};

void solve() {
    lli n, m, x, a, b, c;
    cin >> n >> m >> x;
    vector<lli> v;

    vector<struct Edge> edges;
    for (lli i = 0; i < m; i++) {
        struct Edge edg;
        cin >> edg.a >> edg.b >> edg.c;
        edg.a--;
        edg.b--;
        edges.pb(edg);
    }

    double beg = 0, end = 1e6 + 2;

    double ans, prec = 1e-12, lim = 100;
    while (beg <= end && lim--) {
        double mid = (beg + end) / 2;

        struct Dinic graph(n);
        for (auto edg : edges) {
            lli w = edg.c / mid;
            graph.addEdge(edg.a, edg.b, w);
        }

        lli mx = graph.calc(0, n - 1);

        if (mx >= x) {
            ans = mid;
            beg = mid + prec;
        } else {
            end = mid - prec;
        }
    }

    cout << fixed << setprecision(10);
    ans *= x;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}