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

void solve() {
    lli n, a, b;
    cin >> n;
    vector<lli> va, vb;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        va.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        vb.pb(a);
    }

    vector<lli> mp(n + 2, 0);
    vector<stack<lli>> st(n + 2);
    set<lli> store;

    for (lli i = 0; i < n; i++) {
        if (va[i] == vb[i]) {
            store.insert(va[i]);
            mp[va[i]]++;
            st[va[i]].push(i);
        }
    }

    while (store.size() >= 2) {
        auto it = store.begin();
        a = *it;
        it++;
        b = *it;
        lli mn = min(mp[a], mp[b]);
        mp[a] -= mn;
        mp[b] -= mn;

        while (mn > 0) {
            lli ind1 = st[a].top();
            lli ind2 = st[b].top();
            st[a].pop();
            st[b].pop();
            vb[ind1] = b;
            vb[ind2] = a;
            mn--;
        }

        if (mp[a] == 0) {
            store.erase(store.find(a));
        }
        if (mp[b] == 0) {
            store.erase(store.find(b));
        }
    }

    lli cnt = 0, val;
    for (lli i = 0; i < n; i++) {
        if (va[i] == vb[i]) {
            cnt++;
            val = va[i];
        }
    }

    for (lli i = 0; i < n; i++) {
        if (cnt == 0) {
            break;
        }
        if (va[i] != val && vb[i] != val) {
            lli ind = st[val].top();
            st[val].pop();
            lli tmp = vb[i];
            vb[i] = val;
            vb[ind] = tmp;
            cnt--;
        }
    }

    if (cnt == 0) {
        cout << "Yes" << endl;
        for (lli i = 0; i < n; i++) {
            cout << vb[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
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