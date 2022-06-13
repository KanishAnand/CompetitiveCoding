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
    lli n, a, check = 0;
    vector<lli> v, v1, bl;
    vector<pair<lli, lli>> vc;
    set<lli> st;
    cin >> n;
    bl.resize(n + 2, 0);
    input(n, v);
    input(n, v1);
    fr(i, 0, n) {
        vc.pb(make_pair(v[i], v1[i]));
    }
    sort(vc.begin(), vc.end());
    fr(i, 0, n - 1) {
        if (vc[i].first == vc[i + 1].first) {
            check = check | (vc[i].first);
            bl[i] = 1;
            bl[i + 1] = 1;
        }
    }

    fr(i, 0, n) {
        if (bl[i] == 0) {
            lli flag = 0;
            // lli t = check | vc[i].first;
            // cout << check << " " << vc[i].first << " " << t << endl;
            for (int j = 0; j < n; j++) {
                if (bl[j] == 1) {
                    lli t = vc[j].first | vc[i].first;
                    if (t == vc[j].first) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1) {
                // if (t == check) {
                bl[i] = 1;
                // }
            }
        }
    }
    lli sum = 0, cnt = 0;
    fr(i, 0, n) {
        if (bl[i] == 1) {
            ++cnt;
        }
        sum += (vc[i].second) * bl[i];
    }
    if (cnt < 2) {
        sum = 0;
    }
    cout << sum << endl;
    rt;
}
