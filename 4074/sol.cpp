#include <bits/stdc++.h>

void bfs(std::vector<int> g[], std::vector<int> &d, int start) {
  std::queue<int> q;
  q.push(start);
  d[start] = 1;

  while (!q.empty()) {
    int nod = q.front();

    q.pop();
    for (auto vec : g[nod]) {
      if (!d[vec]) {
        q.push(vec);
        d[vec] = d[nod] + 1;
      }
    }
  }
}

int main() {
  std::ifstream in{"distante.in"};
  std::ofstream out{"distante.out"};

  int n, m, nod1, nod2;
  in >> n >> m >> nod1 >> nod2;

  std::vector<int> g[n + 1];

  int a, b;
  while (m--) {
    in >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  std::vector<int> d1(n + 1);
  std::vector<int> d2(n + 1);

  bfs(g, d1, nod1);
  bfs(g, d2, nod2);

  for(int i = 1; i <= n; i++)
  {
      if(d1[i] == d2[i])
          out << i << " ";
  }

  return 0;
}
