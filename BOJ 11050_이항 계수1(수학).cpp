#include <stdio.h>

int main()
{
    int n, m;
    int i;
    int answer = 1;

    scanf("%d %d", &n, &m);

    for (i = m + 1; i <= n; i++)
        answer *= i;
    for (i = 2; i <= (n - m); i++)
        answer /= i;

    printf("%d\n", answer);
}