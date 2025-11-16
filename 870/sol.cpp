#include <bits/stdc++.h>

int main() {
  std::stack<int> A;
  std::stack<int> B;

  int n;

  std::cin >> n;
  int t;
  for (int i = 0; i < n; i++) {
    std::cin >> t;
    A.push(t);
  }

  std::string ans;
  int curr{1}, ops{0};

  while (curr <= n) {
    if (!A.empty() && curr == A.top()) {
      ans.append("A C\n");
      A.pop();
      curr++;
      ops++;
      continue;
    }

    if (!B.empty() && curr == B.top()) {
      ans.append("B C\n");
      B.pop();
      curr++;
      ops++;
      continue;
    }

    if (!A.empty()) {
      ans.append("A B\n");
      B.push(A.top());
      A.pop();
      ops++;
      continue;
    }

    std::cout << 0;
    return 0;
  }

  std::cout << ops << '\n' << ans;
}
