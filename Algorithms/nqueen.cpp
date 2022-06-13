#include<iostream>
#include<cmath>
using namespace std;
int arr[5][5]={0},n=4;
int fun(int j);
int check(int i,int j);
int main(void){
	//int arr[n][n]={0};          // do by vector method
	//cin>>n;
	fun(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;
}

int fun(int j){
	if(j >= n){
		return 1;
	}
	for(int i=0;i<n;i++){
		int d = check(i,j);
		if(d == -1){
			if(i >= n-1){
				return -1;
			}
			else{
				continue;
			}
		}
		else{
			arr[i][j] = 1;
			int c = fun(j+1);
			if(c == -1){
				//cout<<"k";
				arr[i][j] = 0;
				continue;
			}
			else{
				return 1;
			}
		}

	}
}

int check(int row,int col){
	for(int i=0;i<col;i++){
		if(arr[row][i] == 1){
			return -1;
		}
	}
	for(int i=col-1,j=row-1; i>=0 && j>=0;i--,j--){
		if(arr[j][i] == 1){
		return -1;
		}
	}
	for(int i=col-1,j=row+1;i>=0 && j>=0 && j<n; i--,j++){
		if(arr[j][i] == 1){
			return -1;
		}
	}
return 1;
}




	
/*	for(int j=0;j<n;j++){
		if(i != 0){
		//	check by all conditions of out;
			int a = fabs(y - j);
			if((a == 1 || a == 0) && j == n-1){
				return 0;
			}
			else if(a == 1 || a == 0){
				//j++;
				continue;
			}*/
		//	int e = check(i,j);
/*			if(e == 1){
				fun(i+1,j);
			}
*/		/*	if(e == 1){
				arr[i][j] = 1;
				int d = fun(i+1,j);
				if(d == 1) return 1;
				else{
					arr[i][j] = 0;
					//j++;
					continue;
				}
			}
		}*/
	/*	else if(i == 0){
			arr[i][j] = 1;
			int c = fun(i+1,j);
			if(c == 1){
				return 1;   //true
			}
			else{
				arr[i][j] = 0;
				//j++;
				continue;
			}
		}
	}*/
/*return 0;
}*/


