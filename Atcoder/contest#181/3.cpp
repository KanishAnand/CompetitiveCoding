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
    lli n, a,b;
    cin>>n;

    vector<pair<lli,lli>> v;
    for (lli i = 0; i < n; i++) {
        cin>>a>>b;
        v.pb({a,b});
    }


    for (lli i = 0; i < n; i++) {
        for (lli j = i+1; j < n; j++) {
            for (lli k = j+1; k < n; k++) {
                lli x1 = v[i].first, y1 = v[i].second;
                lli x2 = v[j].first, y2 = v[j].second;
                lli x3 = v[k].first, y3 = v[k].second;
                lli area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                if(area == 0){
                    cout<<"Yes"<<endl;
                    exit(0);    
                }
            }
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