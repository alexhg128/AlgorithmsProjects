/**
 * Alejandro Hahn
 * 
 * Proyecto G (Recursivo)
 **/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Duo
{
    string first;
    string second;
};

int LcsRecursive(Duo input, int x, int y)
{
    if (x == 0 || y == 0)
    {
        return 0;
    }
    if (input.first[x - 1] == input.second[y - 1])
    {
        return 1 + LcsRecursive(input, x - 1, y - 1);
    }
    else
    {
        return max(LcsRecursive(input, x - 1, y), LcsRecursive(input, x, y - 1));
    }
}

int Lcs(Duo input)
{
    return LcsRecursive(input, input.first.size(), input.second.size());
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        Duo d;
        cin >> d.first;
        cin >> d.second;
        cout << "Case " << i + 1 << ": " << Lcs(d) << endl;
    }
    return 0;
}