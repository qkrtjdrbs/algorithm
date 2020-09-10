#include <iostream>
#include <cstdlib>
using namespace std;
int n, s, a[100001], dist[100001];
int get_gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dist[i] = abs(a[i] - s);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        dist[i + 1] = get_gcd(dist[i], dist[i + 1]);
    }
    cout << dist[n];
}