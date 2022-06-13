#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
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
    lli arr[n][n];
    fr(i, 0, n) {
        fr(j, 0, n) {
            cin >> a;
            arr[i][j] = a;
        }
    }

    int flag = 1;

    fr(i, 0, n) {
        fr(j, 0, n) {
            flag = 1;
            if (arr[i][j] != 1) {
                fr(p, 0, n) {
                    fr(q, 0, n) {
                        if (arr[p][j] + arr[i][q] == arr[i][j]) {
                            flag = 0;
                            // break;
                        }
                    }
                }
                if (flag == 1) {
                    cout << "NO" << endl;
                    rt;
                }
            }
        }
    }
    cout << "YES" << endl;
    rt;
}
