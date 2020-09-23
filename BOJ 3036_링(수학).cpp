#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int num, a, b;

    scanf("%d", &n);
    scanf("%d", &num);
    for (i = 1; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        for (j = num; j >= 1; j--)
        {
            if (num % j == 0 && tmp % j == 0)
                break;
        }
        printf("%d/%d\n", num / j, tmp / j);
    }
}