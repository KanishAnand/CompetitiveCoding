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

struct Trie {
    Trie *arr[26];
};

Trie *root;
map<Trie *, lli> dp_win, dp_lose;

void dfs(Trie *node) {
    int leaf = 1;
    for (lli i = 0; i < 26; i++) {
        if (node->arr[i] != NULL) {
            leaf = 0;
            Trie *child = node->arr[i];
            dfs(child);
            if (dp_lose[child] == 0) {
                dp_lose[node] = 1;
            }
            if (dp_win[child] == 0) {
                dp_win[node] = 1;
            }
        }
    }

    if (leaf == 1) {
        dp_lose[node] = 1;
    }
}

Trie *get() {
    Trie *node = new Trie();
    for (lli i = 0; i < 26; i++) {
        node->arr[i] = NULL;
    }
    return node;
}

void insert(string st) {
    lli n = st.length();
    Trie *node = root;
    for (lli i = 0; i < n; i++) {
        if (node->arr[st[i] - 'a'] == NULL) {
            node->arr[st[i] - 'a'] = get();
        }
        node = node->arr[st[i] - 'a'];
    }
}

void solve() {
    lli n, k;
    cin >> n >> k;
    string st;
    root = get();

    for (lli i = 0; i < n; i++) {
        cin >> st;
        insert(st);
    }

    dfs(root);

    lli win = dp_win[root], lose = dp_lose[root];

    if (win == 1 && lose == 0) {
        if (k % 2 == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    } else if (win == 0 && lose == 1) {
        cout << "Second" << endl;
    } else if (win == 1 && lose == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}