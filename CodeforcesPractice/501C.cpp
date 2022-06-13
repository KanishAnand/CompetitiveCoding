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
    lli n, a, b;
    vector<lli> arr, arr2;
    vector<pair<lli, lli>> v;
    set<pair<lli, pair<lli, lli>>> st;
    cin >> n;
    arr.resize(n + 2, 0);
    arr2.resize(n + 2, 0);
    fr(i, 0, n) {
        cin >> a >> b;
        if (a != 0) {
            st.insert(make_pair(a, make_pair(b, i)));
            arr[i] = a;
            arr2[i] = b;
        }
    }

    while (!st.empty()) {
        auto it = st.begin();
        a = (*it).first;
        b = (*it).second.first;
        lli par = (*it).second.second;
        st.erase(it);
        v.pb(make_pair(par, b));
        auto itr = st.find(make_pair(arr[b], make_pair(arr2[b], b)));
        st.erase(itr);
        arr[b]--;
        arr2[b] ^= par;
        if (arr[b] != 0) {
            st.insert(make_pair(arr[b], make_pair(arr2[b], b)));
        }
    }

    cout << v.size() << endl;
    fr(i, 0, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    rt;
}
