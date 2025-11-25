#include <bits/stdc++.h>

void uneste(std::vector<int> &v, int a, int b) {
  for (int i = 0; i < v.size(); i++)
    if (v[i] == b)
      v[i] = a;
}

void query(std::vector<int> &v, int a, int b) {
    if (v[a] == v[b])
        std::cout << "DA\n";
    else
        std::cout << "NU\n";
}

int main() {
  int n, m;

  std::cin >> n >> m;

  std::vector<int> v(n);

  for (int i = 1; i <= n; i++) {
    v[i - 1] = i;
  }

  int t, a, b;
  for (int i = 1; i <= m; i++) {
    std::cin >> t >> a >> b;
    if (t == 1)
      uneste(v, v[a-1], v[b-1]);
    else
      query(v, a-1, b-1);
  }
}
