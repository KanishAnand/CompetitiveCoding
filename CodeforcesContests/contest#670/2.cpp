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
    cin >> n;
    vector<lli> pos, neg;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a >= 0) {
            pos.pb(a);
        } else {
            neg.pb(abs(a));
        }
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());

    lli ans = 1, i = 0, j = 0, cnt = 0;

    for (lli p = 0; p < 5; p++) {
        if (i == pos.size()) {
            ans *= neg[j];
            j++;
            cnt++;
            continue;
        }
        if (j == neg.size()) {
            ans *= pos[i];
            i++;
            continue;
        }

        if (pos[i] >= neg[j]) {
            ans *= pos[i];
            i++;
        } else if (neg[j] > pos[i]) {
            ans *= neg[j];
            j++;
            cnt++;
        }
    }

    if (cnt % 2 == 0) {
        cout << ans << endl;
        return;
    }

    lli val1 = ans, val2 = ans;
    lli flag1 = -1, flag2 = -1;

    if (i != pos.size()) {
        val1 /= neg[j - 1];
        val1 *= pos[i];
        flag1 = 1;
    }

    if (i != 0 && j != neg.size()) {
        val2 /= pos[i - 1];
        val2 *= neg[j];
        flag2 = 1;
    }

    if (flag1 != -1 && flag2 != -1) {
        ans = max(val1, val2);
        cout << ans << endl;
        return;
    }
    if (flag1 != -1) {
        ans = val1;
        cout << ans << endl;
        return;
    }
    if (flag2 != -1) {
        ans = val2;
        cout << ans << endl;
        return;
    }

    ans = 1;

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    i = 0, j = 0;

    for (lli p = 0; p < 5; p++) {
        if (i == pos.size()) {
            ans *= neg[j];
            j++;
            cnt++;
            continue;
        }
        if (j == neg.size()) {
            ans *= pos[i];
            i++;
            continue;
        }

        if (pos[i] <= neg[j]) {
            ans *= pos[i];
            i++;
        } else if (neg[j] < pos[i]) {
            ans *= neg[j];
            j++;
            cnt++;
        }
    }

    cout << -ans << endl;
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