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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<vector<pair<lli, lli>>> store(20);

lli fun(vector<lli> &v, lli beg, lli end) {
    lli firstDigit = v[beg], withoutCarry = 0, withCarry = 0;

    for (auto pr : store[firstDigit]) {
        lli sum = pr.first + pr.second;
        if (sum < 10) {
            // cout << pr.first << " " << pr.second << endl;
            withoutCarry++;
        } else {
            // cout << pr.first << " " << pr.second << endl;
            withCarry++;
        }
    }

    // base case
    if (beg == end) {
        // cout << beg << " D " << end << " " << withoutCarry << " " << v[beg] << endl;
        return withoutCarry;
    }

    lli ans = 0;

    // cout << withoutCarry << " " << withCarry << endl;
    // transition
    if (withoutCarry) {
        ans += (withoutCarry * fun(v, beg + 1, end));
    }

    if (withCarry) {
        lli ind = -1;
        vector<lli> tmp = v;
        for (lli i = beg + 2; i <= end; i += 2) {
            if (v[i] != 0) {
                ind = i;
                break;
            } else {
                tmp[i] = 9;
            }
        }

        if (ind != -1) {
            tmp[ind]--;
            ans += (withCarry * fun(tmp, beg + 1, end));
        }
    }

    // cout << beg << " " << end << " " << ans << endl;
    return ans;
}

void solve() {
    lli n, a;
    cin >> n;

    vector<lli> v;
    while (n > 0) {
        v.pb(n % 10);
        n /= 10;
    }

    lli ans = fun(v, 0, sz(v) - 1);
    ans -= 2;
    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (lli i = 0; i <= 9; i++) {
        for (lli j = 0; j <= 9; j++) {
            lli val = i + j;
            store[val % 10].pb({i, j});
        }
    }

    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}