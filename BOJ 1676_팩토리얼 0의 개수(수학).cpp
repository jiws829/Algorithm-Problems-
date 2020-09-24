#include <stdio.h>

int main()
{
    int n;
    int answer = 0;
    int tmp = 5;

    scanf("%d", &n);

    while (1)
    {
        if (tmp > n)
            break;
        answer += n / tmp;
        tmp *= 5;
    }
    printf("%d\n", answer);
}