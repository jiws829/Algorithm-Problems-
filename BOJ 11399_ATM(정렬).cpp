#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int p[1001];

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    sort(p, p + n);

    //for(i=0;i<n;i++) printf("%d ",p[i]);

    int sum = 0;
    int tmp = 0;
    for (i = 0; i < n; i++)
    {
        sum += tmp + p[i];
        tmp += p[i];
    }

    printf("%d\n", sum);
}