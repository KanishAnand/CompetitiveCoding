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
    lli n, a, b, c;
    vector<lli> flag, flag2;
    cin >> n;
    flag.resize(n + 2, 0);
    flag2.resize(n + 2, 0);
    vector<pair<pair<lli, lli>, pair<lli, lli>>> v;
    vector<pair<pair<lli, lli>, pair<lli, lli>>> v2, v3;
    fr(i, 0, n) {
        cin >> a >> b >> c;
        v.pb({{a, b}, {c, i + 1}});
    }
    sort(all(v));

    for (lli i = 0; i < n - 1; i++) {
        a = v[i].first.first;
        b = v[i + 1].first.first;
        if (a == b) {
            if (flag2[i] == 0) {
                v2.pb(v[i]);
            }
            if (flag2[i + 1] == 0) {
                v2.pb(v[i + 1]);
            }
            flag2[i] = 1;
            flag2[i + 1] = 1;
        }
    }

    sort(all(v2));
    lli sz = v2.size();

    for (lli i = 0; i < sz - 1; i++) {
        a = v2[i].first.second;
        b = v2[i + 1].first.second;
        lli c = v2[i].first.first;
        lli d = v2[i + 1].first.first;

        if (c == d && a == b) {
            cout << v2[i].second.second << " " << v2[i + 1].second.second
                 << endl;
            flag[v2[i].second.second - 1] = 1;
            flag[v2[i + 1].second.second - 1] = 1;
            ++i;
        }
    }

    lli cnt = 0;
    for (lli i = 0; i < n; i++) {
        if (flag[v[i].second.second - 1] == 0) {
            v3.pb(v[i]);
        }
    }

    lli ll = v3.size();

    for (lli i = 0; i < ll - 1; i++) {
        if (v3[i].first.first == v3[i + 1].first.first) {
            cout << v3[i].second.second << " " << v3[i + 1].second.second
                 << endl;
            flag[v3[i].second.second - 1] = 1;
            flag[v3[i + 1].second.second - 1] = 1;
            ++i;
        }
    }

    for (lli i = 0; i < n; i++) {
        if (flag[v[i].second.second - 1] == 0 && cnt == 0) {
            cout << v[i].second.second << " ";
            ++cnt;
        } else if (flag[v[i].second.second - 1] == 0 && cnt == 1) {
            cout << v[i].second.second << endl;
            cnt = 0;
        }
    }

    rt;
}
