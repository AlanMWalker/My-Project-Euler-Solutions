#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cout << "Hello world" << endl;
	vector<double> values;
	for (int power = 2; power <= 100; ++power)
	{
		for (int number = 2; number <= 100; ++number)
		{
			values.push_back(pow((double)number, (double)power));
		}
	}

	std::sort(values.begin(), values.end());
	auto it = std::unique(values.begin(), values.end());
	values.erase(it, values.end());
	cout << values.size() << endl;
	system("pause");
	return 0;
}