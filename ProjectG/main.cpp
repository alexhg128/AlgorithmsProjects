/**
 * Alejandro Hahn
 * 
 * Proyecto G 
 **/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Duo
{
    string first;
    string second;
};

int Lcs(Duo input)
{
    int x = input.first.size();
    int y = input.second.size();
    vector<vector<int>> lcs;
    vector<int> f;
    f.assign(y + 1, 0);
    lcs.assign(x + 1, f);
    for(int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if(i == 0 || j == 0)
            {
                lcs[i][j] = 0;
                continue;
            }
            if (input.first[i - 1] == input.second[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                continue;
            }
            lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);  
        }
        
    }
    return lcs[x][y];
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