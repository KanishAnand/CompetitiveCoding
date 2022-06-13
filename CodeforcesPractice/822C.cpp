#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, x, b, c;
    vector<lli> v(200009, 0);
    cin >> n >> x;
    // set<pair<pair<lli, lli>, pair<lli, lli>>> st;
    set<pair<lli, pair<lli, pair<lli, lli>>>> st;
    fr(i, 0, n) {
        cin >> a >> b >> c;
        // st.insert(make_pair(make_pair(b - a + 1, c), make_pair(a, b)));
        st.insert(make_pair(b - a + 1, make_pair(c, make_pair(a, b))));
    }

    lli ans = 1e15;

    for (auto it = st.begin(); it != st.end(); it++) {
        lli r = (*it).second.second.second;
        lli t = (*it).second.second.first;
        lli y = r - t + 1;
        if (x > y) {
            // pair<pair<lli, lli>, pair<lli, lli>> pairVal = {{x - y, 0},
            //                                                 {r + 1, 0}};
            pair<lli, pair<lli, pair<lli, lli>>> pairVal = {x - y, {0, {r, 0}}};
            auto itr = lower_bound(it, st.end(), pairVal);

            if (itr != st.end() && (*itr).first == x - y) {
                lli val = (*it).second.first + (*itr).second.first;
                if (val < ans) {
                    ans = val;
                }
            }
        }
    }

    if (ans == 1e15) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
    rt;
}
