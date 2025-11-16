#include <bits/stdc++.h>
#include <fstream>

struct Point {
  int x, y;
};

void border(std::vector<std::vector<int>> &v)
{
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = v[i][v.size() - 1] = -1;
    v[0][i] = v[v.size() - 1][i] = -1;
  }
}

void lee(std::vector<std::vector<int>> &v, Point start) {
  std::vector<int> dx = {0, -1, 0, 1};
  std::vector<int> dy = {1, 0, -1, 0};

  std::queue<Point> q;

  q.push(start);
  v[start.x][start.y] = 1;

  while (!q.empty()) {
    Point p = q.front();
    q.pop();

    for (int i = 0; i <= 3; i++) {
      Point vec{p.x + dx[i], p.y + dy[i]};
      if (v[vec.x][vec.y] == 0) {
        v[vec.x][vec.y] = v[p.x][p.y] + 1;
        q.push(vec);
      }
    }
  }
}

int main() {
  std::ifstream in{"alee.in"};
  std::ofstream out{"alee.out"};

  int n, m;

  in >> n >> m;

  std::vector<std::vector<int>> v(n + 2, std::vector<int>(n + 2));

  for (int i = 0; i < m; i++) {
    int x, y;

    in >> x >> y;
    v[x][y] = -1;
  }

  Point start, end;
  in >> start.x >> start.y >> end.x >> end.y;

  border(v);
  lee(v, start);

  out << v[end.x][end.y];
}
