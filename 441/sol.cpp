#include <bits/stdc++.h>
#include <ostream>

void dfs(std::set<int> g[], std::vector<int>& v, int i, int ccnr) {

  if (v[i] != 0)
    return;

  v[i] = ccnr;

  for (auto vec : g[i]) {
    dfs(g, v, vec, ccnr);
  }
}

int main() {

  std::ifstream in{"componenteconexe1.in"};
  std::ofstream out{"componenteconexe1.out"};

  int n;
  in >> n;

  std::set<int> g[n + 1];

  int a{}, b{}, m{};
  while (in >> a >> b) {
    m++;
    g[a].insert(b);
    g[b].insert(a);
  }



  std::vector<int> v(n + 1);

  int ccnr{0};
  for (int i = 1; i <= n; i++) {
    if (v[i] == 0) {
      ++ccnr;
      dfs(g, v, i, ccnr);
    }
  }

  // for (auto e : v) {
  //   std::cout << e;
  // }

  out << ccnr - 1 << '\n';

  for (int i = 2; i <= ccnr; i++)
  {
      out << 1 << " " << std::distance(v.begin(), std::find(v.begin(), v.end(), i)) << '\n';
  }

  return 0;
}
