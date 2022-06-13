#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

lli ans = 0;

struct trie {
    lli endofword;
    struct trie *child[676];
};

struct trie *getnode() {
    struct trie *node = new trie;
    node->endofword = 0;
    fr(i, 0, 676) {
        node->child[i] = NULL;
    }
    return node;
}

struct trie *root;

lli insert(string st) {
    struct trie *head = root;
    lli beg = 0;
    lli l = st.length();
    while (beg < st.length()) {
        lli val = st[beg] - 'a';
        lli val2 = st[l - beg - 1] - 'a';
        lli p = val * 26 + val2;
        if (head->child[p] == NULL) {
            head->child[p] = getnode();
        }
        head = head->child[p];
        beg++;
    }
    head->endofword++;
}

lli dfs(struct trie *node, lli level) {
    level++;
    for (lli i = 0; i < 676; i++) {
        if (node->child[i] != NULL) {
            node->endofword += dfs(node->child[i], level);
        }
    }

    lli val = node->endofword;
    ans += (level * level) * (val / 2);
    level--;
    return val % 2;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t;
    cin >> t;
    string st;
    while (t--) {
        ans = 0;
        root = getnode();
        cin >> n;
        fr(i, 0, n) {
            cin >> st;
            insert(st);
        }
        dfs(root, -1);
        cout << ans << endl;
    }
    rt;
}
