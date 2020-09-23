#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p[101];
vector<int> answer;

int main()
{
    //freopen("./c++/input.txt", "r", stdin);

    int i;
    int a, b, c;
    int st;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    sort(p, p + n);

    st = p[0];
    a = p[1] - p[0];
    for (i = 2; i < n; i++)
    {
        b = p[i] - st;

        if (a < b)
        {
            c = a;
            a = b;
            b = c;
        }
        while (1)
        {
            c = a % b;
            if (c == 0)
                break;
            a = b;
            b = c;
        }
        a = b;
    }

    //printf("%d\n",a);

    for (i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            answer.push_back(i);
            if (i * i != a)
                answer.push_back(a / i);
        }
    }
    answer.push_back(a);

    sort(answer.begin(), answer.end());

    for (i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);
}