#include <bits/stdc++.h>
#include <fstream>
#include <vector>

int gaseste(std::vector<int> &t, int x)
{
    if (t[x] == x)
        return x;

    return t[x] = gaseste(t, t[x]);
}

void uneste(std::vector<int> &t, int x, int y)
{
    x = gaseste(t, x);
    y = gaseste(t, y);

    if (x == y)
        return;

    t[y] = x;
}

struct Muchie {
    int x, y, c;
};

int main()
{
    std::ifstream in {"zapada.in"};
    std::ofstream out {"zapada.out"};

    int n, m;

    in >> n >> m;

    std::vector<Muchie> mu;
    int x, y, c;
    while (m--)
    {
        in >> x >> y >> c;
        mu.push_back(Muchie{x, y, c});
    }

    int ans{0};

    std::vector<int> t(n + 1);

    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
    }

    int k;
    in >> k;
    while (k--)
    {
        in >> x;
        --x;
        ans += mu[x].c;
        uneste(t, mu[x].x, mu[x].y);
    }

    std::sort(mu.begin(), mu.end(), [](Muchie a, Muchie b){
        return a.c < b.c;
    });

    for (auto o : mu)
    {
        if (gaseste(t, o.x) == gaseste(t, o.y))
            continue;

        ans += o.c;
        uneste(t, o.x, o.y);
    }

    out << ans;
}
