#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int n, i, num;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        p.insert(p.begin() + p.size() - num, i + 1);
    }

    for (i = 0; i < n; i++)
        cout << p[i] << " ";
}