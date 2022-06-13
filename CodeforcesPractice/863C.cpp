#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// #define endl '\n'
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

int cnt[5][5];  // memset and fill add in template

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, k;
    vector<lli> v(11, 0), v2(11, 0);
    int arr[5][5], arr2[5][5];  // take double vector here.
    cin >> k >> a >> b;
    fr(i, 0, 3) {
        fr(j, 0, 3) {
            cin >> n;
            arr[i + 1][j + 1] = n;
        }
    }

    fr(i, 0, 3) {
        fr(j, 0, 3) {
            cin >> n;
            arr2[i + 1][j + 1] = n;
        }
    }

    lli cont = 0;

    // cout << "K" << endl;
    while (1) {
        if (cnt[a][b] != 0) {
            break;
        }
        // cout << "kan" << endl;
        cont++;
        lli scra = 0, scrb = 0;
        if (a != b) {
            if (a + b == 3) {
                if (a == 1) {
                    scrb++;
                } else {
                    scra++;
                }
            } else if (a + b == 4) {
                if (a == 1) {
                    scra++;
                } else {
                    scrb++;
                }
            } else {
                if (a == 3) {
                    scra++;
                } else {
                    scrb++;
                }
            }
        }
        v[cont] = v[cont - 1] + scra;
        v2[cont] = v2[cont - 1] + scrb;
        // v.pb(scra);
        // v2.pb(scrb);
        cnt[a][b] = cont;
        lli x = arr[a][b];
        lli y = arr2[a][b];
        a = x;
        b = y;
        // cout << "K" << a << " " << b << " " << cont << endl;
    }
    // cout << cnt[a][b] << endl;
    lli ansa = 0, ansb = 0;
    // cout << cont << endl;
    // cout << a << " " << b << " " << cnt[a][b] << endl;
    // cout << k << endl;
    ansa += v[min(k, (lli)cnt[a][b] - 1)];
    ansb += v2[min(k, (lli)cnt[a][b] - 1)];
    k = k - cnt[a][b] + 1;
    if (k > 0) {
        // cout << k << endl;
        // cout << ansa << " " << ansb << endl;
        ansa += (v[cont] - v[cnt[a][b] - 1]) * (k / (cont - cnt[a][b] + 1));
        ansb += (v2[cont] - v2[cnt[a][b] - 1]) * (k / (cont - cnt[a][b] + 1));
        // cout << ansa << " " << ansb << endl;
        ansa +=
            v[(k % (cont - cnt[a][b] + 1)) + cnt[a][b] - 1] - v[cnt[a][b] - 1];
        ansb += v2[(k % (cont - cnt[a][b] + 1)) + cnt[a][b] - 1] -
                v2[cnt[a][b] - 1];
    }
    cout << ansa << " " << ansb << endl;

    rt;
}