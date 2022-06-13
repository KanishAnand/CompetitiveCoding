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
    lli n, a;
    string st;
    cin >> st;
    n = st.length();
    lli beg = 0, end = n - 1;

    string ans = "";

    while ((end - beg) >= 3) {
        vector<lli> tmp(3, 0);
        tmp[st[beg] - 'a']++;
        tmp[st[beg + 1] - 'a']++;
        tmp[st[end] - 'a']++;
        tmp[st[end - 1] - 'a']++;
        if (tmp[0] > 1) {
            ans += 'a';
        } else if (tmp[1] > 1) {
            ans += 'b';
        } else {
            ans += 'c';
        }
        beg += 2;
        end -= 2;
    }

    string ans2 = ans;
    reverse(all(ans2));

    if ((end - beg) >= 1) {
        ans += st[beg];
    }

    cout << ans << ans2 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}