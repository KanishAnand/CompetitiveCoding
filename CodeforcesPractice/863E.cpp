#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b;
    set<lli> st;
    map<lli, lli> mp;
    vector<lli> v;
    vector<pair<lli, lli>> store;
    cin >> n;
    fr(i, 0, n) {
        cin >> a >> b;
        store.pb({a, b});
        st.insert(a);
        st.insert(b);
        st.insert(b + 1);
        mp[a]++;
        mp[b + 1]--;
    }
    for (auto it = st.begin(); it != st.end(); it++) {
        // cout << *it << endl;
        v.pb(*it);
    }
    fr(i, 1, v.size()) {
        mp[v[i]] += mp[v[i - 1]];
        // cout << v[i] << " " << mp[v[i]] << endl;
    }

    map<lli, lli> mp2;
    fr(i, 0, v.size()) {
        if (mp[v[i]] <= 1) {
            mp2[v[i]] = 1;
        }
    }

    fr(i, 1, v.size()) {
        mp2[v[i]] += mp2[v[i - 1]];
    }

    fr(i, 0, store.size()) {
        a = store[i].first, b = store[i].second;
        if (mp2[a] == mp2[b] && mp[a] > 1 && mp[b] > 1) {
            cout << i + 1 << endl;
            rt;
        }
    }
    cout << "-1" << endl;
    rt;
}