#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> p;
int t[51];

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j;
    int num, tmp;
    int answer = 0;

    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    for (i = 1; i <= n; i++)
        p.push_back(i);

    for (j = 0; j < m; j++)
    {
        num = t[j];

        for (i = 0; i < p.size(); i++)
        {
            if (p[i] == num)
                break;
        }

        if (i == 0)
        {
            p.erase(p.begin());
            continue;
        }

        if (p.size() - i < i)
        {
            while (1)
            {
                if (p[0] == num)
                    break;
                tmp = p[p.size() - 1];
                p.erase(p.begin() + p.size() - 1);
                p.insert(p.begin(), tmp);
                answer++;
            }
            p.erase(p.begin());
        }
        else
        {
            while (1)
            {
                if (p[0] == num)
                    break;
                tmp = p[0];
                p.erase(p.begin());
                p.push_back(tmp);
                answer++;
            }
            p.erase(p.begin());
        }
    }

    cout << answer;
}
