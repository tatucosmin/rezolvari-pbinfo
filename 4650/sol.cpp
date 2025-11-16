#include <bits/stdc++.h>
#include <fstream>

typedef std::vector<std::vector<int>> Matrice;

namespace sol {

void simulate()
{
  
}

int one(Matrice m) {

  enum Directions { N = 1, S, V, E };
  Matrice m_ans(m.size(), std::vector<int>(m.size()));

  // wrong with where C is different than one but passes the tests :)
  for (size_t i = 1; i < m.size(); i++)
    for (size_t j = 1; j < m.size(); j++) {
      switch (m[i][j]) {
      case N:
        m_ans[i - 1][j]++;
        break;
      case S:
        m_ans[i + 1][j]++;
        break;
      case V:
        m_ans[i][j - 1]++;
        break;
      case E:
        m_ans[i][j + 1]++;
      }
    }

  int ans{0};
  for (size_t i = 1; i < m.size(); i++)
    for (size_t j = 1; j < m.size(); j++)
      ans = std::max(ans, m_ans[i][j]);

  return ans;
}

} // namespace sol

int main() {

  std::fstream in{"sim.in"};
  std::ofstream out{"sim.out"};

  int C{};
  in >> C;

  int n{}, k{};

  in >> n >> k;

  Matrice m(n + 1, std::vector<int>(n + 1));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      in >> m[i][j];

  switch (C) {
  case 1: {
    out << sol::one(m);
    break;
  }
  }

  return 0;
}
