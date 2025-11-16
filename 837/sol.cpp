
#include <bits/stdc++.h>
#include <fstream>


void fill(std::vector<std::vector<int>>& v, int i, int j)
{

  std::vector<int> dx = {0, -1, 0, 1};
  std::vector<int> dy = {1, 0, -1 ,0};
  
  if (v[i][j] == 0)
    return;

  v[i][j] = 0;
  for(int k = 0; k < 4; k++)
    fill(v, i+dx[k], j+dy[k]);
  
}

int main()
{
  std::ifstream in {"fill.in"};
  std::ofstream out {"fill.out"};

  int n, m;
  in >> n >> m;

  std::vector<std::vector<int>> v(n+2, std::vector<int>(m+2));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      in >> v[i][j];
  
  int ans{};
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == 1)
      {
        ans++;
        fill(v, i, j);
      }    
    }

  out << ans;
}


