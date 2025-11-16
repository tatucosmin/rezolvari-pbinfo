#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace sol {
int one(std::vector<int> v) {

  std::unordered_map<int, int> map;

  for (size_t i = 0; i < v.size(); i++) {
    map[v[i]]++;
  }

  int ans{};
  for (size_t i = 0; i < map.size(); i++) {
    ans = std::max(ans, map[i]);
  }

  return ans;
}

int two(std::vector<int> v) {
  int ans{};
  std::unordered_map<int, int> map;
  for (size_t i = 0; i < v.size(); i++) {
    map[v[i]]++;

    int ma{ 0 }, mi{ INT_MAX };
    for (auto e : map) {
      ma = std::max(ma, e.second);
      mi = std::min(mi, e.second);
    }
    ans = std::max(ans, ma - mi);
  }

  // diff secventa - for for

  return ans;
}
} // namespace sol

int main() {
  std::fstream in{"diff.in"};
  std::ofstream out{"diff.out"};

  int C{}, n{};
  in >> C >> n;

  std::vector<int> v(n);

  for (int i = 0; i < n; i++) {
    in >> v[i];
  }

  switch (C) {
  case 1:
    out << sol::one(v);
    break;
  case 2:
    out << sol::two(v);
    break;
  }
}
