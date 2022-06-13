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
    lli aa, ab, ba, bb;
    cin >> aa >> ab >> ba >> bb;

    if (aa + ab + ba + bb == 0) {
        cout << "0" << endl;
        return;
    }

    lli p = 1, q = 1;

    if (aa != 0 && (ab + ba + bb) == 0) {
        q = 0;
    }
    if (bb != 0 && (ab + ba + aa) == 0) {
        p = 0;
    }

    if (aa != 0) {
        lli val = 1 + 8 * aa;
        p = sqrt(val);
        if (p * p != val) {
            cout << "Impossible" << endl;
            return;
        }
        p++;
        if (p % 2 != 0) {
            cout << "Impossible" << endl;
            return;
        }
        p /= 2;
    }

    if (bb != 0) {
        lli val = 1 + 8 * bb;
        q = sqrt(val);
        if (q * q != val) {
            cout << "Impossible" << endl;
            return;
        }
        q++;
        if (q % 2 != 0) {
            cout << "Impossible" << endl;
            return;
        }
        q /= 2;
    }

    lli tot = ((p + q) * (p + q - 1)) / 2;
    if (aa + ab + ba + bb != tot) {
        cout << "Impossible" << endl;
        return;
    }

    if (q == 0) {
        for (lli i = 0; i < p; i++) {
            cout << "0";
        }
        cout << endl;
        return;
    }

    lli no = ab / q;
    if (p < no) {
        cout << "Impossible" << endl;
        return;
    }

    string ans = "";
    for (lli i = 0; i < no; i++) {
        ans += '0';
        p--;
    }

    no = ab % q;
    for (lli i = 0; i < q - no; i++) {
        ans += '1';
    }

    q = no;
    if (no != 0) {
        if (p == 0) {
            cout << "Impossible" << endl;
            return;
        }
        ans += '0';
        p--;
    }
    for (lli i = 0; i < q; i++) {
        ans += '1';
    }

    for (lli i = 0; i < p; i++) {
        ans += '0';
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