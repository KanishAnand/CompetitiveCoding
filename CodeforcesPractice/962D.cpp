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
    lli n, a;
    vector<lli> v, arr;
    set<pair<lli, lli>> st, st2;
    cin >> n;
    arr.resize(100 * n, 0);

    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
        st.insert(make_pair(a, i));
    }

    lli cnt = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (it != st.end()) {
            auto p = it;
            p++;
            if ((*it).first == (*p).first) {
                arr[cnt] = -1;
                arr[cnt + 1] = -1;
                st.insert(make_pair(2 * ((*it).first), (*p).second));
                ++it;
                cnt += 2;
            } else {
                ++cnt;
            }
        }
    }

    lli c = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (arr[c] != -1) {
            st2.insert(make_pair((*it).second, (*it).first));
        }
        ++c;
    }

    cout << st2.size() << endl;
    for (auto it = st2.begin(); it != st2.end(); it++) {
        cout << (*it).second << " ";
    }
    cout << endl;
    rt;
}
