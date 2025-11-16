#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <fstream>

namespace utilities
{
	void write_vec_to_file(std::vector<int> v, std::ofstream& o)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			o << v[i] << " ";
		}
	}


	std::vector<int> precompute_two(std::vector<int> v)
	{
		for (size_t i = 1; i < v.size(); i++)
		{
			v[i] += v[i - 1];
		}

		return v;
	}
}

namespace ans
{
	int solve_one(std::vector<int> v, int poz)
	{
		int to_cmp = v[poz];
		int curr{ 0 };

		for (size_t i = 1; i < v.size(); i++)
		{
			if (v[i] < to_cmp)
				curr = i;
			else
				break;
		}

		return curr;
	}

	void solve_two(std::vector<int> v, std::ofstream& o, int n)
	{
		v = utilities::precompute_two(v);
		int sum{ 0 };
		std::vector<int> ans;
		for (int i = 1; i <= n; i++)
		{
			sum += i;
			if (v[i] == sum) {
				ans.push_back(i);
			}
		}

		utilities::write_vec_to_file(ans, o);
	}

	// https://www.pbinfo.ro/probleme/4829/cartonase4
	// nu convine la limita de timp dar nu ma pot gandi la ceva mai eficient
	void solve_three(std::vector<int> v, std::ofstream& o, int n)
	{
		int i{ 1 };

		while (i <= n)
		{
			int prev_within{ 0 };
			for (int j = 1; j <= i; j++)
				if (v[j] <= i)
					prev_within++;

			if (prev_within == i - 1)
				o << i << " ";

			i++;
		}
	}
}



int main()
{

	std::fstream in{ "cartonase.in" };
	std::ofstream out{ "cartonase.out" };

	int C;
	in >> C;

	int n{};
	in >> n;

	std::vector<int> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		in >> v[i];
	}

	switch (C) {
	case 1:
		int poz;
		in >> poz;

		out << ans::solve_one(v, poz);
		out.close();
		break;
	case 2:
		ans::solve_two(v, out, n);
		break;
	case 3:
		ans::solve_three(v, out, n);
		break;
	}

	return 0;
}
