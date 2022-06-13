#include<bits/stdc++.h>
using namespace std;
int main(void){
	vector<int> v;
	for(int i=0;i<4;i++){
		v.push_back(i+1);
	}
	for(auto itr=v.begin()+1;itr<v.end();itr++){
		cout<<typeid(itr).name()<<endl;
	}
	set<pair<int,int>> st;
	for(int i=0;i<5;i++){
		st.insert(make_pair(5-i,i+1));
	}
	auto it = st.begin();
	++it;
	for(auto itr=it;itr != st.end();itr++){
		//++itr;
		auto pr = *itr;
		cout<<typeid(itr).name()<<endl;
		//cout<<typeid(pr).name()<<endl;
		cout<<pr.first<<" "<<pr.second<<endl;
	}
return 0;
}