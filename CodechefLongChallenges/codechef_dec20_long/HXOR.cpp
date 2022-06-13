#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

void solve() {
    int n, x, a;
    cin >> n >> x;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<int> ptr(32, 0);
    vector<vector<int>> st(32);
    vector<vector<bool>> no(n + 2, vector<bool>(32, 0));

    for (int i = 0; i < n; i++) {
        int tmp = v[i], cnt = 0;
        while (tmp > 0) {
            no[i][cnt] = tmp % 2;
            if (tmp % 2 == 1 && i != n - 1) {
                st[cnt].pb(i);
            }
            tmp /= 2;
            cnt++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 30; j >= 0; j--) {
            if (no[i][j] == 0) {
                continue;
            }

            if (x == 0) {
                break;
            }

            no[i][j] = 0;
            ptr[j]++;

            if (ptr[j] != sz(st[j])) {
                int ind = st[j][ptr[j]];
                no[ind][j] = 0;
                ptr[j]++;
            } else {
                no[n - 1][j] = 1 - no[n - 1][j];
            }
            x--;
        }
        if (x == 0) {
            break;
        }
    }

    if (x % 2 == 1 && n == 2) {
        no[n - 2][0] = 1;
        no[n - 1][0] = 1 - no[n - 1][0];
    }

    for (int i = 0; i < n; i++) {
        int val = 0, p = 1;
        for (int j = 0; j <= 30; j++) {
            val += p * no[i][j];
            if (j != 30) {
                p *= 2;
            }
        }
        cout << val << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    rt;
}