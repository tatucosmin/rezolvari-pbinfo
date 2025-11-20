#include <bits/stdc++.h>
#include <istream>

void clear_vector(std::vector<int> &v) {
  for (size_t i = 1; i <= v.size() - 1; i++)
    v[i] = 0;
}

void dfs(std::vector<int> g[], std::vector<int> &v, int curr, int excl, int &ccnr) {

  ccnr++;
  v[curr] = ccnr;

  for (auto vec : g[curr]) {
    if (!v[vec] && vec != excl)
        dfs(g, v, vec, excl, ccnr);
  }
}

int main() {
  std::ifstream in{"retea.in"};
  std::ofstream out{"retea.out"};

  int n, m;
  in >> n >> m;

  std::vector<int> g[n + 1], v(n + 1);

  int a, b;
  while (m--) {
    in >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ccnr{0};
  for (int i = 1; i <= n; i++) {

    ccnr = 0;
    clear_vector(v);
    if (i == 1) {
      dfs(g, v, 2, 1, ccnr);
    } else {
      dfs(g, v, 1, i, ccnr);
    }

    int ans = ccnr == n-1 ? 0 : 1;
    out << ans << " ";

  }
}
