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
    lli n, a;
    string s, t;
    vector<lli> v1, v2, ans1, ans2;
    cin >> n;
    cin >> s >> t;
    lli cnt1 = 0, cnt2 = 0;
    fr(i, 0, n) {
        if (s[i] == 'a' && t[i] == 'b') {
            cnt1++;
            v1.pb(i + 1);
        } else if (s[i] == 'b' && t[i] == 'a') {
            cnt2++;
            v2.pb(i + 1);
        }
    }

    lli k = cnt1 / 2 + cnt2 / 2;
    lli cnt1o = cnt1, cnt2o = cnt2;

    fr(i, 0, cnt1) {
        if (i != cnt1 - 1) {
            ans1.pb(v1[i]);
            ans2.pb(v1[i + 1]);
            i++;
        }
    }

    fr(i, 0, cnt2) {
        if (i != cnt2 - 1) {
            ans1.pb(v2[i]);
            ans2.pb(v2[i + 1]);
            i++;
        }
    }

    if (cnt1 % 2 == 0) {
        cnt1 = 0;
    } else {
        cnt1 = 1;
    }

    if (cnt2 % 2 == 0) {
        cnt2 = 0;
    } else {
        cnt2 = 1;
    }

    if (cnt1 + cnt2 == 1) {
        cout << "-1" << endl;
        rt;
    } else if (cnt1 + cnt2 == 2) {
        k += 2;
        ans1.pb(v1[cnt1o - 1]);
        ans2.pb(v1[cnt1o - 1]);
        ans1.pb(v1[cnt1o - 1]);
        ans2.pb(v2[cnt2o - 1]);
    }

    cout << k << endl;
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " " << ans2[i] << endl;
    }
    rt;
}