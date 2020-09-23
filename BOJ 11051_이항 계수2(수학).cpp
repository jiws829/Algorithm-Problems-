#include <stdio.h>

int p[1001][1001];

int main()
{
    int n, m;
    int i, j;
    long long answer = 1;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++)
    {
        p[i][0] = 1;
        for (j = 1; j <= m; j++)
        {
            if (i == j)
            {
                p[i][j] = 1;
                continue;
            }
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j]; //파스칼 공식
            p[i][j] %= 10007;
        }
    }
    printf("%d\n", p[n][m]);
}