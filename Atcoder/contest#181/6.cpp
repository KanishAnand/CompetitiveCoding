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


double radi(double x1, double y1, double x2, double y2, double x3, double y3){
	double x12 = x1 - x2; 
	double x13 = x1 - x3; 

	double y12 = y1 - y2; 
	double y13 = y1 - y3; 

	double y31 = y3 - y1; 
	double y21 = y2 - y1; 

	double x31 = x3 - x1; 
	double x21 = x2 - x1; 

	// x1^2 - x3^2 
    double sx13 = pow(x1, 2) - pow(x3, 2); 

	// y1^2 - y3^2 
	double sy13 = pow(y1, 2) - pow(y3, 2); 

	double sx21 = pow(x2, 2) - pow(x1, 2); 
	double sy21 = pow(y2, 2) - pow(y1, 2); 

	double f = ((sx13) * (x12) 
			+ (sy13) * (x12) 
			+ (sx21) * (x13) 
			+ (sy21) * (x13)) 
			/ (2 * ((y31) * (x12) - (y21) * (x13))); 
	double g = ((sx13) * (y12) 
			+ (sy13) * (y12) 
			+ (sx21) * (y13) 
			+ (sy21) * (y13)) 
			/ (2 * ((x31) * (y12) - (x21) * (y13))); 

	double c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1; 

	// eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0 
	// where centre is (h = -g, k = -f) and radius r 
	// as r^2 = h^2 + k^2 - c 
	double h = -g; 
	double k = -f; 
	double sqr_of_r = h * h + k * k - c; 

	// r is the radius 
	double r = sqrt(sqr_of_r); 

	// cout << "Centre = (" << h << ", " << k << ")" << endl; 
	// cout << "Radius = " << r; 
    return r;
} 

void solve() {
    double n, a,b;
    cin>>n;
    vector<pair<double,double>> v;

    for (lli i = 0; i < n; i++) {
        cin >> a>>b;
        v.pb({a,b});
    }

    double ans = -1;

    for (lli i = 0; i < sz(v); i++) {
        double x1 = v[i].first, y1 = v[i].second;
        vector<pair<double,double>> tmp = v;
        tmp.pb({x1,100});
        tmp.pb({x1,-100});
        double q = 0;
        double p = -1;

        for (lli j = 0; j < sz(tmp); j++) {
            double x2 = v[j].first, y2 = v[j].second;
            if(x1 == x2 && y1 == y2){
                continue;
            }
            p = -1;

            for (lli k = 0; k < sz(v); k++) {
                double x3 = v[k].first, y3 = v[k].second;
                if((x3 == x2 && y3 == y2) ||  (x3 == x1 && y3 == y1)){
                    continue;
                }
                double val = radi(x1,y1,x2,y2,x3,y3);
                if(p == -1){
                    p = val;
                }
                p = min(val,p);
            }
            q = max(q, p);
        }
        if(ans == -1){
            ans = q;
        }
        ans = min(ans,q);
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