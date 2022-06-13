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
    vector<lli> arr, val, val2;
    cin >> n;
    arr.resize(n * n + 2, 0);
    val.resize(n * n + 2, 0);
    val2.resize(n * n + 2, 0);

    for (lli i = 1; i <= n * n; i++) {
        cin >> a;
        arr[i] = a;
    }

    lli p = n + 1, prev = 1;
    for (lli i = 1; i <= n; i++) {
        prev = 1;
        for (lli j = i; j <= n * n; j += p) {
            if (j != 0 && j <= n * prev && j >= n * (prev - 1)) {
                val[i] += arr[j];
            } else {
                // break;
            }
            prev++;
        }
    }
    // cout << val[2] << endl;
    prev = 1;
    lli r = 1;
    for (lli i = n + 1; i <= n * n; i += n) {
        prev = 1 + r;
        for (lli j = i; j <= n * n; j += p) {
            if (j != 0 && j <= n * prev && j > n * (prev - 1)) {
                val[i] += arr[j];
            } else {
                break;
            }
            prev++;
        }
        ++r;
    }

    prev = 1;
    for (lli i = 1; i <= n; i++) {
        prev = 1;
        for (lli j = i; j <= n * n; j += p) {
            if (j != 0 && j <= n * prev && j >= n * (prev - 1)) {
                val[j] = val[i];
            } else {
                break;
            }
            prev++;
        }
    }

    prev = 1, r = 1;
    for (lli i = n + 1; i <= n * n; i += n) {
        prev = 1 + r;
        for (lli j = i; j <= n * n; j += p) {
            if (j != 0 && j <= n * prev && j > n * (prev - 1)) {
                val[j] = val[i];
            } else {
                break;
            }
            prev++;
        }
        ++r;
    }

    lli q = n - 1;
    prev = 1;

    for (lli i = 1; i <= n; i++) {
        prev = 1;
        for (lli j = i; j <= n * n; j += q) {
            if (j != 0 && j <= n * prev && j > n * (prev - 1)) {
                val2[i] += arr[j];
            } else {
                break;
            }
            prev++;
        }
    }
    // cout << val2[1] << endl;
    prev = 1, r = 1;
    for (lli i = 2 * n; i <= n * n; i += n) {
        prev = 1 + r;
        for (lli j = i; j <= n * n; j += q) {
            if (j != 0 && j <= n * prev && j > n * (prev - 1)) {
                val2[i] += arr[j];
            } else {
                break;
            }
            prev++;
        }
        ++r;
    }

    prev = 1;

    for (lli i = 1; i <= n; i++) {
        prev = 1;
        for (lli j = i; j <= n * n; j += q) {
            if (j != 0 && j <= n * prev && j > n * (prev - 1)) {
                val2[j] = val2[i];
            } else {
                break;
            }
            prev++;
        }
    }

    prev = 1, r = 1;
    for (lli i = 2 * n; i <= n * n; i += n) {
        prev = 1 + r;
        for (lli j = i; j <= n * n; j += q) {
            if (j != 0 && j <= n * prev && j > n * (prev - 1)) {
                val2[j] = val2[i];
            } else {
                break;
            }
            prev++;
        }
        ++r;
    }

    lli minn1 = -1, minn2 = -1;

    // for (int i = 1; i <= n * n; i++) {
    //     cout << val[i] << " " << val2[i] << " " << i << endl;
    // }
    lli cnt = 0, x1, y1, x2, y2;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            ++cnt;
            if ((i + j) % 2 == 0) {
                if (val[cnt] + val2[cnt] - arr[cnt] > minn1) {
                    minn1 = val[cnt] + val2[cnt] - arr[cnt];
                    x1 = i;
                    y1 = j;
                }
            } else {
                if (val[cnt] + val2[cnt] - arr[cnt] > minn2) {
                    minn2 = val[cnt] + val2[cnt] - arr[cnt];
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }

    cout << minn1 + minn2 << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    rt;
}
