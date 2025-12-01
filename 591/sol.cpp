#include <bits/stdc++.h>
#include <climits>
#include <fstream>
#include <linux/limits.h>

struct Muchie
{
    int x, y, c;
};

int main()
{

    std::ifstream in {"firma.in"};
    std::ofstream out {"firma.out"};

    int n, m;
    in >> n >> m;


    std::vector<Muchie> mu;
    int x, y, c;
    while (m--)
    {
        in >> x >> y >> c;
        mu.push_back(Muchie{x,y,c});
    }

    // a[i][j] = costul muchiei de la i la j
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));

    for (auto m : mu)
    {
        a[m.x][m.y] = m.c;
        a[m.y][m.x] = m.c;
    }

    constexpr int INF = 1e9;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0)
                a[i][j] = INF;

    // a[i][j] = costul minim al drumului de la i la j

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if( a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];


    int min { INT_MAX }, idx{};
    for (int i = 1; i <= n; i++) {
        int sum{0};
        for (int j = 1; j <= n; j++)
            sum += a[i][j] * (i != j);

        if (min > sum)
        {
            min = sum;
            idx = i;
        }
    }

    out << idx;


}
