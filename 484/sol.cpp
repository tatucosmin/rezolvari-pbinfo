#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>

void bfs(std::vector<int> g[], std::vector<int> &t, int start, int stop, std::ostream &out) {

  std::queue<int> q;
  q.push(start);
  t[start] = -1;

  while (!q.empty()) {
    int nod = q.front();
    q.pop();

    for (auto vec : g[nod]) {
      if (!t[vec]) {
        t[vec] = nod;
        q.push(vec);
      }
    }
  }

  int i = stop;

  std::vector<int> ans;
  while (i != start)
  {
      ans.push_back(i);
      i = t[i];
  }

  ans.push_back(start);

  out << ans.size() << '\n';

  std::reverse(ans.begin(), ans.end());

  for (auto e : ans)
  {
      out << e << " ";
  }
}

int main() {
  std::ifstream in{"lantminim.in"};
  std::ofstream out{"lantminim.out"};

  int n, start, stop;
  in >> n >> start >> stop;

  std::vector<int> g[n + 1];

  std::vector<int> d(n + 1);
  std::vector<int> t(n + 1);

  int a, b;
  while (in >> a >> b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bfs(g, t, start, stop, out);

  return 0;
}
