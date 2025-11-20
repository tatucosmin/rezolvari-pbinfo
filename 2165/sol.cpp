#include <bits/stdc++.h>
#include <ostream>
#include <unordered_map>

void bfs(std::vector<int> g[], std::vector<int> &d, int start) {

  std::queue<int> q;
  q.push(start);
  d[start] = 1;

  while (!q.empty()) {
    int nod = q.front();
    q.pop();

    for (auto vec : g[nod]) {
      if (!d[vec]) {
        d[vec] = d[nod] + 1;
        q.push(vec);
      }
    }
  }
}

int main() {
  std::ifstream in{"graf1.in"};
  std::ofstream out{"graf1.out"};

  int n, m, start, stop;
  in >> n >> m >> start >> stop;

  std::vector<int> g[n + 1];

  int a, b;
  while (m--) {
    in >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  std::vector<int> d1(n + 1);
  std::vector<int> d2(n + 1);

  bfs(g, d1, start);
  bfs(g, d2, stop);

  std::vector<int> pos;
  std::unordered_map<int, int> u;

  for (int i = 1; i <= n; i++) {

    if (i == start || i == stop)
        continue;

    if (d1[i] + d2[i] == d1[stop] + 1) {
        pos.push_back(i);
        u[d1[i]]++;
    }

  }

  int s{0};
  std::vector<int> ans;

  ans.push_back(start);
  ans.push_back(stop);

  for (auto p : pos) {
    if (u[d1[p]] == 1) {
        ans.push_back(p);
    }
  }

  out << ans.size() << '\n';


  std::sort(ans.begin(), ans.end());
  for (auto p : ans) {
    out << p << " ";
  }

  return 0;
}
