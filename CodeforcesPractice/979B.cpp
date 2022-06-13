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

    string st1, st2, st3;
    cin >> st1 >> st2 >> st3;

    lli mx1 = 0, mx2 = 0, mx3 = 0, l = st1.length();
    vector<lli> cnt1(100, 0), cnt2(100, 0), cnt3(100, 0);

    for (lli i = 0; i < l; i++) {
        cnt1[st1[i] - 'A']++;
        mx1 = max(mx1, cnt1[st1[i] - 'A']);
        cnt2[st2[i] - 'A']++;
        mx2 = max(mx2, cnt2[st2[i] - 'A']);
        cnt3[st3[i] - 'A']++;
        mx3 = max(mx3, cnt3[st3[i] - 'A']);
    }

    if (mx1 + n > l) {
        mx1 = l;
        if ((mx1 + n - l) == 1) {
            mx1--;
        }
    } else {
        mx1 = mx1 + n;
    }

    if (mx2 + n > l) {
        mx2 = l;
        if ((mx2 + n - l) == 1) {
            mx2--;
        }
    } else {
        mx2 = mx2 + n;
    }

    if (mx3 + n > l) {
        mx3 = l;
        if ((mx3 + n - l) == 1) {
            mx3--;
        }
    } else {
        mx3 = mx3 + n;
    }

    lli mx = max({mx1, mx2, mx3});

    if ((mx1 == mx2 && mx1 == mx) || (mx2 == mx3 && mx2 == mx) || (mx1 == mx3 && mx1 == mx)) {
        cout << "Draw" << endl;
    } else {
        if (mx == mx1) {
            cout << "Kuro" << endl;
        } else if (mx == mx2) {
            cout << "Shiro" << endl;
        } else {
            cout << "Katie" << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}