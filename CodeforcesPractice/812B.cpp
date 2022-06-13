#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli minn = 100000;
lli n, a, m, store = -1;
vector<lli> leftt, rightt;
vector<string> v;

lli fun(lli time, lli row, lli stair) {
    // cout << time << " " << row << " " << stair << endl;
    if (row >= store) {
        if (row == store) {
            if (stair == 0 && leftt[row] != -1) {
                time += leftt[row];
            } else if (stair == 1 && rightt[row] != -1) {
                time += rightt[row];
            }
        }
        if (time < minn) {
            minn = time;
        }
        return 0;
    }
    if (stair == 0) {
        // cout << row << " " << leftt[row] << endl;
        if (leftt[row] != -1) {
            // cout << leftt[row] << endl;
            fun(time + 2 * leftt[row] + 1, row + 1, 0);
            fun(time + m + 2, row + 1, 1);
        } else {
            fun(time + 1, row + 1, 0);
            fun(time + m + 2, row + 1, 1);
        }
    } else {
        if (rightt[row] != -1) {
            fun(time + 2 * rightt[row] + 1, row + 1, 1);
            fun(time + m + 2, row + 1, 0);
        } else {
            fun(time + 1, row + 1, 1);
            fun(time + m + 2, row + 1, 0);
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli n, a, m;
    // vector<lli> lefttt;
    // vector<string> v;
    string st;
    cin >> n >> m;
    fr(i, 0, n) {
        cin >> st;
        v.pb(st);
    }

    for (lli i = n - 1; i >= 0; i--) {
        lli in = -1, f = 0, in2 = -1;
        // cout << v[i] << i << endl;
        fr(j, 0, m + 2) {
            if (v[i][j] == '1') {
                if (f == 0) {
                    in2 = j;
                    f = 1;
                }
                in = j;
            }
        }
        // cout << in << " " << in2 << endl;
        leftt.pb(in);
        rightt.pb(m + 1 - in2);
    }

    for (lli i = 0; i < n; i++) {
        if (leftt[i] != -1) {
            store = i;
        }
    }
    if (store == -1) {
        cout << "0" << endl;
        rt;
    }

    // cout << leftt[0] << " " << leftt[1] << endl;
    // cout << rightt[0] << " " << rightt[1] << endl;
    fun(0, 0, 0);
    cout << minn << endl;
    rt;
}