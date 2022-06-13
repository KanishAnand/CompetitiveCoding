#include<iostream>
#include<vector>
using namespace std;
int max(int a,int b);
int stack[100005];
int top=-1;
int max(int a,int b){
	return a<b ? b:a;
}

int push(int val){
	stack[++top] = val;
}


int pop(){
	--top;
}

int main(void){
	int t,n;
	// cin>>t;
	t=1;
	for(int i=0;i<t;i++){
		cin>>n;
		top=-1;
		int a,minleft[100005],minright[100005],arr[100005]={0};
		vector<int> v;
		for(int i=0;i<n;i++){
			cin>>a;
			v.push_back(a);
		}

		top=-1;

		for(int i=0;i<100004;i++){
			minleft[i] = -1;
			minright[i] = -1;
		}

		for(int i=0;i<n;i++){
			if(top == -1){
				push(i);
			}
			else{
				while(v[i] < v[stack[top]] && top != -1){
					minright[stack[top]] = i;
					pop();
				}
				push(i);
			}
		}

		while(top != -1){
			minright[stack[top]] = -1;
			pop();
		}

		top = -1;

		for(int i=n-1;i>=0;i--){
			if(top == -1){
				push(i);
			}
			else{
				while(v[i] < v[stack[top]] && top != -1){
					minleft[stack[top]] = i;
					pop();
				}
				push(i);
			}
		}	

		while(top != -1){
			minleft[stack[top]] = -1;
			pop();
		}

		// for(int i=0;i<n;i++){
		// 	cout<<minleft[i]<<" "<<minright[i]<<endl;
		// }

		for(int i=0;i<n;i++){
			if(minright[i] == -1 && minleft[i] == -1){
				arr[n] = max(arr[n],v[i]);
			}

			else if(minleft[i] == -1){
				arr[minright[i]] = max(v[i],arr[minright[i]]);
			}

			else if(minright[i] == -1){
				arr[n- minleft[i]-1] = max(v[i],arr[n-minleft[i]-1]);
			}

			else{
				arr[minright[i] - minleft[i] - 1] = max(v[i],arr[minright[i] - minleft[i] - 1]);
			}
		}

		// for(int i=n-1;i>=0;i--){
		// 	if(arr[i] == 0){
		// 		arr[i] = arr[i+1];
		// 	}
		// }

		// for(int i=n-1;i>=0;i--){
		// 	arr[i]=max(arr[i],arr[i+1]);
		// }
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}

		// cout<<endl;
	}
	return 0;
}
