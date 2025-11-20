#include <bits/stdc++.h>
#include <queue>

void bfs(std::vector<int> g[], std::vector<int> &d, int start, int &max)
{
    std::queue<int> q;

    q.push(start);
    d[start] = 1;

    while (!q.empty())
    {
        int nod = q.front();
        q.pop();


        for (auto vec : g[nod]) {
            if (!d[vec]) {
                d[vec] = d[nod] + 1;
                max = std::max(max, d[vec]);
                q.push(vec);
            }
        }
    }
}

int main()
{

    int n, m, start;
    std::cin >> n >> m >> start;

    std::vector<int> g[n + 1], d(n + 1);
    int a, b;
    while (m--) {
      std::cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    int max{-1};
    bfs(g, d, start, max);

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == max) {
            std::cout << i << " ";
        }
    }

    return 0;
}
