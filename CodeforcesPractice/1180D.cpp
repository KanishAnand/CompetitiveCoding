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
	lli n,m;
	vector<lli> v;
	cin>>n>>m;
	lli row_start = 1,row_end = n;
	lli column_start = 1,column_end = m;

	while(row_start <= row_end){
		if(row_start != row_end){
			cout<<row_start<<" "<<column_start<<"\n";
			cout<<row_end<<" "<<column_end<<"\n";
			column_start++;
			column_end--;
		}
		else{
			while(column_start < column_end){
				cout<<row_start<<" "<<column_start<<"\n";
				cout<<row_start<<" "<<column_end<<"\n";
				column_start++;
				column_end--;
			}
			if(column_start == column_end){
				cout<<row_start<<" "<<column_end<<"\n";
				column_start++;
				column_end = 0;	
			}
			row_start++;
			row_end--;
		}

		if(column_end == 0){
			row_start++;
			row_end--;
			column_start=1;
			column_end=m;
		}
	}
rt;
}
	
