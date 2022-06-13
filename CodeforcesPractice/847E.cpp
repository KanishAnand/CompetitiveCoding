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
string st;
lli n;
vector<lli> pref, packman;

lli cal(lli val) {
    lli no = 0;

    for (lli i = 0; i < packman.size(); i++) {
        lli steps = 0;
        for (lli j = packman[i] - 1; j >= 0; j--) {
            if (steps >= val) {
                break;
            }

            if (pref[j] - no <= 0) {
                break;
            } else {
                if (st[j] == '*') {
                    no++;
                }
            }
            steps++;
        }

        if (steps >= val) {
            continue;
        }

        steps *= 2;

        for (lli j = packman[i] + 1; j < n; j++) {
            if (steps >= val) {
                break;
            }
            if (st[j] == '*') {
                no++;
            }
            steps++;
        }
    }

    if (no == pref[n - 1]) {
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    lli a;
    cin >> n;
    pref.resize(n + 2, 0);
    cin >> st;

    if (st[0] == '*') {
        pref[0] = 1;
    } else if (st[0] == 'P') {
        packman.pb(0);
    }

    for (lli i = 1; i < n; i++) {
        pref[i] = pref[i - 1];
        if (st[i] == '*') {
            pref[i]++;
        } else if (st[i] == 'P') {
            packman.pb(i);
        }
    }

    lli beg = 0, end = 2 * st.length(), ans = 2 * st.length();

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli f = cal(mid);
        if (f == 1) {
            end = mid - 1;
            ans = min(ans, mid);
        } else {
            beg = mid + 1;
        }
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