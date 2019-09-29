/**
 * Alejandro Hahn
 * 
 * Proyecto F
 **/

#include <iostream>
#include <vector>

using namespace std;

bool verify(vector<int> railroad1, vector<int> railroad2, vector<int> sequence)
{
    vector<bool> v(railroad2.size() + 1, false);
    vector<vector<bool>> mat(railroad1.size() + 1, v);
    mat[0][0] = 0;
    for(int i = 1; i < railroad1.size() + 1; i++)
    {
        mat[i][0] = (railroad1[i - 1] == sequence[i - 1]);
    }
    for(int i = 1; i < railroad2.size() + 1; i++)
    {
        mat[0][i] = (railroad2[i - 1] == sequence[i - 1]);
    }
    for(int i = 1; i < railroad1.size() + 1; i++)
    {
        for(int j = 1; j < railroad2.size() + 1; j++)
        {
            mat[i][j] = (sequence[i + j - 1] == railroad1[i - 1] && mat[i - 1][j])
                        || (sequence[i + j - 1] == railroad2[j - 1] && mat[i][j - 1]);
        }
    }
    return mat[railroad1.size()][railroad2.size()];
}

int main()
{
    while (true)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0)
        {
            break;
        }
        vector<int> railroad1;
        vector<int> railroad2;
        vector<int> sequence;
        for (int i = 0; i < n1; i++)
        {
            int x;
            cin >> x;
            railroad1.push_back(x);
        }
        for (int i = 0; i < n2; i++)
        {
            int x;
            cin >> x;
            railroad2.push_back(x);
        }
        for (int i = 0; i < n1 + n2; i++)
        {
            int x;
            cin >> x;
            sequence.push_back(x);
        }
        cout << (verify(railroad1, railroad2, sequence) ? "possible" : "not possible") << endl;
    }
    return 0;
}