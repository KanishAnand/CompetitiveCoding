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

lli n;

lli dist(lli a, lli b) {
    if (b > a) {
        return b - a;
    } else {
        lli val = b - 1 + n - a + 1;
        return val;
    }
}

void solve() {
    lli a, m, b, d, no;
    cin >> n >> m;
    lli cntt = 0;
    vector<multiset<pair<lli, lli>>> adj(n + 2), new_adj(n + 2);

    lli mx = -1;
    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        d = dist(a, b);
        adj[a].insert({d, b});
        mx = max(mx, sz(adj[a]));
    }

    for (lli i = 1; i <= n; i++) {
        if (mx != 1 && sz(adj[i]) == mx - 1) {
            auto it = adj[i].begin();
            d = it->first;
            no = it->second;
            new_adj[i].insert({d, no});
            cntt += (mx - 1);
            // cout << "1" << endl;
        }
        if (sz(adj[i]) == mx) {
            auto it = adj[i].begin();
            d = it->first;
            no = it->second;
            new_adj[i].insert({d, no});
            cntt += (mx - 1);
            if (mx != 1) {
                it++;
                d = it->first;
                no = it->second;
                new_adj[i].insert({d, no});
            }
            // cout << "2" << endl;
        }
        if (sz(adj[i]) < mx - 1) {
            cntt += sz(adj[i]);
            // cout << "3" << endl;
        }
    }

    vector<lli> ans;

    for (lli start = 1; start <= n; start++) {
        lli cnt = 0, cur = start;
        multiset<lli> st;
        vector<multiset<pair<lli, lli>>> adjtmp;
        adjtmp = new_adj;

        lli tmp = 0, flag = 0;

        if (mx > 1) {
            tmp = (mx - 1) * n;
        }

        cnt = cntt;

        while (flag == 0) {
            if (st.find(cur) != st.end()) {
                st.erase(cur);
            }

            if (mx != 1 && sz(adjtmp[cur]) != 0) {
                auto it = adjtmp[cur].end();
                it--;
                no = it->second;
                adjtmp[cur].erase(it);
                st.insert(no);
            }

            if (cur == n) {
                cur = 1;
            } else {
                cur++;
            }
            if (cur == start) {
                flag = 1;
            }
        }

        cur = start;

        while (1) {
            if (st.find(cur) != st.end()) {
                st.erase(cur);
            }
            if (st.empty() == 1 && cnt == m) {
                break;
            }

            if (adjtmp[cur].empty() == 0) {
                auto it = adjtmp[cur].end();
                it--;
                no = it->second;
                adjtmp[cur].erase(it);
                st.insert(no);
                cnt++;
            }
            tmp++;

            if (cur == n) {
                cur = 1;
            } else {
                cur++;
            }
        }

        ans.pb(tmp);
    }

    for (lli i = 0; i < ans.size(); i++) {
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