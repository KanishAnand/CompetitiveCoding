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
    vector<pair<lli, lli>> v, v2;
    cin >> n;
    v2.resize(n + 2);
    string st;
    cin >> st;
    lli x, y, up = 0, right = 0;
    cin >> x >> y;
    lli val = abs(x) + abs(y);
    if (val > n || (n - val) % 2 == 1) {
        cout << "-1" << endl;
        rt;
    }

    fr(i, 0, n) {
        if (st[i] == 'U') {
            up++;
        } else if (st[i] == 'D') {
            up--;
        } else if (st[i] == 'R') {
            right++;
        } else {
            right--;
        }
        v.pb({up, right});
    }
    if (up == y && right == x) {
        cout << "0" << endl;
        rt;
    }
    up = 0, right = 0;
    for (lli i = n - 1; i >= 0; i--) {
        if (st[i] == 'U') {
            up++;
        } else if (st[i] == 'D') {
            up--;
        } else if (st[i] == 'R') {
            right++;
        } else {
            right--;
        }
        v2[i].first = up;
        v2[i].second = right;
    }

    lli anss = n + 2;
    lli beg = 1, end = n;
    while (beg <= end) {
        lli mid = (beg + end) / 2, flag = 0;
        if (mid == n) {
            flag = 1;
            anss = min(anss, mid);
            end = mid - 1;
            continue;
        }
        if (mid == 0) {
            beg = mid + 1;
            continue;
        }
        for (lli i = 0; i <= n - mid; i++) {
            lli b = i - 1, e = i + mid, ch1, ch2, p;
            if (b == -1) {
                ch1 = v2[e].first;
                ch2 = v2[e].second;
            } else if (e >= n) {
                ch1 = v[b].first;
                ch2 = v[b].second;
            } else {
                ch1 = v[b].first + v2[e].first;
                ch2 = v[b].second + v2[e].second;
            }
            p = abs(y - ch1) + abs(x - ch2);
            if (p <= mid && (mid - p) % 2 == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            anss = min(anss, mid);
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    cout << beg << endl;
    rt;
}