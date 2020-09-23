#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int p[51];

int main()
{
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    sort(p, p + n);

    int answer = p[0] * p[n - 1];

    printf("%d\n", answer);
}