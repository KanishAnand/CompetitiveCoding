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
    lli n, a, mx = 0, in, ans = 1;
    vector<pair<lli, lli>> v;
    cin >> n;
    fr(i, 0, n) {
        cin >> a;
        // if(a > mx){
        //     mx = a;
        //     in = i;
        // }
        v.pb(make_pair(a, i + 1));
    }

    lli cnt = 1;

    sort(v.rbegin(), v.rend());

    for (lli i = 1; i < v.size(); i++) {
        ans += v[i].first * cnt + 1;
        cnt++;
    }

    cout << ans << endl;
    // cout << (*v.end() - 1).second << " ";
    for (lli i = 0; i < v.size(); i++) {
        cout << v[i].second << " ";
    }
    cout << endl;
    rt;
}
