#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    int i, num, j;

    cin >> n >> m;

    queue<int> q;

    for (i = 1; i <= n; i++)
    {
        q.push(i);
    }

    cout << "<";
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
            num = q.front();
            q.pop();
            if (j != m - 1)
                q.push(num);
        }
        if (i != n)
            cout << num << ", ";
        else
            cout << num << ">"
                 << "\n";
    }
}