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
    input(n, v);
    lli time = 0, prev = 0, f = 0;

    fr(i, 0, n) {
        if (v[i] > prev + 15) {
            time += 15;
            f = 1;
            break;
        } else {
            prev = v[i];
            time = v[i];
        }
    }

    if (f == 0) {
        time = min(v[n - 1] + 15, (lli)90);
    }

    cout << time << endl;
    rt;
}
