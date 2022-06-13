#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

vector<lli> king, rankk;

struct edg {
    lli src, des, cost;
};

lli cmp(struct edg a, struct edg b) {
    return a.cost < b.cost;
}

lli check(lli e) {
    if (king[e] != e) {
        king[e] = check(king[e]);
        return king[e];
    } else {
        return e;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] > rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, m, k, b, c;
    cin >> n >> m >> k;
    vector<lli> v(n + 2, 0);
    king.resize(n + 2, 0);
    rankk.resize(n + 2, 0);
    fr(i, 0, k) {
        cin >> a;
        v[a] = 1;
    }
    vector<struct edg> edge;
    fr(i, 0, m) {
        struct edg t;
        cin >> t.src >> t.des >> t.cost;
        edge.pb(t);
    }

    fr(i, 0, n + 2) {
        king[i] = i;
        rankk[i] = 1;
    }

    sort(edge.begin(), edge.end(), cmp);
    lli cnt = 0, wt;
    for (lli i = 0; i < edge.size(); i++) {
        if (cnt == k) {
            break;
        }
        a = edge[i].src;
        b = edge[i].des;
        c = edge[i].cost;
        lli c1 = check(a);
        lli c2 = check(b);
        if (c1 != c2) {
            wt = c;
            cout << wt << " " << cnt << endl;
            if (v[a] == 1) {
                v[a] = 0;
                ++cnt;
            }
            if (v[b] == 1) {
                v[b] = 0;
                ++cnt;
            }
            cout << wt << " " << cnt << endl;
            merge(a, b);
        }
    }

    fr(i, 0, k) {
        cout << wt << " ";
    }
    cout << endl;
    rt;
}