#include <bits/stdc++.h>
#include <ostream>
#include <vector>

void dfs(std::set<int> g[], std::vector<int> &viz, int curr, std::ostream& out)
{
    viz[curr] = 1;

    out << curr << " ";

    for (auto vec : g[curr]) {
        if (viz[vec]) continue;
        dfs(g, viz, vec, out);
    }
}

int main()
{
    std::ifstream in{"dfs.in"};
    std::ofstream out{"dfs.out"};

    int n, m, x;
    in >> n >> m >> x;

    std::vector<int> viz(n + 1);
    std::set<int> g[n + 1];

    int a, b;
    while(in >> a >> b)
    {
        g[a].insert(b);
        g[b].insert(a);
    }

    dfs(g, viz, x, out);

}
