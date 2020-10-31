#include <iostream>
using namespace std;

int n;
int p[51][10];
int answer = 0;
int t[10];
int visited[10];

void simulate()
{
    int point = 0;
    int now = 1;
    int inning = 1;
    int num, out = 0;
    int i;

    int q[4] = {
        0,
    };

    while (1)
    {
        if (inning > n)
            break;
        num = p[inning][t[now++]];

        if (now > 9)
            now = 1;

        if (num == 0)
        {
            out++;
            if (out == 3)
            {
                out = 0;
                q[1] = q[2] = q[3] = 0;
                inning++;
            }
        }
        else if (num == 1)
        {
            point += q[3];
            q[3] = q[2];
            q[2] = q[1];
            q[1] = 1;
        }
        else if (num == 2)
        {
            point += q[2] + q[3];
            q[3] = q[1];
            q[2] = 1;
            q[1] = 0;
        }
        else if (num == 3)
        {
            point += q[1] + q[2] + q[3];
            q[1] = q[2] = 0;
            q[3] = 1;
        }
        else
        {
            point += q[1] + q[2] + q[3] + 1;
            q[1] = q[2] = q[3] = 0;
        }
    }

    if (answer < point)
        answer = point;
}

void dfs(int v)
{
    if (v == 4)
    {
        dfs(v + 1);
        return;
    }

    if (v == 10)
    {
        //for(int i=1;i<=9;i++) printf("%d ",t[i]);
        //printf("\n");
        simulate();
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            t[v] = i;
            dfs(v + 1);
            visited[i] = 0;
            t[v] = 0;
        }
    }
}

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j;

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 9; j++)
            cin >> p[i][j];
    }

    visited[1] = 1;
    t[4] = 1;
    dfs(1);

    cout << answer;
}