#include <bits/stdc++.h>
#include <fstream>
#include <ostream>

void dfs(std::vector<int> g[], std::vector<int> &viz, int curr, int nrc,
         std::ostream &out) {

  if (viz[curr])
    return;

  viz[curr] = nrc;

  for (auto vec : g[curr]) {
    dfs(g, viz, vec, nrc, out);
  }
}

int main() {

  std::ifstream in{"componenteconexe.in"};
  std::ofstream out{"componentconexe.out"};
  int n;
  in >> n;

  std::vector<int> g[n + 1];
  std::vector<int> viz(n + 1);

  int a, b;
  while (in >> a >> b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }


  int nrc = 0;
  for (int i = 1; i <= n; i++)
  {
      if (viz[i] == 0)
      {
          nrc++;
          dfs(g, viz, i, nrc, out);
      }
  }

  out << nrc << '\n';

  for (int k = 1; k <= nrc; k++)
  {
      for (int i = 1; i <= n; i++) {
          if (viz[i] == k) {
              out << i << " ";
          }
      }
      out << "\n";
  }

}
