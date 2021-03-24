#include <iostream>
#include <string>
using namespace std;
int result;
string x;

int main()
{
    string tmp = "";
    bool flag = false;
    cin >> x;
    int len = x.size();
    for (int i = 0; i <= len; i++)
    {
        if (x[i] == '+' || x[i] == '-' || x[i] == '\0')
        {
            if (flag)
            {
                result -= stoi(tmp);
            }
            else
            {
                result += stoi(tmp);
            }
            tmp = "";
            if (x[i] == '-')
            {
                flag = true;
            }
        }
        else
        {
            tmp += x[i];
        }
    }
    cout << result;
    return 0;
}