#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

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
    lli n, a;
    vector<lli> v;
    cin >> n;
    map<lli, lli> mp;
    fr(i, 0, 2 * n) {
        cin >> a;
        v.pb(a);
        mp[a]++;
    }

    vector<lli> pr(2750133, 0);
    lli mx = 2750133;

    for (lli i = 2; i <= sqrt(mx); i++) {
        if (pr[i] == 0) {
            for (lli j = i * i; j <= mx; j += i) {
                if (pr[j] == 0) {
                    pr[j] = i;
                }
            }
        }
    }

    vector<lli> prime;
    prime.pb(0);

    fr(i, 2, mx) {
        if (pr[i] == 0) {
            prime.pb(i);
        }
    }

    sort(v.rbegin(), v.rend());

    fr(i, 0, sz(v)) {
        lli val = v[i];
        if (pr[val] != 0 && mp[val] != 0) {
            mp[val]--;
            mp[val / pr[val]]--;
            cout << val << " ";
        }
    }

    sort(all(v));
    fr(i, 0, sz(v)) {
        if (mp[v[i]] != 0) {
            lli val = prime[v[i]];
            mp[val]--;
            mp[v[i]]--;
            cout << v[i] << " ";
        }
    }

    cout << endl;
    rt;
}