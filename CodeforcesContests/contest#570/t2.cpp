#include <bits/stdc++.h> 
using namespace std; 
typedef long long int lli;
// Function which returns the numbe of 
// unique subsequences of length K 
lli solution(vector<int> A, llik) 
{ 
	// seiz of the vector 
	// which does is constant 
	const lli N = A.size(); 

	// bases cases 
	if (N < k || N < 1 || k < 1) 
		return 0; 
	if (N == k) 
		return 1; 

	// Prepare arrays for recursion 
	vector<int> v1(N, 0); 
	vector<int> v2(N, 0); 
	vector<int> v3(N, 0); 

	// initiate separately for k = 1 
	// intiate the last element 
	v2[N - 1] = 1; 
	v3[A[N - 1] - 1] = 1; 

	// initiate all other elements of k = 1 
	for (lli i = N - 2; i >= 0; i--) { 

		// initialize the front element 
		// to vector v2 
		v2[i] = v2[i + 1]; 

		// if element v[a[i]-1] is 0 
		// then increment it in vector v2 
		if (v3[A[i] - 1] == 0) { 
			v2[i]++; 
			v3[A[i] - 1] = 1; 
		} 
	} 

	// iterate for all possible values of K 
	for (lli j = 1; j < k; j++) { 

		// fill the vectors with 0 
		fill(v3.begin(), v3.end(), 0); 

		// fill(v1.begin(), v1.end(), 0) 
		// the last must be 0 as from last no unique 
		// subarray can be formed 
		v1[N - 1] = 0; 

		// Iterate for all index from which unique 
		// subsequences can be formed 
		for (lli i = N - 2; i >= 0; i--) { 

			// add the number of subsequence formed 
			// from the next index 
			v1[i] = v1[i + 1]; 

			// start with combinations on the 
			// next index 
			v1[i] = v1[i] + v2[i + 1]; 

			// Remove the elements which have 
			// already been counted 
			v1[i] = v1[i] - v3[A[i] - 1]; 

			// Update the number used 
			v3[A[i] - 1] = v2[i + 1]; 
		} 

		// prepare the next iteration 
		// by filling v2 in v1 
		v2 = v1; 
	} 

	// last answer is stored in v1 
	return v1[0]; 
} 

// Function to push the vector into an array 
// and prlliall the unique subarrays 
lli solve(lli a[], lli n, lli k) 
{ 
	vector<int> v; 

	// fill the vector with a[] 
	v.assign(a, a + n); 

	// Function call to prllithe count 
	// of unique susequences of size K 
	return solution(v, k); 
} 

// Driver Code 
int main() 
{ 	
	lli n,k;
	cin>>n>>k;
	string st;
	cin>>st;
	lli a[200];
	for(lli i=0;i< st.length();i++){
		a[i] = st[i] - 'a' + 1; 	
	}
	for(lli i=0;i<st.length();i++){
		cout<<a[i]<<endl;
	}
	lli cost = 0,p=n-1;
	k--;

	cout<<solve(a,n,1)<<endl;
	while(k != 0 && p > 1){
		lli c = solve(a, n, p); 
		cout<<p<<" "<<c<<endl;
		if(c <= k){
			cost += (n - p)*c; 
			k -= c;
		}
		else{
			cost += (n-p)*k;
			k = 0;
		}
		if(k == 0){
			break;
		}
		--p;
	}

	 cout<<cost<<endl;

	return 0; 
} 
