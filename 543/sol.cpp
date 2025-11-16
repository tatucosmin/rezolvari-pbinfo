#include <bits/stdc++.h>
#include <fstream>
#include <ostream>

void dfs(std::vector<int> g[], std::vector<int> &viz, int curr, int cul,
         std::ostream &out) {
  viz[curr] = cul;

  for (auto vec : g[curr]) {
    if (viz[vec] == cul) {
      out << "NU";
      exit(0);
    }

    if (viz[vec])
      continue;

    dfs(g, viz, vec, 3 - cul, out);
  }
}

int main() {

  std::ifstream in{"bipartit2.in"};
  std::ofstream out{"bipartit2.out"};
  int n, m;
  in >> n >> m;

  std::vector<int> g[n + 1];
  std::vector<int> viz(n + 1);

  while (m--) {
    int a, b;
    in >> a >> b;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(g, viz, 1, 1, out);

  out << "DA" << '\n';

  for (int k = 1; k <= 2; k++) {
    for (int i = 1; i <= n; i++) {
      if (viz[i] == k) {
        out << i << " ";
      }
    }

    out << '\n';
  }
}
