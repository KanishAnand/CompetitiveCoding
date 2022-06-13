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

void solve() {
    lli n, a, b;
    cin >> n;
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({a, b});
    }

    lli m, p, q, op;
    cin >> m;

    vector<lli> signx(m + 2, 0), sumx(m + 2, 0), rev(m + 2, 0), signy(m + 2, 0), sumy(m + 2, 0);

    lli ind = 1;
    while (m--) {
        cin >> op;
        signx[ind] = signx[ind - 1];
        signy[ind] = signy[ind - 1];
        sumx[ind] = sumx[ind - 1];
        sumy[ind] = sumy[ind - 1];
        rev[ind] = rev[ind - 1];

        if (op == 1) {
            rev[ind] = 1 - rev[ind - 1];

            signy[ind] = 1 - signx[ind - 1];
            sumy[ind] = -sumx[ind - 1];

            signx[ind] = signy[ind - 1];
            sumx[ind] = sumy[ind - 1];
        } else if (op == 2) {
            rev[ind] = 1 - rev[ind - 1];

            signy[ind] = signx[ind - 1];
            sumy[ind] = sumx[ind - 1];

            signx[ind] = 1 - signy[ind - 1];
            sumx[ind] = -sumy[ind - 1];
        } else if (op == 3) {
            cin >> p;
            signx[ind] = 1 - signx[ind];
            sumx[ind] = 2 * p - sumx[ind - 1];
        } else {
            cin >> p;
            signy[ind] = 1 - signy[ind];
            sumy[ind] = 2 * p - sumy[ind - 1];
        }
        ind++;
    }

    cin >> q;
    while (q--) {
        cin >> ind >> b;
        b--;
        lli valx, valy;
        if (rev[ind] == 1) {
            if (signx[ind] == 1) {
                valx = -v[b].second;
            } else {
                valx = v[b].second;
            }
            if (signy[ind] == 1) {
                valy = -v[b].first;
            } else {
                valy = v[b].first;
            }
            valx += sumx[ind];
            valy += sumy[ind];
        } else {
            if (signx[ind] == 1) {
                valx = -v[b].first;
            } else {
                valx = v[b].first;
            }
            if (signy[ind] == 1) {
                valy = -v[b].second;
            } else {
                valy = v[b].second;
            }
            valx += sumx[ind];
            valy += sumy[ind];
        }

        cout << valx << " " << valy << endl;
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