#include <bits/stdc++.h>

int main()
{

    std::ifstream in{ "listavecini.in"};
    std::ofstream out{ "listavecini.out"};

    int n;
    in >> n;

    std::set<int> g[n + 1];

    int x, y;
    while(in >> x >> y)
    {
        g[x].insert(y);
        g[y].insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        out << g[i].size() << " ";
        for (auto e : g[i])
            out << e << " ";

        out << '\n';
    }

    return 0;
}
