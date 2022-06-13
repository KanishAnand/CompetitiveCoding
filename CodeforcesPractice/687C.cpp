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

void solve() {
    lli n, a, k;
    cin >> n >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    // vector<vector<set<lli>>> store(n + 2, vector<set<lli>>(503, set<lli>));

    vector<vector<set<lli>>> store(n + 2, vector<set<lli>>(503));

    store[0][v[0]].insert(v[0]);
    store[0][v[0]].insert(0);

    for (lli i = 1; i < n; i++) {
        for (lli j = 0; j <= k; j++) {
            for (auto it = store[i - 1][j].begin(); it != store[i - 1][j].end();
                 it++) {
                store[i][j].insert(*it);
            }
        }

        for (lli j = 0; j <= k; j++) {
            if (j + v[i] > k) {
                continue;
            }
            for (auto it = store[i - 1][j].begin(); it != store[i - 1][j].end();
                 it++) {
                store[i][j + v[i]].insert(v[i]);
                store[i][j + v[i]].insert(*it);
                store[i][j + v[i]].insert(*it + v[i]);
            }
        }
        store[i][v[i]].insert(v[i]);
    }

    set<lli> st;
    st.insert(0);

    for (auto it = store[n - 1][k].begin(); it != store[n - 1][k].end(); it++) {
        st.insert(*it);
    }

    cout << st.size() << endl;
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
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