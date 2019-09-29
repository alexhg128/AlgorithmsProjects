#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int big_int;

big_int BinaryTreeCombinations(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1 || n == 2)
    {
        return n;
    }
    vector<big_int> combinations;
    combinations.resize(n + 1);
    combinations[0] = 1;
    combinations[1] = 1;
    combinations[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        big_int res = 0;
        for (int j = 1; j <= i; j++)
        {
            res += combinations[i - j] * combinations[j - 1];
        }
        combinations[i] = res;
    }
    return combinations[n];
}

int main()
{
    int n;
    cin >> n;
    cout << BinaryTreeCombinations(n) << " BTrees" << endl;
}