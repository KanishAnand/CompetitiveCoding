#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
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

// find_by_order(x) returns iterator to element with index x (0-based indexing)
// order_of_key(x) return index of element with value x (0-based indexing)
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
    vector<lli> v;
    new_data_set p;
    p.insert(0);
    p.insert(6);
    p.insert(3);
    p.insert(10);
    p.insert(3);
    // 0 3 6 10
    cout << p.order_of_key(6) << endl;
    cout << *p.find_by_order(2) << endl;
    cout << p.order_of_key(1) << endl;
    cout << p.order_of_key(3) << endl;
    for (auto it = p.begin(); it != p.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    rt;
}
