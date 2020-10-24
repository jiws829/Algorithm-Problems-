#include <stdio.h>

int n;
int p[505][505];

int dx[4][10] = {{-1, 1, -1, 1, 0, -2, 2, -1, 1, 0}, {1, 1, 0, 0, 2, 0, 0, -1, -1, 1}, {-1, 1, -1, 1, 0, -2, 2, -1, 1, 0}, {-1, -1, 0, 0, -2, 0, 0, 1, 1, -1}};
int dy[4][10] = {{-1, -1, 0, 0, -2, 0, 0, 1, 1, -1}, {-1, 1, -1, 1, 0, -2, 2, -1, 1, 0}, {1, 1, 0, 0, 2, 0, 0, -1, -1, 1}, {-1, 1, -1, 1, 0, -2, 2, -1, 1, 0}};
int dz[9] = {10, 10, 7, 7, 5, 2, 2, 1, 1};

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j;
    int x, y, num, cnt, phase;
    int tmp, sum;
    int answer = 0, ans = 0;

    scanf("%d", &n);
    for (i = 2; i <= n + 1; i++)
    {
        for (j = 2; j <= n + 1; j++)
        {
            scanf("%d", &p[i][j]);
            answer += p[i][j];
        }
    }

    x = y = (2 + n + 1) / 2;
    phase = num = 1;
    cnt = 0;

    while (1)
    {
        if (phase == 1)
            y--;
        else if (phase == 2)
            x++;
        else if (phase == 3)
            y++;
        else if (phase == 4)
            x--;

        if (x == 2 && y == 1)
            break;

        /*printf("%d %d\n",x-1,y-1);
        for(i=2;i<=n+1;i++){
            for(j=2;j<=n+1;j++) printf("%3d ",p[i][j]);
            printf("\n");
        }
        printf("----------\n");*/

        //모래 이동
        sum = 0;
        for (i = 0; i < 9; i++)
        {
            tmp = (int)p[x][y] * dz[i] / 100;
            p[x + dx[phase - 1][i]][y + dy[phase - 1][i]] += tmp;
            sum += tmp;
        }
        p[x + dx[phase - 1][9]][y + dy[phase - 1][9]] += p[x][y] - sum;
        p[x][y] = 0;

        /*printf("%d %d\n",x,y);
        for(i=2;i<=n+1;i++){
            for(j=2;j<=n+1;j++) printf("%4d ",p[i][j]);
            printf("\n");
        }
        printf("----------\n");*/

        cnt++;
        if (num == cnt)
        {
            cnt = 0;
            phase++;
            if (phase == 5)
                phase = 1;

            if (phase == 1 || phase == 3)
                num++;
        }
    }

    for (i = 2; i <= n + 1; i++)
    {
        for (j = 2; j <= n + 1; j++)
            ans += p[i][j];
    }

    printf("%d\n", answer - ans);
}