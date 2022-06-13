#include<bits/stdc++.h>
using namespace std;
struct box{
	map<char,struct box*> mp;
	int end=0;
};

int insert(struct box *node,string st){
	for(int i=0;i<st.length();i++){
		if(i == st.length() - 1){
			node->end = 1;
		}
	
		if(node->mp.find(st[i]) != node->mp.end()){
			auto it = node->mp.find(st[i]);
			node  = it->second;
		}
		else{
			struct box *n;
			n = malloc(sizeof(struct box));
			n.end = 0;
			node->mp.insert(st[i],n);
			node = n;
		}
	}
return 0;
}

int main(void){
	int n;
	cin>>n;
	stirng str;
	struct box root;
	for(int i=0;i<n;i++){
		cin>>str;
		insert(root,str);
	}
}