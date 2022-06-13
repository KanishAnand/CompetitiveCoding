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
    lli n, a, k;
    vector<lli> v;
    map<lli, lli> st;
    cin >> n >> k;
    lli sz = 0, strt = 0;

    fr(i, 0, n) {
        cin >> a;
        if (st[a] == 0) {
            if (sz < k) {
                v.pb(a);
                st[a] = 1;
                ++sz;
            } else {
                st[v[strt]] = 0;
                v.pb(a);
                st[a] = 1;
                ++strt;
            }
        }
        // if (st.size() != 0) {
        //     for (auto it = st.begin(); it != st.end(); it++) {
        //         cout << *it << " ";
        //     }
        //     cout << endl;
        // }
        // if (st.size() < k) {
        //     if (st.size() == 0 || st.find(a) == st.end()) {
        //         st.insert(a);
        //     }
        // } else {
        //     if (st.size() != 0 && st.find(a) != st.end()) {
        //     } else {
        //         auto itr = st.begin();
        //         st.erase(itr);
        //         st.insert(a);
        //     }
        // }
    }

    // for (auto it = st.begin(); it != st.end(); it++) {
    //     v.pb(*it);
    // }
    cout << v.size() - strt << endl;
    for (lli i = v.size() - 1; i >= strt; i--) {
        cout << v[i] << " ";
    }
    cout << endl;
    rt;
}
