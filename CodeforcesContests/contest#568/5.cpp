#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,a;
    vector<lli> diff;
    vector<pair<lli,lli>> v;
    cin>>n; 
    if(n == 2 || n == 3){
        cout<<"1"<<endl;
        rt;
    }

    // diff.resize(n+2);
    diff.pb(0);
    fr(i,0,n){
        cin>>a;
        v.pb(make_pair(a,i+1));
    }
    //set<pair<lli,lli>> st;
    set<lli> s;
    lli k=0;
    sort(v.begin(),v.end());
    fr(i,1,n){
        diff.pb(v[i].first  - v[i-1].first);
        //cout<<diff[i]<<endl;
        if(s.empty() || s.find(diff[i]) == s.end()){
            ++k;
            s.insert(diff[i]);
        }
    }
    //cout<<s.size()<<endl;

    if(k == 1){
        cout<<v[0].second<<endl;
        rt;
    }

    if(k == 2){
        auto itr = s.begin();
        lli s2 = *itr,c1=0,c2=0;
        ++itr;
        lli s1 = *itr;
        
        for(lli i=1;i<n;i++){
            if(diff[i] == s1){
                ++c1;
            }
            else if(diff[i] == s2){
                ++c2;
            }
        }

        if(c1 < c2){
            lli temp2 = s2;
            lli temp = c2;
            c2 = c1;
            s2 = s1;
            s1 = temp2;
            c1 = temp;
        }

        if(c2 == 1){
            for(lli i=1;i<n;i++){
                if(diff[i] == s2){
                    if(i == n-1){
                        cout<<v[i].second<<endl;
                        rt;
                    }
                    else{
                        if(s2 == 0){
                            cout<<v[i].second<<endl;
                            rt;
                        }
                        else if(i == 1){
                            cout<<v[0].second<<endl;
                            rt;
                        }
                        else{
                            cout<<"-1"<<endl;
                            rt;
                        }
                    }
                }
            }
        }
        else if(c2 == 2){
            if(s2 + s2 == s1){
                //cout<<"K";
                fr(i,1,n){
                    if(i != n-1 && diff[i] == s2 && diff[i+1] == s2){
                        cout<<v[i].second<<endl;
                        rt;
                    }
                }
                cout<<"-1"<<endl;
                rt;
            }
            else{
                cout<<"-1"<<endl;
                rt;
            }
        }
        else{
            cout<<"-1"<<endl;
            rt;
        }
        
    }

    else if(k == 3){
        auto itr = s.begin();
        lli s1 = *itr;
        ++itr;
        lli s2 = *itr;
        ++itr;
        lli s3 = *itr;
        lli c1=0,c2=0,c3=0;

        for(lli i=1;i<n;i++){
            if(diff[i] == s1){
                ++c1;
            }
            else if(diff[i] == s2){
                ++c2;
            }
            else{
                ++c3;
            }
        }

        vector<pair<lli,lli>> t;
        t.pb(make_pair(c1,s1));
        t.pb(make_pair(c2,s2));
        t.pb(make_pair(c3,s3));

        sort(t.begin(),t.end());
        c1 = t[0].first;
        c2 = t[1].first;
        c3 = t[2].first;

        if(c1 != 1 || c2 != 1){
            cout<<"-1"<<endl;
            rt;
        }
        if(t[0].second + t[1].second == t[2].second){
            for(lli i=1;i<n;i++){
                if(diff[i] == t[0].second){
                    if(i != n-1 && diff[i+1] == t[1].second){
                        cout<<v[i].second<<endl;
                        rt;
                    }
                    else{
                        cout<<"-1"<<endl;
                        rt;
                    }
                }
                if(diff[i] == t[1].second){
                    if(i != n-1 && diff[i+1] == t[0].second){
                        cout<<v[i].second<<endl;
                        rt;
                    }
                    else{
                        cout<<"-1"<<endl;
                        rt;
                    }
                }
            }
            cout<<"-1"<<endl;
            rt;
        }
        else{
            cout<<"-1"<<endl;
            rt;
        }
    }

    else{
        cout<<"-1"<<endl;
    }
rt;
}
    
