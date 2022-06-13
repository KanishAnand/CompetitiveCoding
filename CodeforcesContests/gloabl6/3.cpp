#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << "0" << endl;
        rt;
    }
    lli p, q;
    p = min(r, c);
    q = max(r, c);
    vector<vector<lli>> v;
    v.resize(q + 3);

    lli beg = 2;
    for (lli i = 0; i < p; i++) {
        v[i].pb(beg);
        for (lli j = 2; j <= p; j++) {
            if (beg != 2) {
                v[i].pb(beg * 2 * j);
            } else {
                v[i].pb(beg * j);
            }
        }
        if (beg == 2) {
            beg++;
        } else {
            beg += 2;
        }
    }
    beg = p * 2;
    beg++;

    for (lli i = p; i < q; i++) {
        v[i].pb(beg);
        for (lli j = 2; j <= p; j++) {
            v[i].pb(beg * 2 * j);
        }
        beg++;
    }

    if (r <= c) {
        for (lli i = 0; i < p; i++) {
            for (lli j = 0; j < q; j++) {
                cout << v[j][i] << " ";
            }
            cout << endl;
        }
    } else {
        for (lli i = 0; i < q; i++) {
            for (lli j = 0; j < p; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    rt;
}
