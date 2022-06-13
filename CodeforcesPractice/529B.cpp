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
    lli n, w, h;
    cin >> n;

    lli sum = 0, mx = -1;
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> w >> h;
        sum += w;
        mx = max(mx, h);
        v.pb({w, h});
    }

    lli ans = sum * mx;

    for (lli i = 0; i < n; i++) {
        lli val = v[i].second, flag = 0;
        lli tmp = 0;
        lli sum_cp = sum;
        map<lli, lli> mp;

        for (lli j = 0; j < n; j++) {
            if (i != j) {
                if (v[j].second > val && v[j].first > val) {
                    flag = 1;
                    break;
                } else if (v[j].second > val) {
                    mp[j] = 1;
                    sum_cp += -v[j].first + v[j].second;
                    tmp++;
                }
            }
        }

        if (tmp > n / 2) {
            flag = 1;
        }
        if (flag == 1) {
            continue;
        }

        vector<lli> tmp2;
        lli cnt = tmp;

        for (lli j = 0; j < n; j++) {
            if (i != j && mp[j] == 0) {
                if (v[j].first <= val && v[j].second < v[j].first) {
                    tmp2.pb(v[j].first - v[j].second);
                }
            }
        }

        sort(tmp2.rbegin(), tmp2.rend());
        lli beg = 0;
        while (cnt < n / 2 && beg < tmp2.size()) {
            sum_cp -= tmp2[beg];
            beg++;
            cnt++;
        }

        lli no = sum_cp * val;
        ans = min(ans, no);
    }

    for (lli i = 0; i < n; i++) {
        lli val = v[i].first, flag = 0;
        lli tmp = 1;
        lli sum_cp = sum;
        sum_cp += -v[i].first + v[i].second;
        map<lli, lli> mp;
        mp[i] = 1;

        for (lli j = 0; j < n; j++) {
            if (i != j) {
                if (v[j].second > val && v[j].first > val) {
                    flag = 1;
                    break;
                } else if (v[j].second > val) {
                    mp[j] = 1;
                    sum_cp += -v[j].first + v[j].second;
                    tmp++;
                }
            }
        }

        if (tmp > n / 2) {
            flag = 1;
        }
        if (flag == 1) {
            continue;
        }

        vector<lli> tmp2;
        lli cnt = tmp;

        for (lli j = 0; j < n; j++) {
            if (i != j && mp[j] == 0) {
                if (v[j].first <= val && v[j].second < v[j].first) {
                    tmp2.pb(v[j].first - v[j].second);
                }
            }
        }

        sort(tmp2.rbegin(), tmp2.rend());
        lli beg = 0;
        while (cnt < n / 2 && beg < tmp2.size()) {
            sum_cp -= tmp2[beg];
            beg++;
            cnt++;
        }

        lli no = sum_cp * val;
        ans = min(ans, no);
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}