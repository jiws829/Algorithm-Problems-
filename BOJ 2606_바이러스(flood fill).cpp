#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[101];
int check[101];

void dfs(int v)
{
    int i;
    for (i = 0; i < adj[v].size(); i++)
    {
        if (check[adj[v][i]] == 0)
        {
            check[adj[v][i]] = 1;
            dfs(adj[v][i]);
        }
    }
}

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, a, b;

    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    check[1] = 1;
    dfs(1);

    int answer = 0;
    for (i = 2; i <= n; i++)
    {
        if (check[i])
            answer++;
    }
    cout << answer;
}