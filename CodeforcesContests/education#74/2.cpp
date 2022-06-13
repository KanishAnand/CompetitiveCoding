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

lli check(lli p, vector<lli> ve, lli r) {
    lli l = ve.size();
    if (ve.size() > p) {
        lli c = l - p;
        lli val = ve[c - 1];
        if (val > p * r) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, q, r;
    cin >> q;
    while (q--) {
        cin >> n >> r;
        vector<lli> v;
        input(n, v);
        set<lli> st;
        for (lli i = 0; i < n; i++) {
            st.insert(v[i]);
        }
        vector<lli> ve;
        for (auto it = st.begin(); it != st.end(); it++) {
            ve.pb(*it);
        }
        // sort(v.begin(), v.end());
        lli beg = 1, end = n;
        while (beg <= end) {
            lli mid = (beg + end) / 2;
            lli c = check(mid, ve, r);
            if (c == 1) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        cout << beg << endln;
    }
    rt;
}
