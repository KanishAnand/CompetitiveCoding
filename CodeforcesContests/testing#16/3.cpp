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
    lli n, a, x = 0, y = 0, prevx = 0, prevy = 0, ans = 0, tmpx, tmpy, tmp2x,
              tmp2y;
    string st;
    cin >> st;
    set<pair<lli, pair<lli, pair<lli, lli>>>> stt;

    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == 'N') {
            y++;
        } else if (st[i] == 'S') {
            y--;
        } else if (st[i] == 'E') {
            x++;
        } else {
            x--;
        }

        if (x < prevx) {
            tmpx = x;
            tmpy = y;
            tmp2x = prevx;
            tmp2y = prevy;
        } else if (x == prevx) {
            tmpx = x;
            tmp2x = prevx;
            if (y < prevy) {
                tmpy = y;
                tmp2y = prevy;
            } else {
                tmp2y = y;
                tmpy = prevy;
            }
        } else {
            tmp2x = x;
            tmp2y = y;
            tmpx = prevx;
            tmpy = prevy;
        }

        auto it = stt.find({tmpx, {tmpy, {tmp2x, tmp2y}}});
        if (it != stt.end()) {
            ans += 1;
        } else {
            ans += 5;
        }

        if (x < prevx) {
            stt.insert({x, {y, {prevx, prevy}}});
        } else if (x == prevx) {
            if (y < prevy) {
                stt.insert({x, {y, {prevx, prevy}}});
            } else {
                stt.insert({prevx, {prevy, {x, y}}});
            }
        } else {
            stt.insert({prevx, {prevy, {x, y}}});
        }

        prevx = x;
        prevy = y;
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}