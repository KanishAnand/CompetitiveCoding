#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n, b, a;
    vector<int> v;
    cin >> n >> b;
    int maxa[n + 5], no;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int max = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] >= max)
        {
            max = v[i];
        }
	maxa[i] = max;
    }

    int cp,p=b;
	int Max=0;
    for (int i = 0; i < n; i++)
    {	p=b;
        no = b / v[i];
        cp = no * v[i];
        p -= cp;
        p += maxa[i] * no;
	if(p>Max){
		Max=p;
	}
    }

    cout << Max << endl;
    return 0;
}
