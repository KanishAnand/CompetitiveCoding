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
    lli n, a, t, b, c;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b >> c;
        string st;
        cin >> st;
        lli l = st.length();
        lli r = 0, p = 0, s = 0;
        fr(i, 0, l) {
            if (st[i] == 'R') {
                r++;
            } else if (st[i] == 'S') {
                s++;
            } else {
                p++;
            }
        }

        lli cnt = 0;
        cnt += min(a, s);
        cnt += min(b, r);
        cnt += min(c, p);
        lli val = n / 2;
        if (n % 2 == 1) {
            ++val;
        }
        // cout << cnt << " " << val << endl;
        if (cnt >= val) {
            cout << "YES" << endl;
            vector<char> v(n + 2, 'q');
            for (lli i = 0; i < n; i++) {
                if (st[i] == 'S' && a != 0) {
                    v[i] = 'R';
                    a--;
                } else if (st[i] == 'R' && b != 0) {
                    v[i] = 'P';
                    b--;
                } else if (st[i] == 'P' && c != 0) {
                    v[i] = 'S';
                    c--;
                }
            }

            for (lli i = 0; i < n; i++) {
                if (v[i] != 'q') {
                    cout << v[i];
                } else {
                    if (a != 0) {
                        cout << "R";
                        a--;
                    } else if (b != 0) {
                        cout << "P";
                        b--;
                    } else {
                        cout << "S";
                        c--;
                    }
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    rt;
}
