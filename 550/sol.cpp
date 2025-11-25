#include <bits/stdc++.h>
#include <fstream>

void dfs(std::vector<int> g[], std::vector<int> &lookup, std::vector<int> &viz,
         int curr, int &ans) {


  if (curr == -1)
    return;

  viz[curr] = 1;
  ans += lookup[curr];

  int maxvec{-1}, maxidx{-1};
  for (auto vec : g[curr]) {
    if (maxvec < lookup[vec] && !viz[vec]) {
      maxvec = lookup[vec];
      maxidx = vec;
    }
  }

  dfs(g, lookup, viz, maxidx, ans);
}

int main() {
  std::ifstream in{"mere.in"};
  std::ofstream out{"mere.out"};

  int n;
  in >> n;

  std::vector<int> mere(n + 1);
  for (int i = 1; i <= n; i++)
    in >> mere[i];

  int a, b;
  std::vector<int> g[n + 1], viz(n + 1);
  while (in >> a >> b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans{0};
  dfs(g, mere, viz, 1, ans);

  out << ans;
}
