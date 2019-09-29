/**
 * Alejandro Hahn
 * 
 * Proyecto A
 **/

#include <iostream>
#include <vector>

using namespace std;

float average(float x, float y)
{
	return (x + y) / 2;
}

float median(vector<float> data, int a, int b, int c, int d)
{
	if (b == a)
	{
		return average(data[a], data[c]);
	}
	if (b - a == 1)
	{
		int mid1 = (b + a) / 2;
		int mid2 = (d + c) / 2;
		if (data[mid1 + 1] > data[mid2] && data[mid1] < data[mid2 + 1])
		{
			swap(data[mid1 + 1], data[mid2]);
		}
		else if (data[mid1 + 1] < data[mid2] && data[mid1] > data[mid2 + 1])
		{
			swap(data[mid1 + 1], data[mid2]);
		}
		if (data[mid1] > data[mid1 + 1])
		{
			swap(data[mid1], data[mid1 + 1]);
		}
		if (data[mid2] > data[mid2 + 1])
		{
			swap(data[mid2], data[mid2 + 1]);
		}
		float med1 = average(data[mid1], data[mid1 + 1]);
		float med2 = average(data[mid2], data[mid2 + 1]);
		if (med1 > med2)
		{
			return median(data, a, mid1, mid2 + 1, d);
		}
		else
		{
			return median(data, mid1 + 1, b, c, mid2);
		}
	}
	else if ((b - a) % 2 != 0)
	{
		int mid1 = (b + a) / 2;
		int mid2 = (d + c) / 2;
		float med1 = average(data[mid1], data[mid1 + 1]);
		float med2 = average(data[mid2], data[mid2 + 1]);
		if (med1 > med2)
		{
			return median(data, a, mid1, mid2 + 1, d);
		}
		else
		{
			return median(data, mid1 + 1, b, c, mid2);
		}
	}
	else
	{
		int mid1 = (b + a) / 2;
		int mid2 = (d + c) / 2;
		if (data[mid1] > data[mid2])
		{
			return median(data, a, mid1, mid2, d);
		}
		else
		{
			return median(data, mid1, b, c, mid2);
		}
	}

}

float median(vector<float> data)
{
	int size = data.size();
	return median(data, 0, (size / 2) - 1, size / 2, size - 1);
}

int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int size;
		vector<float> elements;
		cin >> size;
		for (int j = 0; j < size * 2; j++)
		{
			float x;
			cin >> x;
			elements.push_back(x);
		}
		cout << "Median case " << i + 1 << ": ";
		printf("%.2f", median(elements));
		cout << endl;
	}

}