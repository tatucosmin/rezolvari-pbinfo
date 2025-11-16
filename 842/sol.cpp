#include <bits/stdc++.h>

void rez(std::vector<int>& v, int n, int left, int right) {
  if (n == 1) {
    v[left] = 1;
    return;
  }
  int m = (right + left) / 2;
  v[m] = n;

  rez(v, n-1, left, m - 1);
  rez(v, n - 1, m + 1, right);
}

int main()
{
  int n;
  std::cin >> n;

  int sz = (1 << n) - 1;
  std::vector<int> v(sz);
  rez(v, n, 0, v.size() - 1);

  for (auto e : v)
    std::cout << e << " ";
}
