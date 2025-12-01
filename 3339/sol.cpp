#include <bits/stdc++.h>

int gaseste(std::vector<int> &t, int x) {
  if (t[x] == x)
    return x;

  return t[x] = gaseste(t, t[x]);
}

void uneste(std::vector<int> &t, std::vector<int> &sz, int x, int y) {
  x = gaseste(t, x);
  y = gaseste(t, y);

  if (x == y)
    return;

  if (sz[x] < sz[y]) {
    std::swap(x, y);
  }

  t[y] = x;
  sz[x] += sz[y];
}

int query(std::vector<int> &sz) {
  int max{-1};
  for (auto e : sz)
    max = std::max(max, e);

  return max;
}

void query(std::vector<int> &t, int x, int y) {
  x = gaseste(t, x);
  y = gaseste(t, y);

  if (x == y)
    std::cout << "DA\n";
  else
    std::cout << "NU\n";
}

int main() {
  int n, m;

  std::cin >> n >> m;

  std::vector<int> v(n), sz(n, 1);

  for (int i = 1; i <= n; i++) {
    v[i - 1] = i - 1;
  }

  int t, a, b;
  for (int i = 1; i <= m; i++) {
    std::cin >> t;
    if (t != 3) {
        std::cin >> a >> b;
    }
    --a;
    --b;
    if (t == 1)
      uneste(v, sz, a, b);
    else if (t == 2)
      query(v, a, b);
    else
      std::cout << query(sz) << '\n';
  }
}
