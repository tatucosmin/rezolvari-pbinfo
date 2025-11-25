#include <bits/stdc++.h>
#include <cstdlib>

void bfs(std::vector<int> g[], std::vector<int> &viz, int curr, int end,
         int to_find, bool &was_found, const int max_chain_size, int &chain_size) {

  std::queue<int> q;

  q.push(curr);
  viz[curr] = ++chain_size;
  if (chain_size == max_chain_size)
  {
      std::cout << "you fucked up :(";
      std::exit(1); // something wrong on my side considering at least 1 exists

  }

  while (!q.empty()) {
    int nod = q.front();
    if (nod == to_find) was_found = true;
    if (nod == end && was_found) return;

    q.pop();
    viz[nod] = 1;
    for (auto vec : g[nod]) {
        if (!viz[vec])
        {
            q.push(vec);
        }
    }
  }
}

int main() {
  std::ifstream in{"lant1.in"};
  std::ofstream out{"lant1.out"};

  int n, p, q, r;
  in >> n >> p >> q >> r;

  const int max_chain_size = 2 * n;

  std::set<int> g[n + 1];

  int a, b;
  while (in >> a >> b) {
    g[a].insert(b);
    g[b].insert(a);
  }
}
