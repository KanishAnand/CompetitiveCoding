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
    vector<lli> v, v1;
    vector<pair<lli, lli>> arr;
    cin >> n;
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }
    fr(i, 0, n) {
        cin >> a;
        v1.pb(a);
    }
    fr(i, 0, n) {
        arr.pb(make_pair(v[i], v1[i]));
    }
    sort(v.begin(), v.end());
    sort(arr.begin(), arr.end());
    lli in = -1;
    for (lli i = n - 1; i >= 1; i--) {
        if (v[i] == v[i - 1]) {
            in = i;
            break;
        }
    }
    // cout << in << endl;
    if (in == -1) {
        cout << "0" << endl;
    } else {
        lli cnt = 0, sum = 0;
        for (auto it = arr.begin(); it != arr.end(); it++) {
            // cout << cnt << " l" << in << endl;
            if (cnt <= in) {
                ++cnt;
                // cout << (*it).first << " " << (*it).second << endl;
                sum += (*it).second;
            } else {
                // cout << "K" << endl;
                break;
            }
        }
        cout << sum << endl;
    }
    rt;
}