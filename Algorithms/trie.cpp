#include<bits/stdc++.h>
using namespace std;
struct box{
	struct box *arr[27];
	int end;
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
			node->arr[s-'a'] = ne;
			node=ne;
			if(j == st.length()-1){
				node->end = 1;
			}
		}

		else{
			node = node->arr[s-'a'];
			if(j == st.length()-1){
				node->end = 1;
			}
		}
	}
return 0;
}

int searc(string st,struct box *node){
	int flag = 0;

	for(int i=0;i<st.length();i++){
		if(node->arr[st[i]-'a'] != NULL){
			node = node->arr[st[i]-'a'];
			if(i == st.length()-1){
				if(node->end != 1){
					flag = 1;
					//cout<<"k";
					break;
				}	
			}
		}
		else{
			flag = 1;
			//cout<<i;
			break;
		}
	}
return flag;
}

int main(void){
	int n;
	cin>>n;
	string str;
	struct box *root;
	//root = malloc(sizeof(struct box));
	root = new box;
	for(int i=0;i<27;i++){
		root->arr[i] = NULL;
	}
	root->end = 0;
	for(int i=0;i<n;i++){
		cin>>str;
		insert(str,root);
	}
	//cout<<root->arr[0]<<" ";
	//root = root->arr[0];
	//root=root->arr['l'-'a'];
	//cout<<root->end<<endl;
	//for(int i=0;i<26;i++)
	//cout<<root->arr[i];
	string stri;
	cin>>stri;
	cout<<!searc(stri,root)<<endl;

return 0;
}