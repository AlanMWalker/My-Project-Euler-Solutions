#include <vector>	
#include <iostream>

using namespace std;

std::vector<int> individual_digits = { 1 };

int main(void)
{
	//Sum the digits of 2^1000
	for (int exp = 1; exp <= 1000; ++exp)
	{
		for (auto& digit : individual_digits)
		{
			digit *= 2; //hard-coded 2 as exponent
		}
		int size = individual_digits.size();
		int carryOver = 0;
		for (int i = 0; i < size; ++i)
		{
			if (individual_digits[i] >=10)
			{
				if (i + 1 >= individual_digits.size())//only push_back if it's required
				{
					individual_digits.push_back(1);
					++size;
				}
				else
				{
					individual_digits[i+1] += 1;
				}

				individual_digits[i] = individual_digits[i] - 10; //negates a modulo
			}
		}
	}
	int sum = 0;
	for (auto& digit : individual_digits)
	{
		sum += digit;
	}
	cout << "Sum of 2^1000 is " << sum << endl;
	for (auto it = individual_digits.rbegin(); it != individual_digits.rend(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	system("pause");
	return 0;
}