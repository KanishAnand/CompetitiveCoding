#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, m, k, a;
    vector<lli> v;
    cin >> n >> m >> k;
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }
    lli c = k, ans = 0;

    for (lli i = n - 1; i >= 0 && m > 0; i--) {
        if (v[i] <= k) {
            if (v[i] <= c) {
                c -= v[i];
                // cout << i << endl;
                ans++;
            } else {
                m--;
                if (m != 0) {
                    c = k - v[i];
                    // cout << i << "l" << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    rt;
}
