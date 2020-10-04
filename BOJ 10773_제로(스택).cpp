#include <stdio.h>
#include <vector>
using namespace std;

vector<int> p;

int main()
{
    int n, a;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);

        if (a == 0)
        {
            p.pop_back();
        }
        else
        {
            p.push_back(a);
        }
    }

    int sum = 0;
    for (i = 0; i < p.size(); i++)
        sum += p[i];

    printf("%d\n", sum);
}