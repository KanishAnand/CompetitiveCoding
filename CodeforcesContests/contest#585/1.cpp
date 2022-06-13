#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endl '\n'
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

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
    lli n, a1, a2, k1, k2;
    vector<lli> v;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    lli o = n, mx = 0, a1o = a1, a2o = a2;
    if (k1 > k2) {
        lli p = min(n / k2, a2);
        n -= p * k2;
        a2 -= p;
        mx += p;
        if (n != 0) {
            p = min(n / k1, a1);
            a1 -= p;
            n -= p * k1;
            mx += p;
        }
    } else {
        lli p = min(n / k1, a1);
        n -= p * k1;
        a1 -= p;
        mx += p;
        if (n != 0) {
            p = min(n / k2, a2);
            a2 -= p;
            n -= p * k2;
            mx += p;
        }
    }

    n = o;
    a1 = a1o, a2 = a2o;
    // cout << a1 << " " << a2 << " " << n << endl;
    lli ans = a1 * (k1 - 1) + a2 * (k2 - 1), mn = 0;
    // cout << ans << endl;
    if (ans < n) {
        n -= ans;
        mn = min(a1 + a2, n);
    }

    cout << mn << " " << mx << endl;
    rt;
}
