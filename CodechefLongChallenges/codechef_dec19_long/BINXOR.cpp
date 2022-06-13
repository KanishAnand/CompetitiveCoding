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

lli mod = 1e9 + 7;
vector<lli> fac(100002, 1);

lli modinverse(lli a) {
    lli b = mod - 2;
    lli ans = 1, x = a;

    while (b > 0) {
        if (b % 2 == 1) {
            ans *= x;
            ans %= mod;
        }
        b /= 2;
        x = (x * x) % mod;
    }
    return ans;
}

lli ncr(lli a, lli b) {
    lli p = (fac[a] * modinverse(fac[b])) % mod;
    return (p * modinverse(fac[a - b])) % mod;
}

lli calfac() {
    for (lli i = 1; i <= 100003; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calfac();
    lli n, t;
    vector<lli> v;
    cin >> t;
    while (t--) {
        cin >> n;
        string a, b;
        lli cnta1 = 0, cnta0 = 0, cntb1 = 0, cntb0 = 0;
        cin >> a >> b;
        fr(i, 0, n) {
            if (a[i] == '1') {
                cnta1++;
            } else {
                cnta0++;
            }
            if (b[i] == '1') {
                cntb1++;
            } else {
                cntb0++;
            }
        }

        lli maxval, minval;
        maxval = min(cnta0, cntb1) + min(cnta1, cntb0);
        minval = n - (min(cnta0, cntb0) + min(cnta1, cntb1));
        lli sum = 0, beg = minval;
        while (beg <= maxval) {
            sum += ncr(n, beg);
            sum %= mod;
            beg += 2;
        }

        cout << sum << endl;
    }
    rt;
}
