#include <bits/stdc++.h>
#include <fstream>

void dfs(std::set<int> g[], std::vector<int>& v, int i, int ccnr) {

  if (v[i] != 0)
    return;

  v[i] = ccnr;

  for (auto vec : g[i]) {
    dfs(g, v, vec, ccnr);
  }
}

int main()
{
    std::ifstream in { "componenteconexe3.in" };
    std::ofstream out { "componenteconexe3.out" };

    int n;

    in >> n;

    std::set<int> g[n + 1];

    int a, b;
    while (in >> a >> b)
    {
        g[a].insert(b);
        g[b].insert(a);
    }

    std::vector<int> v(n + 1);

    int ccnr{0};
    for (int i = 1; i <= n; i++) {
      if (v[i] == 0) {
        ++ccnr;
        dfs(g, v, i, ccnr);
      }
    }

    int ma{-1}, aidx{0}, idx{ 1 }, s{};
    for (int i = 1; i <= ccnr; i++)
    {
        s = 0;
        for (int j = 1; j <= v.size(); j++)
        {
            if (s == 0) {
                idx = j;
            }

            if (v[j] == i)
                s++;
        }

        if (s > ma) {
            ma = s;
            aidx = idx;
        }
    }

    out << aidx << " " << ma;

}
