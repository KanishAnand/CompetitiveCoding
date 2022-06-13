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

void solve() {
    lli n, a, no;
    cin >> n;

    vector<vector<lli>> store(n);
    vector<lli> allEnd;
    for (lli i = 0; i < n; i++) {
        cin >> no;
        allEnd.pb(no);
        for (lli j = 0; j < no; j++) {
            cin >> a;
            store[i].pb(a);
        }
    }

    lli m;
    cin >> m;
    set<vector<lli>> st;
    for (lli i = 0; i < m; i++) {
        vector<lli> banned;
        for (lli j = 0; j < n; j++) {
            cin >> a;
            banned.pb(a);
        }
        st.insert(banned);
    }

    if (st.find(allEnd) == st.end()) {
        for (lli i = 0; i < n; i++) {
            cout << allEnd[i] << " ";
        }
        cout << endl;
        return;
    }

    lli finalNuk = -1;
    vector<lli> ans;
    for (auto v : st) {
        for (lli i = 0; i < n; i++) {
            if (v[i] == 1) {
                continue;
            }
            v[i]--;
            lli nuk = 0;
            for (lli j = 0; j < n; j++) {
                nuk += (store[j][sz(store[j]) - 1] - store[j][v[j] - 1]);
            }
            if ((finalNuk == -1 || nuk < finalNuk) &&
                (st.find(v) == st.end())) {
                finalNuk = nuk;
                ans = v;
            }
            v[i]++;
        }
    }

    // cout << finalNuk << endl;
    for (lli i = 0; i < n; i++) {
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