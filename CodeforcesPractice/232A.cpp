#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

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
    lli n, a, k;
    vector<lli> x(102, 0);
    vector<vector<lli>> arr(102, x);
    cin >> k;
    lli m = -1;
    lli cnt = 0;
    fr(i, 0, 100) {
        fr(j, i + 1, 100) {
            fr(p, j + 1, 100) {
                arr[i][j] = 1;
                arr[j][i] = 1;
                arr[i][p] = 1;
                arr[p][i] = 1;
                arr[j][p] = 1;
                arr[p][j] = 1;
                m = max({i, j, p, m});
                ++cnt;
                if (cnt == k) {
                    goto label;
                }
            }
        }
    }

label:
    cout << m + 1 << endl;
    fr(i, 0, m + 1) {
        fr(j, 0, m + 1) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    rt;
}
