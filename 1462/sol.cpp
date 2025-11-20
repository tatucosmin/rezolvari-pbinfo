#include <algorithm>
#include <bits/stdc++.h>

void dfs(std::vector<int> g[], std::vector<int> &cc, int ccnr, int curr) {
  if (cc[curr] != 0)
    return;

  cc[curr] = ccnr;

  for (int vec : g[curr]) {
      if (cc[vec] == 0)
          dfs(g, cc, ccnr, vec);
  }
}

int main() {
  std::ifstream in{"gasti.in"};
  std::ofstream out{"gasti.out"};

  int n, m;

  in >> n >> m;

  std::vector<int> g[n + 1];
  int a{}, b{};
  while (m--) {
    in >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  std::vector<int> cc(n + 1);

  int ccnr{0};
  for (int i = 1; i <= n; i++) {
    if (cc[i] == 0)
      dfs(g, cc, ++ccnr, i);
  }

  out << ccnr << " ";

  std::vector<int> dedupe(ccnr + 1);
  for (auto e : cc) {
      dedupe[e]++;
  }

  std::sort(dedupe.begin() + 1, dedupe.end(), [](int a, int b){
      return a > b;
  });

  if (dedupe[1] != dedupe[2]) {
      if (dedupe[2] == dedupe[3]) {
          int p;
          for (p = 2; p <= ccnr && dedupe[2] == dedupe[p]; p++);
          p--;

          // 4 3 3 3

          out << dedupe[1] * dedupe[2] * (p - 1) % 666013;
          return 0;
      }
      out << dedupe[1] * dedupe[2] % 666013;
      return 0;
  }

  int p;
  for (p = 1; p <= ccnr && dedupe[1] == dedupe[p]; p++);
  p--;

  out << ((p * (p - 1)) / 2 * dedupe[1] * dedupe[1]) % 666013;

  return 0;
}
