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
 
void solve() {
    lli n, a;
    string st;
    cin>>st;
    
    map<lli,lli> mp;
    for (lli i = 0; i < st.length(); i++) {
        mp[st[i] - '0']++;
    }

    if(st.length() == 1){
        if(st == "0" || st == "8"){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        return;
    }

    if(st.length() == 2){
        for (lli i = 0; i <= 99; i+=8) {
            lli val = i;
            map<lli,lli> temp;
            vector<lli> v;

            while(v.size() < 2){
                lli rem = val % 10;
                v.pb(rem);
                temp[rem]++;
                val /= 10;
            }
            
            if(mp[v[0]] >= temp[v[0]] && mp[v[1]] >= temp[v[1]]){
                cout<<"Yes"<<endl;
                exit(0);
            }
        }
        cout<<"No"<<endl;
        return;
    }

    for (lli i = 0; i <= 999; i+=8) {
        lli val = i;
        map<lli,lli> temp;
        vector<lli> v;

        while(v.size() < 3){
            lli rem = val % 10;
            v.pb(rem);
            temp[rem]++;
            val /= 10;
        }
        
        if(mp[v[0]] >= temp[v[0]] && mp[v[1]] >= temp[v[1]] && mp[v[2]] >= temp[v[2]]){
            cout<<"Yes"<<endl;
            exit(0);
        }
    }

    cout<<"No"<<endl;
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}