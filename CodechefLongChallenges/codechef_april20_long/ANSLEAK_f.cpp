#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

void solve() {
    lli n, a, m, k;
    cin >> n >> m >> k;
    vector<vector<lli>> ans(n + 2);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < k; j++) {
            cin >> a;
            ans[i].pb(a);
        }
    }

    vector<pair<lli, vector<lli>>> store;
    for (lli pp = 0; pp < min(n, (lli)7); pp++) {
        // map<lli, lli> mp;
        vector<lli> mp(k + 2, 0);
        lli minn = 0;
        vector<lli> ans1;
        ans1.resize(n + 2);
        lli i = pp, cnt = 0;

        while (cnt < n) {
            cnt++;
            vector<lli> cnt(m + 2, 0), v;
            lli mx = -1, ind;
            for (lli j = 0; j < k; j++) {
                a = ans[i][j];
                v.pb(a);
                if (mp[j] == minn) {
                    cnt[a]++;

                    if (cnt[a] > mx) {
                        mx = cnt[a];
                        ind = a;
                    }
                }
            }

            for (lli j = 0; j < k; j++) {
                if (v[j] == ind) {
                    mp[j]++;
                }
            }

            ans1[i] = ind;
            lli val = 6000;
            for (lli j = 0; j < k; j++) {
                val = min(val, mp[j]);
            }
            minn = val;
            i = (i + 1) % n;
        }

        store.pb({minn, ans1});
    }

    sort(store.rbegin(), store.rend());

    for (lli i = 0; i < n; i++) {
        cout << store[0].second[i] << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}