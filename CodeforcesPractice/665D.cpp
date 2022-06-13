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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> isprime(2000005, 1);
    lli no = 2000005;

    for (lli i = 2; i <= sqrt(no); i++) {
        if (isprime[i] == 0) {
            continue;
        }
        for (lli j = i * i; j <= no; j += i) {
            isprime[j] = 0;
        }
    }

    vector<vector<lli>> store(n + 2);
    vector<lli> cnt(n + 2), vis(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        for (lli j = i + 1; j < n; j++) {
            lli val = v[i] + v[j];
            if (isprime[val] == 0) {
                store[i].pb(j);
                store[j].pb(i);
            }
        }
    }

    set<pair<lli, lli>> st;

    for (lli i = 0; i < n; i++) {
        cnt[i] = store[i].size();
        st.insert({store[i].size(), i});
    }

    while (!st.empty()) {
        auto it = st.end();
        it--;
        lli ch = (*it).first;
        if (ch == 0) {
            break;
        }
        lli ind = (*it).second;
        vis[ind] = 1;
        st.erase(it);

        for (lli i = 0; i < store[ind].size(); i++) {
            lli val = store[ind][i];
            if (vis[val] == 0) {
                st.erase({cnt[val], val});
                cnt[val]--;
                st.insert({cnt[val], val});
            }
        }
    }

    vector<lli> ans;
    for (lli i = 0; i < n; i++) {
        if (vis[i] == 0) {
            ans.pb(i);
        }
    }

    cout << ans.size() << endl;
    for (lli i = 0; i < ans.size(); i++) {
        cout << v[ans[i]] << " ";
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