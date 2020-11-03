#include <iostream>
#include <vector>
using namespace std;

struct pp
{
    int index;
    int prior;
} tmp;
vector<pp> p;

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int t;
    int n, m;
    int i, j;
    int v[10];
    int flag;
    int answer;

    cin >> t;
    while (t-- > 0)
    {
        for (i = 1; i <= 9; i++)
            v[i] = 0;
        p.clear();
        answer = 0;

        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            cin >> tmp.prior;
            tmp.index = i;
            p.push_back(tmp);
            v[tmp.prior]++;
        }

        while (1)
        {
            flag = 0;
            for (i = p[0].prior + 1; i <= 9; i++)
            {
                if (v[i] > 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                answer++;
                if (p[0].index == m)
                {
                    cout << answer << '\n';
                    break;
                }
                v[p[0].prior]--;
                p.erase(p.begin());
            }
            else
            {
                tmp = p[0];
                p.erase(p.begin());
                p.push_back(tmp);
            }
        }
    }
}