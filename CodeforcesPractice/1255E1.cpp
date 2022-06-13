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
    lli n, a;
    vector<lli> v, ch;
    cin >> n;
    lli one = 0;
    fr(i, 0, n) {
        cin >> a;
        if (a == 1) {
            ++one;
            ch.pb(i);
        }
        v.pb(a);
    }

    lli p = sqrt(one);
    set<lli> st;
    for (lli i = 2; i <= one; i++) {
        while (one % i == 0) {
            st.insert(i);
            one /= i;
        }
    }

    lli mn = 1e13;
    for (auto it = st.begin(); it != st.end(); it++) {
        lli ans = 0, beg = 0;
        while (beg < ch.size()) {
            lli i;
            lli mid = (beg + *it + beg - 1) / 2;
            for (i = beg; i < *it + beg; i++) {
                ans += abs(ch[i] - ch[mid]);
            }
            beg = i;
        }

        if (ans < mn) {
            mn = ans;
        }
    }

    if (mn == 1e13) {
        mn = -1;
    }

    cout << mn << endl;
    rt;
}