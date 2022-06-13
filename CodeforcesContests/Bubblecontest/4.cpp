#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endl '\n'
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
    lli n, a, k;
    vector<lli> v, cost;
    cin >> n >> k;
    input(n, v);
    cin >> a;
    input(n, cost);
    lli minn = cost[0], ans = 0, strnght = k;
    set<lli> st;

    for (int i = 0; i < n; i++) {
        st.insert(cost[i]);
        lli count = st.size();
        if (v[i] > strnght) {
            // cout << v[i] << " " << i << " " << strnght << endl;
            lli x = v[i] - strnght;
            lli y = x / a;
            y++;
            if (x % a == 0) {
                --y;
            }
            // cout << y << "k" << i << endl;
            // get sum of min y elements in set and add in ans
            if (st.size() < y) {
                cout << "-1" << endl;
                rt;
            } else {
                lli cnt = 0;
                for (auto it = st.begin(); it != st.end(); it++) {
                    if (cnt < y) {
                        // cout << *it << " " << i << endl;
                        ans += *it;
                        ++cnt;
                    } else {
                        break;
                    }
                }
                auto p = st.begin();
                lli x = y;
                while (x--) {
                    p++;
                }
                st.erase(st.begin(), p);
                strnght += y * a;
            }
        }
    }

    cout << ans << endl;
    rt;
}
