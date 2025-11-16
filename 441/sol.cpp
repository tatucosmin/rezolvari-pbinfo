#include <bits/stdc++.h>
#include <ostream>


void dfs(std::set<int> g[], int curr, int target, int cnt, std::ostream &out)
{

    for(auto vec : g[curr])
    {
        if (curr != target) {
            cnt++;
            g[vec].insert(target);
            out << target << vec;
        }

        dfs(g, vec, target, cnt, out);
    }
}

int main() {

  std::ifstream in{"componenteconexe1.in"};
  std::ofstream out{"componenteconexe1.out"};

  int n;
  in >> n;

  std::set<int> g[n + 1];

  int a, b;
  while (in >> a >> b) {
      g[a].insert(b);
      g[b].insert(a);
  }

  int cnt = 0;
  dfs(g, 1, 1, cnt, out);


  return 0;
}
