#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
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
    lli n, a, t;
    cin >> t;
    while (t--) {
        string st;
        cin >> st;
        vector<lli> v;
        lli l = st.length();
        vector<lli> ev, od;
        fr(i, 0, l) {
            lli p = st[i] - '0';
            if (p % 2 == 0) {
                ev.pb(p);
            } else {
                od.pb(p);
            }
        }

        lli ecnt = 0, ocnt = 0, ce = ev.size(), co = od.size();

        while (ecnt != ce && ocnt != co) {
            if (ev[ecnt] < od[ocnt]) {
                v.pb(ev[ecnt]);
                ecnt++;
            } else {
                v.pb(od[ocnt]);
                ++ocnt;
            }
        }
        if (ecnt != ce) {
            fr(i, 0, v.size()) {
                cout << v[i];
            }
            for (lli i = ecnt; i < ev.size(); i++) {
                cout << ev[i];
            }
        } else if (ocnt != co) {
            fr(i, 0, v.size()) {
                cout << v[i];
            }
            for (lli i = ocnt; i < od.size(); i++) {
                cout << od[i];
            }
        } else {
            fr(i, 0, v.size()) {
                cout << v[i];
            }
        }
        cout << endln;
    }
    rt;
}
