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

lli x, d;
vector<vector<lli>> adj;
vector<lli> vv, level, v;
vector<vector<lli>> seg;

void build(lli pos, lli l, lli r) {
    if (l == r) {
        seg[pos].push_back(v[l]);
        return;
    }

    lli mid = (l + r) / 2;

    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);

    /* merging left and right child in sorted order */
    merge(seg[2 * pos].begin(), seg[2 * pos].end(), seg[2 * pos + 1].begin(),
          seg[2 * pos + 1].end(), back_inserter(seg[pos]));
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        auto it = upper_bound(seg[pos].begin(), seg[pos].end(), end);
        lli val = seg[pos].end() - it;
        return val;
    }

    lli mid = (l + r) / 2;
    return query(2 * pos, beg, end, l, mid) +
           query(2 * pos + 1, beg, end, mid + 1, r);
}

void solve() {
    lli n, a;
    cin >> n;
    adj.clear();
    v.clear();
    vv.clear();
    level.clear();
    seg.clear();

    seg.resize(4 * n + 2);
    adj.resize(n + 2);
    level.resize(n + 2, 0);

    for (lli i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
        adj[i].pb(a);
    }

    vv.pb(0);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        vv.pb(a);
    }

    lli inf = n + 10;
    v.resize(n + 2, inf);
    map<lli, lli> mp;

    for (lli i = n; i >= 1; i--) {
        lli val = vv[i];
        if (mp[val] != 0) {
            v[i] = mp[val];
        }
        mp[val] = i;
    }

    build(1, 1, n);

    lli q;
    cin >> q;
    lli ans = 0;

    while (q--) {
        cin >> x >> d;
        x = x ^ ans;
        d = d ^ ans;
        lli pp = min(n, x + d);
        ans = query(1, x, pp, 1, n);
        cout << ans << endl;
    }
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