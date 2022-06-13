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
    // vector<lli> arr;
    cin >> n;
    lli arr[n + 2][n + 2];
    fr(i, 0, n) {
        fr(j, 0, n) {
            cin >> a;
            arr[i + 1][j + 1] = a;
        }
    }

    fr(i, 1, n + 1) {
        lli x = i + 1, y = i + 2;
        if (x > n) {
            x -= n;
        }
        if (y > n) {
            y -= n;
        }
        arr[i][i] = (arr[i][x] * arr[i][y]) / (arr[x][y]);
    }

    fr(i, 1, n + 1) {
        cout << (lli)sqrt(arr[i][i]) << " ";
    }
    cout << endl;
    rt;
}
