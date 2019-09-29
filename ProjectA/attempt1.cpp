#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Alejandro Hahn
 * 
 * Proyecto A
 **/

using namespace std;

float AbsoluteMedian(vector<float> x, int lo, int hi)
{
    int size = hi - lo + 1;
    if (size % 2 == 0)
    {
        float m = x[lo + (size / 2)];
        float n = x[lo + (size - 1) / 2];
        return (m + n) / 2;
    }
    else
    {
        return x[lo + (size - 1) / 2];
    }
}

float MedianRecursive(vector<float> elems, int lo_a, int hi_a, int lo_b, int hi_b)
{

    if (hi_a - lo_a == 1 && hi_b - lo_b == 1)
    {
        float x = max(elems[lo_a], elems[lo_b]);
        float y = min(elems[hi_a], elems[hi_b]);
        return (x + y) / 2;
    }

    if (hi_a - lo_a == 0 && hi_b - lo_b == 0)
    {
        return (elems[lo_a], elems[hi_b]);
    }

    if (hi_a - lo_a == 0 && hi_b - lo_b == 0)
    {
        float x = max(elems[lo_a], elems[lo_b]);
        float y = min(elems[hi_a], elems[hi_b]);
        return (x + y) / 2;
    }

    if (hi_a - lo_a == 1 && hi_b - lo_b == 0)
    {
        float x = max(elems[lo_a], elems[lo_b]);
        float y = min(elems[hi_a], elems[hi_b]);
        return (x + y) / 2;
    }

    float median_a = AbsoluteMedian(elems, lo_a, hi_a);
    float median_b = AbsoluteMedian(elems, lo_b, hi_b);

    int mid_a = (lo_a + hi_a) / 2;
    int mid_b = (lo_b + hi_b) / 2;
    if (median_a > median_b)
    {
        return MedianRecursive(elems, lo_a, mid_a, mid_b, hi_b);
    }
    else
    {
        return MedianRecursive(elems, mid_a, hi_a, lo_b, mid_b);
    }
}


float Median(vector<float> elems, int size)
{
    int n = 0;
    int m = (size / 2) - 1;
    int x = size / 2;
    int y = size - 1;
    while(true)
    {
        if(m - n == 1 && y - x == 1)
        {
            float a = max(elems[n], elems[x]);
            float b = min(elems[m], elems[y]);
            return (a + b) / 2;
        }
    }
    //return MedianRecursive(elems, 0, size - 1, size, size * 2 - 1);
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
        printf("%.2f", Median(elements, size));
        cout << endl;
    }
    
}