#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct pp
{
    int st, en;
} tmp;
vector<pp> p;
int n;

int compare(pp a, pp b)
{
    if (a.en == b.en)
        return a.st < b.st;
    else
        return a.en < b.en;
}

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &tmp.st, &tmp.en);
        p.push_back(tmp);
    }

    sort(p.begin(), p.end(), compare);
    //for(i=0;i<n;i++) printf("%d %d\n",p[i].st,p[i].en);
    int answer = 0;
    int num = 0;
    for (i = 0; i < n; i++)
    {
        if (p[i].st >= num)
        {
            num = p[i].en;
            answer++;
        }
    }
    printf("%d\n", answer);
}