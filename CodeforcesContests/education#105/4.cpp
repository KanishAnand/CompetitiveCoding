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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

lli cnt, n;
vector<lli> king, rankk;
vector<pair<lli, lli>> employee;
vector<pair<lli, lli>> edges;
vector<vector<lli>> salaries;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] > rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

void fun(vector<lli> &comp, lli parent) {
    lli mx = -1;
    for (lli i = 0; i < sz(comp); i++) {
        for (lli j = i + 1; j < sz(comp); j++) {
            mx = max(mx, salaries[comp[i]][comp[j]]);
        }
    }

    for (lli i = 0; i < sz(comp); i++) {
        king[comp[i]] = comp[i];
        rankk[comp[i]] = 1;
    }

    // cout << mx << endl;
    for (lli i = 0; i < sz(comp); i++) {
        for (lli j = i + 1; j < sz(comp); j++) {
            lli p = salaries[comp[i]][comp[j]];
            if (p != mx) {
                // cout << comp[i] << " " << comp[j] << " " << p << endl;
                merge(find(comp[i]), find(comp[j]));
            }
        }
    }

    set<lli> st;
    for (lli i = 0; i < sz(comp); i++) {
        lli p = comp[i];
        // cout << comp[i] << " d " << find(p) << endl;
        st.insert(find(p));
    }

    // cout << sz(st) << endl;
    if (sz(st) == 1) {
        for (lli i = 0; i < sz(comp); i++) {
            lli p = comp[i];
            edges.pb({p, parent});
        }
        return;
    }

    cnt++;
    employee.pb({cnt, mx});

    if (parent != -1) {
        edges.pb({cnt, parent});
    }

    lli par = cnt;
    for (auto king : st) {
        vector<lli> new_comp;
        for (lli i = 0; i < sz(comp); i++) {
            lli p = find(comp[i]);
            if (p != king) {
                continue;
            }
            new_comp.pb(comp[i]);
        }
        fun(new_comp, par);
    }
}

void solve() {
    lli a;
    cin >> n;
    king.resize(n + 2);
    rankk.resize(n + 2);
    cnt = n;
    salaries.resize(n + 2, vector<lli>(n + 2, 0));

    // 1 based indexing
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            cin >> a;
            salaries[i][j] = a;
        }
    }

    vector<lli> comp;
    for (lli i = 1; i <= n; i++) {
        comp.pb(i);
    }

    fun(comp, -1);

    //ans
    cout << cnt << endl;
    for (lli i = 1; i <= n; i++) {
        cout << salaries[i][i] << " ";
    }

    sort(all(employee));
    for (auto pr : employee) {
        cout << pr.second << " ";
    }
    cout << endl;

    cout << n + 1 << endl;

    for (auto edg : edges) {
        cout << edg.first << " " << edg.second << endl;
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