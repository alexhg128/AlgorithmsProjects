/**
 * Alejandro Hahn
 * 
 * Proyecto C
 **/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int kombat(string str, vector<int> pow, int k)
{
    priority_queue<int> acum;
    int score = 0;
    char prev = str[0];
    for (int i = 0; i < pow.size(); i++)
    {
        if (str[i] == prev)
        {
            acum.push(pow[i]);
        }
        else
        {
            for (int i = 0; i < k && !acum.empty(); i++)
            {
                score += acum.top();
                acum.pop();
            }
            acum = priority_queue<int>();
            prev = str[i];
            acum.push(pow[i]);
        }
    }
    for (int i = 0; i < k && !acum.empty(); i++)
    {
        score += acum.top();
        acum.pop();
    }
    return score;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> power(n);
    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
    }
    string str;
    cin >> str;
    cout << kombat(str, power, k) << endl;
}