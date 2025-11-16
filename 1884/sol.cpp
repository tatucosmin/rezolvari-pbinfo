#include <bits/stdc++.h>
#include <vector>

int main() {
  std::stack<int> s;

  int n;
  std::cin >> n;

  std::vector<int> v(n + 1), ans(n);
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i];
  }

  for (int i = v.size() - 1; i >= 1; i--) {
    while (!s.empty() && v[i] >= s.top()) {
      s.pop();
    }

    if (s.empty())
      ans[i-1] = -1;
    else
      ans[i-1] = s.top();

    s.push(v[i]);
  }

  for (auto e : ans) {
    std::cout << e << " ";
  }

  return 0;
}
