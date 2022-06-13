#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n, b, a;
    vector<int> v;
    cin >> n >> b;
    int maxa[n + 5], no[n + 5], key, ind[n + 5], p[n + 5] = {0};
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
            key = i;
        }
        maxa[i] = max;
        ind[i] = key;
    }

    int cp;
    p[0] = b;

    for (int i = 0; i < n; i++)
    {
        no[i] = p[i] / v[i];
        cp = no[i] * v[i];
        p[i] -= cp;
        p[ind[i]] += maxa[i] * no[i];
        p[i + 1] += p[i];
    }

    cout << p[n - 1] << endl;
    return 0;
}