#include <stdio.h>
#include <algorithm>

using namespace std;

long long find_num(long long num, long long cnt)
{
    long long ans = 0;
    int tmp = cnt;
    while (1)
    {
        if (num < cnt)
            return ans;
        ans += num / cnt;
        cnt *= tmp;
    }
}

int main()
{
    long long n, m;
    long long two, five;

    scanf("%lld %lld", &n, &m);

    two = find_num(n, 2) - find_num(m, 2) - find_num(n - m, 2);
    five = find_num(n, 5) - find_num(m, 5) - find_num(n - m, 5);

    //printf("%lld %lld\n",two,five);

    printf("%lld\n", min(two, five));
}