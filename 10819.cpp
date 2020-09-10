#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,ans=0;
int cal(vector<int> &a){
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=abs(a[i-1]-a[i]);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    do
    {
        int tmp = cal(a);
        ans=max(ans,tmp);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans;
}