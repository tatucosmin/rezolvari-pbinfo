#include <bits/stdc++.h>
#include <vector>

void rec(std::vector<std::vector<int>>& m, int l1, int l2, int c1, int c2, int pas)
{
    if (!pas)
        return;

    int midl = (l1 + l2) / 2;
    int midc = (c1 + c2) / 2;

    m[midl][midc] = pas;

    rec(m, l1, midl - 1, c1, midc - 1, pas - 1);
    rec(m, l1, midl - 1, midc + 1, c2, pas - 1);
    rec(m, midl + 1, l2, c1, midc - 1, pas - 1);
    rec(m, midl + 1, l2, midc + 1, c2, pas - 1);
}

int main()
{

    int n;
    std::cin >> n;

    int p = (1 << n) - 1;
    std::vector<std::vector<int>> m(p, std::vector<int>(p));

    rec(m, 0, m.size() - 1, 0, m.size() - 1, n);


    for (auto e : m) {
        for (auto e1 : e) {
            std::cout << e1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
