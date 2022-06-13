#include<bits/stdc++.h>
using namespace std;
struct box{
	struct box *arr[27];
	int end;
	int pre;
};

int insert(string st,struct box *node){

	for(int j=0;j<st.length();j++){
		char s = st[j];

		if(node->arr[s-'a'] == NULL){
			struct box *ne;
			//ne = malloc(sizeof(struct box));
			ne = new box;
			for(int i=0;i<27;i++){
				ne->arr[i] = NULL;
			}
			ne->end = 0;
			ne->pre=0;
			node->arr[s-'a'] = ne;
			node=ne;
			if(j == st.length()-1){
				node->end = 1;
				node->pre += 1;
			}
		}

		else{
			node = node->arr[s-'a'];
			if(j == st.length()-1){
				node->end = 1;
				node->pre += 1;
			}
		}
	}
return 0;
}

int cal(struct box *node){
	for(int i=0;i<26;i++){
		if(node->arr[i] != NULL){
			node->pre += cal(node->arr[i]);
		}
	}
	return node->pre;
}

int searc(string st,struct box *node){
	
	for(int i=0;i<st.length();i++){
		if(node->arr[st[i]-'a'] != NULL){
			node = node->arr[st[i]-'a'];
			if(i == st.length()-1){
				return node->pre;
			}
		}
		else{
			return 0;
		}
	}
return 0;
}

int main(void){
	int n,q;
	cin>>n>>q;
	string str;
	struct box *root;
	//root = malloc(sizeof(struct box));
	root = new box;
	for(int i=0;i<27;i++){
		root->arr[i] = NULL;
	}
	root->end = 0;
	root->pre=0;
	for(int i=0;i<n;i++){
		cin>>str;
		insert(str,root);
	}
	cal(root);
	for(int i=0;i<q;i++){
		string stri;
		cin>>stri;
		cout<<searc(stri,root)<<endl;
	}

return 0;
}