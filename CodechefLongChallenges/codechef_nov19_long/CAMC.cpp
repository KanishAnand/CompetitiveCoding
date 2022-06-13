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
    lli t;
    cin >> t;

    while (t--) {
        lli n, m, a;
        cin >> n >> m;
        vector<pair<lli, lli>> ve;

        fr(i, 0, n) {
            cin >> a;
            ve.pb({a, i % m});
        }

        sort(ve.begin(), ve.end());
        vector<lli> cnt(m + 2, 0);
        lli ptr1 = 0, ptr2 = -1;
        set<lli> st;

        for (lli i = 0; i < n; i++) {
            if (st.size() == m) {
                break;
            }
            cnt[ve[i].second]++;
            st.insert(ve[i].second);
            ++ptr2;
        }

        lli ans = ve[ptr2].first - ve[ptr1].first;

        while (1) {
            lli a = ve[ptr1].second;

            if (cnt[a] != 1) {
                ptr1++;
                cnt[a]--;
            } else if (cnt[a] == 1) {
                lli ind = -1;
                for (lli i = ptr2 + 1; i < n; i++) {
                    cnt[ve[i].second]++;
                    if (ve[i].second == a) {
                        ind = i;
                        break;
                    }
                }

                if (ind == -1) {
                    break;
                } else {
                    ptr1++;
                    cnt[a]--;
                    ptr2 = ind;
                }
            }

            ans = min(ans, ve[ptr2].first - ve[ptr1].first);
        }
        cout << ans << endl;
    }
    rt;
}
