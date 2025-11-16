#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

struct Skyline {
  int h, l;
};

int main() {
  std::fstream in{"skyline.in"};
  std::ofstream out{"skyline.out"};

  int n;
  in >> n;

  std::vector<Skyline> v;
  for (int i = 0; i < n; i++) {
    Skyline s;
    in >> s.h >> s.l;
    v.push_back(s);
  }

  std::stack<int> s;
  std::vector<int> dr(n);
  for (int i = v.size() - 1; i >= 0; i--) {
    while (!s.empty() && v[i].h <= v[s.top()].h) {
      s.pop();
    }

    if (s.empty()) {
      dr[i] = -1;
    } else {
      dr[i] = s.top();
    }

    s.push(i);
  }

  std::vector<int> st(n);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && v[i].h <= v[s.top()].h) {
      s.pop();
    }

    if (s.empty()) {
      st[i] = -1;
    } else {
      st[i] = s.top();
    }

    s.push(i);
  }

  std::vector<int> sum(n);
  sum[0] = v[0].l;
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + v[i].l;
  }

  long long ans{};
  for (int i = 0; i < n; i++) {
    int a, b;

    if (st[i] == -1) {
      a = 0;
    } else {
      a = sum[st[i]];
    }

    if (dr[i] == -1) {
      b = sum[n - 1];
    } else {
      b = sum[dr[i] - 1];
    }

    long long s1 = b - a;

    ans = std::max(ans, v[i].h * s1);
  }

  out << ans;
  return 0;
}
