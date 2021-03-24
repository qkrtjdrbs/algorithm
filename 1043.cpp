#include <iostream>
using namespace std;
int n, m, answer, person[51], personIdx, party[51][51], partyIdx[51], parent[51];

/* find(x): 재귀 이용 */
int find(int x)
{
    // 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        // 각 노드의 부모 노드를 찾아 올라간다.
        return find(parent[x]);
    }
}

/* union(x, y) */
void merge(int x, int y)
{
    // 각 원소가 속한 트리의 루트 노드를 찾는다.
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int main()
{
    for (int i = 0; i < 51; i++)
        parent[i] = i;
    int knowNum;
    cin >> n >> m;
    cin >> knowNum;
    for (int i = 0; i < knowNum; i++)
    {
        int num;
        cin >> num;
        person[i] = num;
        personIdx += 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int personNum;
            cin >> personNum;
            party[i][j] = personNum;
            partyIdx[i] += 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < partyIdx[i] - 1; j++)
        {
            merge(party[i][j], party[i][j + 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int flag = 0;
        for (int j = 0; j < partyIdx[i]; j++)
        {
            for (int k = 0; k < personIdx; k++)
            {
                if (find(person[k]) == find(party[i][j]))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            answer += 1;
        }
    }
    cout << answer;
}