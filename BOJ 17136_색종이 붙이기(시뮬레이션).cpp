#include <iostream>
using namespace std;

int p[10][10], n = 10;
int paper[6] = {0, 5, 5, 5, 5, 5};
int answer = 210000000, cnt;

void dfs(int x, int y)
{
    if (x == n)
    {
        if (answer > cnt)
            answer = cnt;
        return;
    }
    if (y == n)
    {
        dfs(x + 1, 0);
        return;
    }
    if (p[x][y] == 0)
    {
        dfs(x, y + 1);
        return;
    }

    for (int len = 5; len >= 1; len--)
    {
        if (paper[len] == 0 || x + len > n || y + len > n)
            continue;

        int flag = 0, i, j;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
            {
                if (p[x + i][y + j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (flag == 1)
            continue;

        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
                p[x + i][y + j] = 0;
        }
        paper[len]--;
        cnt++;
        dfs(x, y + len);

        paper[len]++;
        cnt--;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
                p[x + i][y + j] = 1;
        }
    }
}

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> p[i][j];
    }

    dfs(0, 0);

    if (answer == 210000000)
        answer = -1;
    cout << answer;
}