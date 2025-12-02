#include <bits/stdc++.h>

int gaseste(std::vector<int> &t, int x)
{
    if (t[x] == x)
        return x;

    return gaseste(t, t[x]);
}



int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> g[n + 1];

    while (m--)
    {
        int a, b;
        std::cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }


}
