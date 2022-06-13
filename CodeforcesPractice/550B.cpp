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
    lli n, a, l, r, xe;
    vector<lli> v;
    cin >> n >> l >> r >> xe;
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }
    lli ans = 0, d = 0;
    fr(i, 0, pow(2, n) + 1) {
        lli temp = i, cnt = 0, sum = 0;
        set<lli> st;
        while (temp > 0) {
            lli c = temp % 2;
            temp /= 2;
            if (c == 1) {
                st.insert(v[cnt]);
                ++d;
                sum += v[cnt];
            }
            ++cnt;
        }

        if (d >= 2) {
            auto it = st.end();
            --it;
            lli x = *(st.begin()), y = *it;

            if (sum <= r && sum >= l && (y - x) >= xe) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    rt;
}
