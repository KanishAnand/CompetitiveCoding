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
#define len(x) (lli)(x.length())
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

lli fun(vector<lli> &boxes, vector<lli> &special, vector<lli> &occupied, map<lli, lli> &mp, lli occupied_pos) {
    lli ind = 0, cnt = 0, ans = 0, curr_ind = 0;

    for (auto pos : special) {
        lli tmp = 0;
        // number of boxes after this which are at special positions
        if (mp[pos] == 1) {
            occupied_pos--;
        }

        tmp += occupied_pos;

        // number of boxes before this point
        while (ind < sz(boxes)) {
            if (boxes[ind] <= pos) {
                cnt++;
                ind++;
            } else {
                break;
            }
        }

        // number of special boxes in this range
        auto it = lower_bound(special.begin(), special.end(), pos - cnt + 1);
        lli start_ind = it - special.begin();
        lli no = curr_ind - start_ind + 1;
        tmp += min(no, cnt);

        curr_ind++;
        ans = max(ans, tmp);
    }

    return ans;
}

void solve() {
    lli n, m, a;
    cin >> n >> m;

    map<lli, lli> mp_first, mp_second;
    vector<lli> boxes_first, special_first, occupied_first;
    vector<lli> boxes_second, special_second, occupied_second;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a > 0) {
            mp_first[a] = 1;
            boxes_first.pb(a);
        } else {
            mp_second[-a] = 1;
            boxes_second.pb(-a);
        }
    }

    for (lli i = 0; i < m; i++) {
        cin >> a;
        if (a > 0) {
            special_first.pb(a);
            if (mp_first[a] == 1) {
                occupied_first.pb(a);
            }
        } else {
            special_second.pb(-a);
            if (mp_second[-a] == 1) {
                occupied_second.pb(-a);
            }
        }
    }

    sort(all(boxes_first));
    sort(all(special_first));
    sort(all(occupied_first));
    lli first_ans = fun(boxes_first, special_first, occupied_first, mp_first, sz(occupied_first));
    first_ans = max(first_ans, sz(occupied_first));

    sort(all(boxes_second));
    sort(all(special_second));
    sort(all(occupied_second));
    lli second_ans = fun(boxes_second, special_second, occupied_second, mp_second, sz(occupied_second));
    second_ans = max(second_ans, sz(occupied_second));

    lli ans = first_ans + second_ans;
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