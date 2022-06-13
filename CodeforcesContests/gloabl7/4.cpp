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
 
// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % MOD;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }
 
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
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

    lli ans,leng = -1;

    for(lli i=beg;i<=end;i++){
        lli s = beg,e = i,flag=0,cnt=0;

        while(s <= e){
            if(st[s] == st[e]){
                ++cnt;
                s++;
                e--;
            }
            else{
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            ans = i; 
            leng = i - beg + 1;   
        }
    }

    lli ans2,leng2 = -1;

    for(lli i=end;i>=beg;i--){
        lli s = i,e = end,flag=0,cnt=0;
        while(s <= e){
            if(st[s] == st[e]){
                ++cnt;
                s++;
                e--;
            }
            else{
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            ans2 = i; 
            leng2 = end - i + 1;   
        }
    }

    string part3;

    if(leng > leng2){
        part3 = st.substr(beg,leng);
    }
    else{
        part3 = st.substr(ans2,leng2);
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