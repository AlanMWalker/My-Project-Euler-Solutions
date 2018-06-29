#include <iostream>	
#include <string>
#include <fstream>

using namespace std;

bool IsTriangleNumber(int num);

int TriangleNumberCount = 0;
const string filename("p042_words.txt");
const int CONVERSION = 64;

int main(void)
{
	ifstream wordFile;

	wordFile.open(filename);

	if (wordFile.fail())
	{
		cout << "Failed to open " << filename << endl;
		system("pause");
		return -1;
	}

	string tempString;
	tempString.resize(100);
	int wordSum = 0;
	while (!wordFile.eof()) // while we haven't reached the end of the file
	{
		wordFile.getline(&tempString[0], 100 * sizeof(char), ',');
		wordSum = 0;
		for (int i = 1; i < tempString.size(); ++i)//skip first and last char because they are an opening and close quotation mark
		{
			if (tempString[i] < 'A' || tempString[i] > 'Z')
				break;
			wordSum += (int)(tempString[i]) - CONVERSION;
		}
		if (IsTriangleNumber(wordSum))
		{
			++TriangleNumberCount;
		}
	}
	wordFile.close();

	cout << TriangleNumberCount << endl;
	system("pause");
	return 0;
}

bool IsTriangleNumber(int num)
{
	const static int a = 1;
	const static int b = 1;
	const int c = -(num * 2);

	const int descriminant = b - (4 * a * c);

	if (descriminant < 0)
	{
		return false;
	}

	const float x1 = (-(float)b + sqrtf(descriminant)) / 2.0f;
	const float x2 = (-(float)b - sqrtf(descriminant)) / 2.0f;

	if (x1 < 0 && x2 < 0)
	{
		return false;
	}

	if (fmod(x1, 1) == 0 || fmod(x2, 1) == 0)
	{
		return true;
	}

	return false;
}
