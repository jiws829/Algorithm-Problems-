#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

int n, m;
struct node
{
    int to, val;
} tmp, top;
vector<node> adj[1001];
vector<node> heap;

int ans[1001];

void swap(node &a, node &b)
{
    tmp = a;
    a = b;
    b = tmp;
    return;
}

void heap_push(int to, int val)
{
    tmp.to = to;
    tmp.val = val;
    heap.push_back(tmp);
    int now = heap.size() - 1;

    while (now > 0)
    {
        if (heap[(now - 1) / 2].val > heap[now].val)
        {
            swap(heap[(now - 1) / 2], heap[now]);
            now = (now - 1) / 2;
        }
        else
            break;
    }
}

node heap_pop()
{
    node a = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.erase(heap.begin() + heap.size() - 1);

    int now = 0;
    while (now < heap.size())
    {
        if (now * 2 + 2 < heap.size())
        {
            if (heap[now].val < heap[now * 2 + 1].val && heap[now].val < heap[now * 2 + 2].val)
                break;
            if (heap[now * 2 + 1].val < heap[now * 2 + 2].val)
            {
                swap(heap[now], heap[now * 2 + 1]);
                now = now * 2 + 1;
            }
            else
            {
                swap(heap[now], heap[now * 2 + 2]);
                now = now * 2 + 2;
            }
        }
        else if (now * 2 + 1 < heap.size())
        {
            if (heap[now].val > heap[now * 2 + 1].val)
            {
                swap(heap[now], heap[now * 2 + 1]);
                now = now * 2 + 1;
            }
            else
                break;
        }
        else
            break;
    }

    return a;
}

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j;
    int a, b, c;
    int st, en;
    int cnt = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        tmp.to = b;
        tmp.val = c;
        adj[a].push_back(tmp);
    }
    scanf("%d %d", &st, &en);

    memset(ans, -1, sizeof(ans));

    heap_push(st, 0);

    while (1)
    {
        //for(i=0;i<heap.size();i++) printf("%d %d\n",heap[i].to, heap[i].val);
        //printf("---------\n");

        while (!heap.empty())
        {
            top = heap_pop();
            if (ans[top.to] == -1)
                break;
        }

        if (ans[top.to] != -1)
            break;

        //printf("%d %d\n",top.to, top.val);
        //printf("-----------\n");

        ans[top.to] = top.val;
        cnt++;

        if (cnt == n)
            break;

        for (i = 0; i < adj[top.to].size(); i++)
        {
            heap_push(adj[top.to][i].to, top.val + adj[top.to][i].val);
        }
    }

    //for(i=1;i<=n;i++) printf("%d ",ans[i]);
    //printf("\n");
    printf("%d\n", ans[en]);
    //printf("!!!%d %d\n",st,en);
}
