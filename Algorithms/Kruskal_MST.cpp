#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct edge {
    lli src;
    lli des;
    lli wt;
};

vector<struct edge> ed;
lli king[10005], rankk[10005];

bool cmp(edge &a, edge &b) {
    return (a.wt < b.wt);
}

lli find(lli val) {
    if (king[val] == val) {
        return val;
    }
    king[val] = find(king[val]);
    return king[val];
}

lli merge(lli a, lli b) {
    if (rankk[a] < rankk[b]) {
        king[a] = king[b];
    } else if (rankk[a] == rankk[b]) {
        king[a] = king[b];
        ++rankk[b];
    } else {
        king[b] = king[a];
    }
    return 0;
}

int main(void) {
    lli n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        struct edge t;
        cin >> t.src >> t.des >> t.wt;
        ed.push_back(t);
    }

    sort(ed.begin(), ed.end(), cmp);
    vector<struct edge>::iterator itr;
    lli mst = 0;
    for (int i = 1; i <= n; i++) {
        king[i] = i;
        rankk[i] = 0;
    }

    // for(itr = ed.begin();itr < ed.end();itr++){
    // 	king[itr->des] = itr->src;
    // }

    for (itr = ed.begin(); itr < ed.end(); itr++) {
        int c = find(itr->src);
        int d = find(itr->des);
        if (c != d) {
            mst += itr->wt;
            merge(c, d);
        }
    }
    cout << mst << endl;
    return 0;
}
