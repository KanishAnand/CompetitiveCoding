#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli arr[8][8] = {0}, f = 0, no[8] = {0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, mi, b, minn = 0;
    vector<lli> v, v1;
    cin >> n >> mi;
    fr(i, 0, mi) {
        cin >> a >> b;
        if (a < b) {
            v.pb(a);
            v1.pb(b);
        } else {
            v.pb(b);
            v1.pb(a);
        }
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                for (int l = 1; l <= 6; l++) {
                    for (int m = 1; m <= 6; m++) {
                        for (int n = 1; n <= 6; n++) {
                            for (int o = 1; o <= 6; o++) {
                                ++f;
                                // cout << f << endl;
                                lli cnt = 0;
                                // for (lli x = 0; x < 8; x++) {
                                //     for (lli y = 0; y < 8; y++) {
                                //         arr[x][y] = 0;
                                //     }
                                // }
                                no[1] = i;
                                no[2] = j;
                                no[3] = k;
                                no[4] = l;
                                no[5] = m;
                                no[6] = n;
                                no[7] = o;
                                // cout << f << endl;

                                for (int y = 0; y < mi; y++) {
                                    if (arr[no[v[y]]][no[v1[y]]] != f) {
                                        arr[no[v[y]]][no[v1[y]]] = f;
                                        arr[no[v1[y]]][no[v[y]]] = f;
                                        ++cnt;
                                    }
                                }
                                // // cout << f << endl;
                                // if (cnt == 21) {
                                //     // cout << i << j << k << l << m << n <<
                                //     o
                                //     // << endl;
                                // }
                                if (cnt > minn) {
                                    minn = cnt;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // cout << "DF" << endl;

    cout << minn << endl;
    // cout << "DF" << endl;
    rt;
}