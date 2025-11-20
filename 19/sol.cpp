#include <bits/stdc++.h>
#include <queue>
#include <vector>

int main() {
  std::ifstream in{"BFS.in"};
  std::ofstream out{"BFS.out"};

  int n, m, start;
  in >> n >> m >> start;

  std::set<int> g[n + 1];

  int a, b;
  while (m--) {
    in >> a >> b;
    g[a].insert(b);
    g[b].insert(a);
  }

  std::queue<int> q;
  std::vector<int> viz(n + 1);

  q.push(start);
  viz[start] = 1;

  while (!q.empty()) {
    int nod = q.front();

    q.pop();
    out << nod << " ";

    for (auto vec : g[nod]) {
      if (viz[vec] == 0) {
          q.push(vec);
          viz[vec] = 1;
      }
    }
  }
}
