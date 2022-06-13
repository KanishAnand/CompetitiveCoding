#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

struct seg {
    lli id, len, prev, next, val;

    bool operator<(const seg& a) const {
        if (a.len == this->len) {
            return this->id < a.id;
        } else {
            return this->len > a.len;
        }
    }
};

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> prev(n + 2, 0), next(n + 2, 0), len(n + 2, 0), valu(n + 2, 0);
    set<struct seg> st;

    lli beg = 0, cnt = 1;

    for (lli i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            cnt++;
        } else {
            beg++;
            struct seg tmp;
            tmp.id = beg;
            tmp.len = cnt;
            tmp.val = v[i - 1];
            tmp.prev = beg - 1;
            tmp.next = beg + 1;
            len[beg] = cnt;
            valu[beg] = tmp.val;
            prev[beg] = beg - 1;
            next[beg] = beg + 1;
            st.insert(tmp);
            cnt = 1;
        }
    }

    beg++;
    struct seg tmp;
    tmp.id = beg;
    tmp.len = cnt;
    tmp.val = v[n - 1];
    tmp.prev = beg - 1;
    tmp.next = 0;
    valu[beg] = tmp.val;
    len[beg] = cnt;
    prev[beg] = beg - 1;
    next[beg] = 0;
    st.insert(tmp);

    lli ans = 0;

    while (!st.empty()) {
        auto it = st.begin();
        struct seg store = *it;
        st.erase(it);
        ans++;

        if (store.prev != 0 && store.next != 0 &&
            valu[store.prev] == valu[store.next]) {
            struct seg tmp1;
            tmp1.id = store.prev;
            tmp1.val = valu[tmp1.id];
            tmp1.len = len[tmp1.id];
            tmp1.prev = prev[tmp1.id];
            tmp1.next = next[tmp1.id];

            auto it1 = st.find(tmp1);
            if (it1 != st.end()) {
                st.erase(it1);
            }

            tmp1.id = store.next;
            tmp1.len = len[tmp1.id];
            tmp1.val = valu[tmp1.id];
            tmp1.prev = prev[tmp1.id];
            tmp1.next = next[tmp1.id];

            auto it2 = st.find(tmp1);
            if (it2 != st.end()) {
                st.erase(it2);
            }

            tmp1.id = store.prev;
            tmp1.val = valu[tmp1.id];
            tmp1.len = len[store.prev] + len[store.next];
            tmp1.prev = prev[tmp1.id];
            lli p = next[store.next];
            tmp1.next = p;
            len[tmp1.id] = tmp1.len;
            next[tmp1.id] = tmp1.next;
            st.insert(tmp1);

            if (tmp1.next != 0) {
                tmp1.id = tmp1.next;
                tmp1.len = len[tmp1.id];
                tmp1.prev = prev[tmp1.id];
                tmp1.next = next[tmp1.id];
                tmp1.val = valu[tmp1.id];
                auto it3 = st.find(tmp1);
                if (it3 != st.end()) {
                    st.erase(it3);
                    tmp1.prev = store.prev;
                    prev[tmp1.id] = tmp1.prev;
                    st.insert(tmp1);
                }
            }

        } else {
            if (store.prev != 0) {
                struct seg tmp1;
                tmp1.id = store.prev;
                tmp1.val = valu[tmp1.id];
                tmp1.len = len[tmp1.id];
                tmp1.prev = prev[tmp1.id];
                tmp1.next = next[tmp1.id];

                auto it1 = st.find(tmp1);
                if (it1 != st.end()) {
                    st.erase(it1);
                    tmp1.next = store.next;
                    next[tmp1.id] = tmp1.next;
                    st.insert(tmp1);
                }
            }

            if (store.next != 0) {
                struct seg tmp1;
                tmp1.id = store.next;
                tmp1.len = len[tmp1.id];
                tmp1.val = valu[tmp1.id];
                tmp1.prev = prev[tmp1.id];
                tmp1.next = next[tmp1.id];

                auto it1 = st.find(tmp1);
                if (it1 != st.end()) {
                    st.erase(it1);
                    tmp1.prev = store.prev;
                    prev[tmp1.id] = tmp1.prev;
                    st.insert(tmp1);
                }
            }
        }
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}