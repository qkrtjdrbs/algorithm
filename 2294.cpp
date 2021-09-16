#include <bits/stdc++.h>
using namespace std;
int n, k, d[10001], coin[100];

int main()
{
    cin >> n >> k;
    for (int i = 0; i <= k; i++)
        d[i] = k;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    d[0] = 0;
    d[k] = k + 1;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= coin[j])
                d[i] = min(d[i], d[i - coin[j]] + 1);
        }
    }
    d[k] == k + 1 ? d[k] = -1 : d[k];
    cout << d[k];
}