#include <iostream>
using namespace std;
int n, m;
bool check[1000001];
int main()
{
    cin >> m >> n;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (check[i] == false)
        {
            for (int j = 2 * i; j <= 1000000; j += i)
                check[j] = true;
        }
    }
    check[0] = check[1] = true;
    for (int i = m; i <= n; i++)
    {
        if (check[i] == false)
            cout << i << '\n';
    }
}