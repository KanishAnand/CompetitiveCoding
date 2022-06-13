#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
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
    lli n, a, q;
    vector<lli> v;
    cin >> q;
    while (q--) {
        cin >> n;
        lli sum = 0, ans;
        fr(i, 0, n) {
            cin >> a;
            sum += a;
        }
        ans = sum / n;
        if (sum % n != 0) {
            ans++;
        }
        cout << ans << endl;
    }
    rt;
}
