#include <iostream>
#include <algorithm>
using namespace std;
int n, w[1001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w + n);
    if (w[0] != 1)
    {
        cout << 1;
        return 0;
    }
    int sum = 1;
    for (int i = 1; i < n; i++)
    {
        if (sum + 1 < w[i])
        {
            break;
        }
        sum += w[i];
    }
    cout << sum + 1;
}