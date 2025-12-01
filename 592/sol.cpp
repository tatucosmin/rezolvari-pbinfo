#include <bits/stdc++.h>
#include <fstream>

struct Muchie {
  int x, y, c;
};

int gaseste(std::vector<int> &t, int x) {
  if (t[x] == x)
    return x;

  return t[x] = gaseste(t, t[x]);
}

void uneste(std::vector<int> &t, int x, int y) {
  x = gaseste(t, x);
  y = gaseste(t, y);

  if (x == y)
    return;

  t[y] = x;
}

int main() {
  std::ifstream in{"kruskal.in"};
  std::ofstream out{"kruskal.out"};

  int n, m;
  in >> n >> m;

  std::vector<int> t(n + 1);

  for (int i = 1; i <= n; i++) {
    t[i] = i;
  }

  std::vector<Muchie> v;
  int x, y, c;
  while (m--) {
    in >> x >> y >> c;
    v.push_back(Muchie{x, y, c});
  }

  std::sort(v.begin(), v.end(), [](Muchie a, Muchie b) { return a.c < b.c; });

  int sum;
  std::vector<Muchie> ans;
  for (auto m : v) {
    if (gaseste(t, m.x) == gaseste(t, m.y))
      continue;

    uneste(t, m.x, m.y);
    ans.push_back(m);
    sum += m.c;
  }

  out << sum << '\n';

  for (auto m : ans)
    out << m.x << " " << m.y << '\n';
}
