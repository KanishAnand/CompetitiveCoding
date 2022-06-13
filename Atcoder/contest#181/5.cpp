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
    lli n, a,m;

    cin>>n>>m;
    vector<lli> v,w;

    for (lli i = 0; i < n; i++) {
        cin>>a;
        v.pb(a);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a;
        w.pb(a);
    }

    sort(all(v));

    vector<lli> pref(n+2,0), suff(n+2,0);

    for (lli i = 1; i < n; i+=2) {
        if(i != 1){
            pref[i] = pref[i-2];
        }
        pref[i] += v[i] - v[i-1];
    }

    for (lli i = n - 2; i >= 0; i-=2) {
        if(i != n - 2){
            suff[i] = suff[i+2];
        }
        suff[i] += v[i+1] - v[i];
    }

    lli ans = 1e17;

    for (lli i = 0; i < m; i++) {
        lli val = w[i];
        auto it = lower_bound(v.begin(), v.end(), val);
        
        if(it == v.end()){
            lli no = val - v[n-1];
            if(n >= 2){
                no += pref[n-2];
            }
            ans = min(ans,no);
            continue;
        }

        lli ind = it - v.begin();
        lli prev = ind;
        lli no = 0;

        if(prev % 2 == 0){
            if(ind != 0){
                no += pref[ind - 1];
            }

            no += v[ind] - val;

            if(ind + 1 < n){
                no += suff[ind+1];
            }
        }
        else{
            if(ind >= 2){
                no += pref[ind - 2];
            }

            no += val - v[ind - 1];

            if(ind < n){
                no += suff[ind];
            }
        }

        ans = min(ans,no);
    }

    cout<<ans<<endl;

}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}