#include <stdio.h>

int n;

bool prime(int num)
{
    if (num == 2)
        return true;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int i;

    scanf("%d", &n);

    i = 2;
    while (n > 1)
    {
        //printf("%d %d\n",i,n);
        if (i != 2 && i % 2 == 0)
            i++;

        if (n % i == 0 && prime(i) == true)
        {
            printf("%d\n", i);
            n /= i;
        }
        else
            i++;
    }
}