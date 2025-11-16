#include <bits/stdc++.h>

void dfs(std::vector<int> g[], std::vector<int> &dir, int curr, int d) {
  dir[curr] = d;

  for (auto vec : g[curr]) {
    if (dir[vec])
      continue;
    dfs(g, dir, vec, 3 - d);
  }
}

int main() {

  std::ifstream in{"gears.in"};
  std::ofstream out{"gears.out"};

  int n, x;
  in >> n >> x;

  std::vector<int> g[n + 1];
  // dr = 1, st = 2
  std::vector<int> dir(n + 1);

  int a, b;
  while (in >> a >> b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(g, dir, x, 1);

  for (int i = 1; i <= n; i++) {
    if (dir[i] == 1) {
      out << "D";
    } else {
      out << "S";
    }
  }
}
