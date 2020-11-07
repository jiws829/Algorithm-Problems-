#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int p[101][101];
int visited[101];

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j, k;
    int a, b;
    vector<int> ans;

    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        p[a][b] = p[b][a] = 1;
    }

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (p[i][k] != 0 && p[k][j] != 0)
                {
                    if (p[i][j] == 0)
                        p[i][j] = p[i][k] + p[k][j];
                    else if (p[i][j] > p[i][k] + p[k][j])
                        p[i][j] = p[i][k] + p[k][j];
                }
            }
        }
    }

    /*for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) printf("%d ",p[i][j]);
        printf("\n");
    }*/
    for (i = 1; i <= n; i++)
    {
        if (visited[i] != 0)
            continue;

        int minn = 21000000, flag;
        for (j = 1; j <= n; j++)
        {
            if (i != j && p[i][j] == 0)
                continue;

            visited[j] = 1;
            int maxx = -999;
            for (k = 1; k <= n; k++)
            {
                if (p[j][k] > 0 && maxx < p[j][k])
                    maxx = p[j][k];
            }

            if (minn > maxx)
            {
                minn = maxx;
                flag = j;
            }
        }

        ans.push_back(flag);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}