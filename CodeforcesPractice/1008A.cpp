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

int check(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
        return 1;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    string st;
    vector<lli> v;
    cin >> st;
    n = st.length();
    int flag = 0;

    fr(i, 0, n) {
        a = check(st[i]);
        if (a == 0 && st[i] != 'n') {
            if (i != n - 1) {
                a = check(st[i + 1]);
                if (a == 0) {
                    flag = 1;
                    break;
                }
            } else {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    rt;
}