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

lli calc(vector<lli> &store) {
    lli val = 0, p = 1, n = sz(store);
    for (lli i = 0; i < n; i++) {
        val += (store[i] * p);
        p *= 2;
    }

    return val;
}

void solve() {
    lli n, k, MX = 30;
    cin >> n >> k;

    vector<lli> v;

    lli aand, aor, band, bor, subOr;
    cout << "and 1 3" << endl;
    cin >> aand;
    cout << "and 2 3" << endl;
    cin >> band;

    cout << "or 1 3" << endl;
    cin >> aor;
    cout << "or 2 3" << endl;
    cin >> bor;

    cout << "or 1 2" << endl;
    cin >> subOr;

    lli oaand = aand, oband = band;
    vector<lli> elThird(MX + 1, 0);

    for (lli i = 0; i <= MX; i++) {
        lli rem1 = aand % 2;
        lli rem2 = band % 2;

        if (rem1 == 1 || rem2 == 1) {
            elThird[i] = 1;
        }

        aand /= 2;
        band /= 2;
    }

    lli totalOr = (aor | bor);
    for (lli i = 0; i <= MX; i++) {
        lli rem1 = totalOr % 2;
        lli rem2 = subOr % 2;

        if (rem1 == 1 && rem2 == 0) {
            elThird[i] = 1;
        }

        totalOr /= 2;
        subOr /= 2;
    }

    v.pb(calc(elThird));
    vector<lli> store = elThird;  // store bits of third element

    for (lli i = 4; i <= n; i++) {
        lli andVal, orVal;
        cout << "and 3 " << i << endl;
        cin >> andVal;

        cout << "or 3 " << i << endl;
        cin >> orVal;

        vector<lli> elm(MX + 1, 0);
        for (lli j = 0; j <= MX; j++) {
            lli rem1 = andVal % 2;
            lli rem2 = orVal % 2;

            if (rem1 == 1) {
                elm[j] = 1;
            }
            if (rem2 == 1 && store[j] == 0) {
                elm[j] = 1;
            }

            andVal /= 2;
            orVal /= 2;
        }

        v.pb(calc(elm));
    }

    aand = oaand, band = oband;
    vector<lli> elm1(MX + 1, 0), elm2(MX + 1, 0);
    for (lli j = 0; j <= MX; j++) {
        lli rem11 = aand % 2;
        lli rem12 = aor % 2;

        lli rem21 = band % 2;
        lli rem22 = bor % 2;

        if (rem11 == 1) {
            elm1[j] = 1;
        }
        if (rem21 == 1) {
            elm2[j] = 1;
        }
        if (rem12 == 1 && store[j] == 0) {
            elm1[j] = 1;
        }
        if (rem22 == 1 && store[j] == 0) {
            elm2[j] = 1;
        }

        aand /= 2;
        band /= 2;
        aor /= 2;
        bor /= 2;
    }

    v.pb(calc(elm1));
    v.pb(calc(elm2));

    sort(all(v));
    lli ans = v[k - 1];
    cout << "finish " << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}