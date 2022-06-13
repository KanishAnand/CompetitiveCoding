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
    vector<lli> arr(10, 0);
    cin >> n;
    string s;
    cin >> s;
    fr(i, 0, n) {
        if (s[i] == 'z') {
            arr[4]++;
        } else if (s[i] == 'e') {
            arr[0]++;
        } else if (s[i] == 'n') {
            arr[1]++;
        } else if (s[i] == 'o') {
            arr[2]++;
        } else if (s[i] == 'r') {
            arr[3]++;
        }
    }

    for (lli i = 0; i < arr[1]; i++) {
        cout << "1 ";
    }
    for (lli i = 0; i < arr[4]; i++) {
        cout << "0 ";
    }
    cout << endl;
    rt;
}
