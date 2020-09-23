#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int n, m;
int p[11];
int minimum = INT_MAX;

void cal(int money, int now, int cnt)
{
    //printf("%d %d %d\n",money,now,cnt);
    if (money == 0)
    {
        if (minimum > cnt)
            minimum = cnt;
        return;
    }
    int i;
    for (i = now - 1; i >= 0; i--)
    {
        if (p[i] > money)
            continue;
        else
        {
            cal(money % p[i], i, cnt + (money / p[i]));
        }
    }
}

int main()
{
    //freopen("./c++/input.txt", "r", stdin);

    int i;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = n - 1; i >= 0; i--)
    {
        if (p[i] > m)
            continue;
        else
        {
            //printf("!! %d %d\n",p[i],m);
            cal(m % p[i], i, m / p[i]);
        }
    }
    printf("%d\n", minimum);
}
