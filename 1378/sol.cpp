#include <algorithm>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int gaseste(std::vector<int> &t, int x)
{
    if (t[x] == x)
        return x;

    return t[x] = gaseste(t, t[x]);
}

void uneste(std::vector<int> &t, int x, int y)
{
    x = gaseste(t, x);
    y = gaseste(t, y);

    if (x == y)
        return;

    t[y] = x;
}


int main()
{
    std::ifstream in {"flori2.in"};
    std::ofstream out {"flori2.out"};

    constexpr int POSSIBLE_MAX_FLOWER = 100;

    int n, m;

    in >> n >> m;

    int max_flower{};

    std::vector<int> g[POSSIBLE_MAX_FLOWER + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a;
            in >> a;
            max_flower = std::max(max_flower, a);
            g[a].push_back(i);
        }
    }

    std::vector<int> t(n + 1);

    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
    }

    for(int i = 1; i <= max_flower; i++)
    {
        if (g[i].size() > 1)
            for (int j = 1; j < g[i].size(); j++)
            {
                uneste(t, g[i][0], g[i][j]);
            }
    }

    for (int i = 1; i <= n; i++)
        t[i] = gaseste(t, i);

    std::map<int, std::vector<int>> map;

    for (int i = 1; i <= n; i++)
    {
        map[t[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto e : map[i]) out << e << " ";
        if (!map[i].empty())
            out << '\n';
    }
}
