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
#define sz(x) (int)(x.size())
#define len(x) (int)(x.length())
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
int n;
vector<int> v;
const int INF = 1e6 + 2;
vector<pair<int, int>> seg;

void build(int pos, int l, int r) {
    int mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = {v[l], v[l]};
        return;
    }
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos].first = min(seg[2 * pos].first, seg[2 * pos + 1].first);
    seg[pos].second = __gcd(seg[2 * pos].second, seg[2 * pos + 1].second);
    return;
}

pair<int, int> query(int pos, int beg, int end, int l, int r) {
    if (l > r || end < l || beg > r) {
        return {INF, 0};
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    int mid = (l + r) / 2;
    pair<int, int> pr1 = query(2 * pos, beg, end, l, mid);
    pair<int, int> pr2 = query(2 * pos + 1, beg, end, mid + 1, r);
    return {min(pr1.first, pr2.first), __gcd(pr1.second, pr2.second)};
}

int check(int len) {
    int flag = 0;
    for (int i = 0; i < n - len; i++) {
        pair<int, int> ret = query(1, i, i + len, 0, n - 1);
        if (ret.first == ret.second) {
            flag = 1;
        }
    }
    return flag;
}

void solve() {
    int a;
    cin >> n;
    seg.resize(4 * n + 2, {INF, 0});

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    build(1, 0, n - 1);

    int beg = 0, end = n - 1, ans = 0;

    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (check(mid)) {
            ans = mid;
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    vector<int> l;
    for (int i = 0; i < n - ans; i++) {
        pair<int, int> ret = query(1, i, i + ans, 0, n - 1);
        if (ret.first == ret.second) {
            l.pb(i + 1);
        }
    }

    cout << sz(l) << " " << ans << endl;
    for (auto val : l) {
        cout << val << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}