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

vector<lli> king, rankk, extra;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] >= rankk[b]) {
        rankk[a] += rankk[b];
        extra[a] += extra[b];
        king[b] = king[a];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
        extra[b] += extra[a];
    }
}

void solve() {
    lli n, a, b, m;
    cin >> n >> m;
    king.clear();
    rankk.clear();
    extra.clear();

    vector<lli> deg(n + 2, 0);
    vector<pair<lli, lli>> store;

    if (n == 1) {
        cout << "0 0" << endln;
        return;
    }

    king.resize(n + 2);
    rankk.resize(n + 2, 1);
    extra.resize(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    lli p, q;

    vector<vector<lli>> adj(n + 2);

    vector<pair<lli, lli>> extra_edges, tree_edges;
    vector<lli> one_edges;

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
        store.pb({a, b});
        p = find(a);
        q = find(b);
        if (p != q) {
            merge(p, q);
        } else {
            extra[p]++;
            extra_edges.pb({a, b});
        }
    }

    set<lli> st;

    for (lli i = 1; i <= n; i++) {
        st.insert(find(i));
    }

    // no : number of components
    lli no = st.size();
    if (no == 1) {
        cout << "0 " << store.size() << endln;
        for (lli i = 0; i < store.size(); i++) {
            cout << store[i].first << " " << store[i].second << endln;
        }
        return;
    }

    vector<lli> cnt(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        cnt[find(i)]++;
    }

    lli ex = 0, tre = 0, one = 0;
    lli ll = 0;

    for (auto i : st) {
        if (extra[i] != 0) {
            ll++;
            ex += extra[i];
        } else if (cnt[i] > 1) {
            tree_edges.pb({i, adj[i][0]});
            tre++;
        } else if (cnt[i] == 1) {
            one_edges.pb(i);
            one++;
        }
    }

    lli ans = 0;

    if (ll == 0) {
        ans = (tre + one - 1) * 2;

        // join all ones
        for (lli i = 0; i < one_edges.size(); i++) {
            deg[one_edges[i]]++;
        }
        // join all trees
        for (lli i = 1; i < tree_edges.size(); i++) {
            deg[tree_edges[i].first]++;
        }

        // join both
        if (tre != 0) {
            deg[tree_edges[0].first] +=
                one_edges.size() + tree_edges.size() - 1;
        }
    }

    else if (ll == 1) {
        p = min(tre, ex);
        tre -= p;
        ex -= p;
        lli tree_ptr = 0, ex_ptr = 0, one_ptr = 0;

        tree_ptr = p;

        p = min(one / 2, ex);
        ans += p * 2;
        ex -= p;
        one -= p * 2;

        for (lli i = 0; i < 2 * p; i++) {
            deg[one_edges[one_ptr]]++;
            one_ptr++;
        }

        lli val = tree_edges.size() - tree_ptr + one_edges.size() - one_ptr;

        lli no = extra_edges[0].first;

        for (lli i = tree_ptr; i < tree_edges.size(); i++) {
            deg[no]++;
            deg[tree_edges[i].first]++;
        }

        for (lli i = one_ptr; i < one_edges.size(); i++) {
            deg[no]++;
            deg[one_edges[i]]++;
        }

        ans += 2 * (tre + one);
    }

    else {
        ex = ex - (ll - 1);

        p = min(tre, ex);
        tre -= p;
        ex -= p;
        lli tree_ptr = 0, ex_ptr = 0, one_ptr = 0;

        tree_ptr = p;

        p = min(one / 2, ex);
        ans += p * 2;
        ex -= p;
        one -= p * 2;

        for (lli i = 0; i < 2 * p; i++) {
            deg[one_edges[one_ptr]]++;
            one_ptr++;
        }

        lli val = tree_edges.size() - tree_ptr + one_edges.size() - one_ptr;

        lli no = extra_edges[0].first;

        for (lli i = tree_ptr; i < tree_edges.size(); i++) {
            deg[no]++;
            deg[tree_edges[i].first]++;
        }

        for (lli i = one_ptr; i < one_edges.size(); i++) {
            deg[no]++;
            deg[one_edges[i]]++;
        }

        ans += 2 * (tre + one);
    }

    vector<pair<lli, lli>> store_all;
    vector<pair<lli, lli>> all;

    for (lli i = 1; i <= n; i++) {
        store_all.pb({deg[i], i});
    }

    sort(store_all.rbegin(), store_all.rend());
    lli ptr = 0, val, ptr2 = 0, vv;

    while (1) {
        while (ptr < n && deg[store_all[ptr].second] == 0) {
            ptr++;
        }
        if (ptr >= n) {
            break;
        }

        val = store_all[ptr].second;
        ptr2 = max(ptr2, ptr + 1);

        while (ptr2 < n && deg[store_all[ptr2].second] == 0) {
            ptr2++;
        }
        if (ptr2 >= n) {
            break;
        }
        vv = store_all[ptr2].second;
        deg[vv]--;
        deg[val]--;
        all.pb({vv, val});
        ptr2++;
        if (ptr2 >= n) {
            break;
        }
    }

    set<pair<lli, lli>> stt;

    for (lli i = 1; i <= n; i++) {
        if (deg[i] != 0) {
            stt.insert({deg[i], i});
        }
    }

    while (stt.size() > 0) {
        auto it = stt.end();
        it--;
        lli val1 = it->second;
        it--;
        lli val2 = it->second;
        all.pb({val1, val2});
        stt.erase({deg[val1], val1});
        stt.erase({deg[val2], val2});
        deg[val1]--;
        if (deg[val1] != 0) {
            stt.insert({deg[val1], val1});
        }
        deg[val2]--;
        if (deg[val2] != 0) {
            stt.insert({deg[val2], val2});
        }
    }

    cout << ans << " " << all.size() << endln;
    for (lli i = 0; i < all.size(); i++) {
        cout << all[i].first << " " << all[i].second << endln;
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