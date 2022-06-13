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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string s, t;
    cin >> s >> t;
    if (t.length() > s.length()) {
        cout << s << endln;
        return;
    }

    lli zs = 0, os = 0;
    for (lli i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            os++;
        } else {
            zs++;
        }
    }

    lli zt = 0, ot = 0;
    for (lli i = 0; i < t.length(); i++) {
        if (t[i] == '1') {
            ot++;
        } else {
            zt++;
        }
    }

    vector<int> v = prefix_function(t);
    lli len = v[sz(v) - 1];

    if (zt > zs || ot > os) {
        cout << s << endl;
        return;
    }

    lli one = 0, zero = 0;
    for (lli i = len; i < t.length(); i++) {
        if (t[i] == '1') {
            one++;
        } else {
            zero++;
        }
    }

    string add = t.substr(len, t.length() - len);

    string ans = t;
    zs -= zt;
    os -= ot;

    while (1) {
        if (zs >= zero && os >= one) {
            ans += add;
            zs -= zero;
            os -= one;
        } else {
            break;
        }
    }

    while (zs != 0) {
        ans += '0';
        zs--;
    }
    while (os != 0) {
        ans += '1';
        os--;
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}