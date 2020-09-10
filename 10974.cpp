#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
}