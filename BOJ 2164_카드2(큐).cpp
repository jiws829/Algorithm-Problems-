#include <stdio.h>
#include <vector>

using namespace std;

vector<int> stack;
vector<char> ans;

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int n;
    int i;
    int a;
    int cnt = 1;

    int flag = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);

        while (a >= cnt)
        {
            stack.push_back(cnt);
            ans.push_back('+');
            cnt++;
        }

        if (a == stack[stack.size() - 1])
        {
            stack.pop_back();
            ans.push_back('-');
        }
        else
        {
            stack.clear();
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        printf("NO\n");
    else
    {
        for (i = 0; i < ans.size(); i++)
            printf("%c\n", ans[i]);
    }
}