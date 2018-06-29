#include <iostream>
#include <string>

using namespace std;

#define ZERO '0'

string irrationalNumberString = "0.";

int main(void)
{

	for (int i = 1; i <= 1000000; ++i)
	{
		irrationalNumberString.append(std::to_string(i));
	}

	int d1, d10, d100, d1000, d10000, d100000, d1000000;
	d1 = irrationalNumberString[2] - ZERO;
	d10 = irrationalNumberString[11] - ZERO;
	d100 = irrationalNumberString[101] - ZERO;
	d1000 = irrationalNumberString[1001] - ZERO;
	d10000 = irrationalNumberString[10001] - ZERO;
	d100000 = irrationalNumberString[100001] - ZERO;
	d1000000 = irrationalNumberString[1000001] - ZERO;


	const int value = d1 * d10 * d100 * d1000 * d10000 * d100000 *  d1000000;
	
	cout << value << endl;
	system("pause");
	return 0;
}