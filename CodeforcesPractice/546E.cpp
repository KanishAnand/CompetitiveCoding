#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

struct Dinic {
    struct Edge {
        lli to, rev;
        lli c, oc;
        lli flow() { return max(oc - c, 0LL); }  // if you need flows
    };

    vector<lli> lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(lli n) : lvl(n), ptr(n), q(n), adj(n) {}
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

void solve() {
    lli n, m, a, b;
    cin >> n >> m;

    lli suma = 0, sumb = 0;
    vector<lli> va, vb;
    va.pb(0);
    vb.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        suma += a;
        va.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        sumb += a;
        vb.pb(a);
    }

    lli source = 0, sink = 2 * n + 1;
    lli INF = 1e6;
    struct Dinic graph(2 * n + 2);

    for (lli i = 1; i <= n; i++) {
        graph.addEdge(i, n + i, INF);
        graph.addEdge(source, i, va[i]);
        graph.addEdge(n + i, sink, vb[i]);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        graph.addEdge(a, n + b, INF);
        graph.addEdge(b, n + a, INF);
    }

    lli mxFlow = graph.calc(source, sink);
    if (mxFlow == suma && suma == sumb) {
        cout << "YES" << endl;
        vector<vector<lli>> flows(n + 2, vector<lli>(n + 2, 0));
        for (lli i = 1; i <= n; i++) {
            for (auto edg : graph.adj[i]) {
                if (edg.to > n) {
                    flows[i][edg.to - n] = edg.flow();
                }
            }
        }

        for (lli i = 1; i <= n; i++) {
            for (lli j = 1; j <= n; j++) {
                cout << flows[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
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