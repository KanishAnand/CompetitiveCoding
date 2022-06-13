#include <iostream>
using namespace std;
int main(void)
{
    int n, m, c, d, k, min = 1e9, ans;
    cin >> c >> d;
    cin >> n >> m >> k;
    int p = n * m - k;
    if (p <= 0)
    {
        cout << "0" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i <= m + 5; i++)
        {
            for (int j = 0; j <= p + 5; j++)
            {
                if (i * n + j >= p)
                {
                    ans = i * c + j * d;
                    if (ans < min)
                    {
                        min = ans;
                    }
                    break;
                }
            }
        }
    }
    cout << min << endl;
    return 0;
}