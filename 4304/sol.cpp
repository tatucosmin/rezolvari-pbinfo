#include <bits/stdc++.h>

void bfs(std::vector<int> g[], std::vector<int> &viz, std::vector<int> &grad) {
  std::queue<int> q;

  for (int i = 1; i <= viz.size() - 1; i++) {
    if (grad[i] < 2) {
      q.push(i);
      viz[i] = 1;
    }
  }

  while (!q.empty()) {
    int nod = q.front();
    q.pop();

    grad[nod] = 0;

    for (auto vec : g[nod]) {
      grad[vec]--;
      if (grad[vec] < 2 && viz[vec] == 0) {
        viz[vec] = 1;
        q.push(vec);
      }
    }
  }
}

int main() {
  std::ifstream in{"ff.in"};
  std::ofstream out{"ff.out"};

  int n, m;
  in >> n >> m;

  std::vector<int> g[n + 1], viz(n + 1), grad(n + 1);
  int a, b;
  while (m--) {
    in >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
      grad[i] = g[i].size();
  }

  bfs(g, viz, grad);

  int cnt{0};
  for (auto e : grad)
  {
      if (e <= 0){
          cnt++;
      }
  }

  out << n - cnt + 1;
  return 0;
}
