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
    lli n, a;
    vector<lli> v;
    cin >> n;
    string st;
    lli cnt = 0;
    cin >> st;
    fr(i, 0, n - 1) {
        if (st[i] == 'a') {
            if (st[i + 1] != 'b') {
                st[i + 1] = 'b';
                ++cnt;
            }
        } else {
            if (st[i + 1] != 'a') {
                st[i + 1] = 'a';
                ++cnt;
            }
        }
        ++i;
    }
    cout << cnt << endl;
    cout << st << endl;
    rt;
}
