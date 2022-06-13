#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
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

lli longest_palindrome_prefix(string s) 
{
    string kmprev = s;
    std::reverse(kmprev.begin(), kmprev.end());
    string kmp = s + "#" + kmprev;

    vector<int> lps(kmp.size(), 0);  
    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];

        while (prev_idx > 0 && kmp[i] != kmp[prev_idx])
        {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }

    return lps[lps.size() - 1];
} 

void solve() {
    lli n, a;
    string st;
    cin>>st;
    lli beg = 0,end = st.length()-1;
    string part1="";

    while(beg <= end){
        if(st[beg] == st[end]){
            part1.pb(st[beg]);
            beg++;
            end--;
        }
        else{
            break;
        }
    }

    if(st[beg] == st[end]){
        cout<<st<<endl;
        return;
    }

    string st1 = st.substr(beg,end-beg+1);
    string st2 = st1;
    reverse(all(st2));
    string part3;

    lli aa = longest_palindrome_prefix(st1);
    lli bb = longest_palindrome_prefix(st2);

    if(aa > bb){
        part3 = st.substr(beg,aa);
    }
    else{
        part3 = st.substr(end-bb+1,bb);
    }

    string part2 = part1;
    reverse(part2.begin(),part2.end());
    string an = part1 + part3 + part2;
    cout<<an<<endl;
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t; cin >> t; while(t--)
    solve();
    rt;
}