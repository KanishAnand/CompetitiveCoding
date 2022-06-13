#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
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
    lli n, a;
    string st;
    cin >> st;
    lli hr = (st[1] - '0') + (st[0] - '0') * 10;
    lli mn = (st[4] - '0') + (st[3] - '0') * 10;

    cin >> a;
    lli val = 60 - mn;
    if (a < val) {
        mn += a;
    } else {
        mn = 0;
        a -= val;
        hr++;
        hr %= 24;
        lli p = a / 60;
        hr += p;
        hr %= 24;
        mn += a % 60;
    }

    string ans = "";
    if (hr == 0) {
        ans += "00";
    } else if (hr < 10) {
        ans += "0";
        ans += (char)(hr + '0');
    } else {
        lli q = hr % 10;
        lli r = hr / 10;
        r = r % 10;
        ans += (char)(r + '0');
        ans += (char)(q + '0');
    }
    ans += ":";
    if (mn == 0) {
        ans += "00";
    } else if (mn < 10) {
        ans += "0";
        ans += (char)(mn + '0');
    } else {
        lli q = mn % 10;
        lli r = mn / 10;
        r = r % 10;
        ans += (char)(r + '0');
        ans += (char)(q + '0');
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