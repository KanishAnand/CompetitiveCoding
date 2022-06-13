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
    lli n, a, m;
    cin >> n >> m;
    map<lli, lli> mp;
    vector<pair<lli, lli>> v;
    fr(i, 0, m) {
        lli b, c;
        cin >> a >> b >> c;
        mp[a] -= c;
        mp[b] += c;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        a = (*it).first;
        auto b = (*it).second;
        if (b != 0) {
            v.pb({b, a});
        }
    }

    if (v.size() != 0) {
        sort(all(v));
    }
    lli beg = 0, end = sz(v) - 1;
    struct ans {
        lli p, q, r;
    };
    vector<struct ans> ve;
    while (beg < end) {
        lli val1 = v[beg].first, val2 = v[end].first, ind1 = v[beg].second,
            ind2 = v[end].second;
        if (val1 == 0) {
            beg++;
            continue;
        }
        if (val2 == 0) {
            end--;
            continue;
        }

        if (abs(val1) <= val2) {
            ve.pb({ind1, ind2, abs(val1)});
            v[end].first -= abs(val1);
            beg++;
        } else {
            ve.pb({ind1, ind2, val2});
            v[beg].first += val2;
            end--;
        }
    }

    cout << ve.size() << endl;
    fr(i, 0, ve.size()) {
        cout << ve[i].p << " " << ve[i].q << " " << ve[i].r << "\n";
    }
    rt;
}