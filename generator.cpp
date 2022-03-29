#include "Generator.h"

int Factorial(int n)
{
	int f = 1;
	for (int b = 2; b <= n; b++)
	{
		f *= b;
	}
	return f;

}

template <class T>
void Print(T someList) {
	for (auto& x : someList) cout << " " << x;
	cout << endl;
}

int Generator::GetCount() {
	count = res.size();
	cout << "Count of combinations: " << count << endl;
	return count;
}

void Generator::GenerateAll() {
	res.resize(0);
	int q = m;
	int z = 2;
	while (q != 1)
	{
		if (q % z == 0)
		{
			x.push_back(z);
			q = q / z;
		}
		else
			z++;
	}
	res.push_back(x);
	Print(x);
	while (x.size() != 1) {
		int s = x.size();
		int Z = x[s - 2] * x[s - 1];
		int last = x[s - 1];
		int maxr = x[s - 1];
		int o = -1;
		for (int r = x[s - 2] + 1; r < maxr; r++) {
			if (Z % r == 0 && r < last)
			{
				o = r;
				break;
			}
		}
		if (o == -1) {
			x.resize(s - 1);
			x[s - 2] = Z;
		} else {
			int M = Z;
			x.resize(s - 2);
			while (M != 1)
			{
				if (M % o == 0 && ((o <= M / o) || (M / o == 1)))
				{
					x.push_back(o);
					M = M / o;
				}
				else
					o++;
			}
		}
		res.push_back(x);
		Print(x);
	}
	x.clear();
}

bool Generator::Recursive(int n, int i, vector<int> mas) {
	vector<int> tmp;
	if (n == 1) {
		Print(mas);
		res.push_back(mas);
	}
	tmp = mas;
	tmp.push_back(i);
	return (n % i == 0 && Recursive(n / i, i, tmp) || i < n && Recursive(n,  i + 1, mas));
}
void Generator::GenerateRec() {
	res.resize(0);
	Recursive(m, 2, x);
}

vector<int>& Generator::GetResult(int index) {
    return res[index];
}