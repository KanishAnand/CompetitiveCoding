#include<iostream>
#include<stack>
using namespace std;
int main(void){
	stack<int> s;
	s.push(3);
	s.push(5);
	cout<<s.size()<<endl;
	s.pop();

	//s.pop();
	cout<<s.top()<<endl;
return 0;
}