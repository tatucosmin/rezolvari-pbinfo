#include <bits/stdc++.h>
#include <fstream>
#include <vector>

void dfs(std::vector<int> g[], std::vector<int> &v, int curr, int ccnr) {
    if (v[curr] != 0)
        return;

    v[curr] = ccnr;

    for (auto vec : g[curr])
        dfs(g, v, vec, ccnr);
}

int main()
{
    std::ifstream in { "componenteconexe5.in" };
    std::ofstream out { "componenteconexe5.out" };

    int n, m;
    in >> n >> m;

    std::vector<int> g[n + 1], v(n + 1);
    int a, b;

    while (m--)
    {
        in >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int q;
    in >> q;

    std::vector<int> nodes;
    while (q--)
    {
        in >> a;
        nodes.push_back(a);
    }

    int ccnr{ 0 };
    for (int i = 1; i < n; i++)
        dfs(g, v, i, ++ccnr);

    std::map<int, int> freq;
    for (auto e : v)
    {
        freq[e]++;
    }

    for (auto node : nodes)
    {
        out << freq[v[node]] << '\n';
    }
}
