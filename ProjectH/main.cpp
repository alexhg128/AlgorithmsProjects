/**
 * Alejandro Hahn
 * 
 * Proyecto H
 **/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

typedef std::vector<std::vector<int>> matrix;
typedef std::map<pair<int, set<int>>, int> distance_matrix;
typedef pair<int, set<int>> distance_matrix_key;

/**
 * Combinations
 **/

vector<int> comb_in;
vector<int> comb_util;
vector<set<int>> comb_out;

void combinate(int offset, int k)
{
    if (k == 0)
    {
        set<int> s;
        for (int x : comb_util)
        {
            s.insert(x);
        }
        comb_out.push_back(s);
        return;
    }
    for (int i = offset; i <= comb_in.size() - k; i++)
    {
        comb_util.push_back(comb_in[i]);
        combinate(i + 1, k - 1);
        comb_util.pop_back();
    }
}

vector<set<int>> combinate(int from, int k, int n)
{
    comb_in.clear();
    comb_out.clear();
    for (int i = 1; i < n; i++)
    {
        if (i != from)
        {
            comb_in.push_back(i);
        }
    }
    combinate(0, k);
    return comb_out;
}

/**
 * Traveller problem
 **/

int traveller(matrix input)
{
    distance_matrix d;
    for (int i = 0; i < input.size() - 1; i++)
    {
        for (int j = 1; j < input.size(); j++)
        {
            if (i == 0)
            {
                set<int> s;
                distance_matrix_key key = pair<int, set<int>>(j, s);
                d.insert(pair<distance_matrix_key, int>(key, input[0][j]));
                continue;
            }
            vector<set<int>> comb(combinate(j, i, input.size()));
            for (set<int> c : comb)
            {
                int acum = INT_MAX;
                for (int a : c)
                {
                    set<int> aux(c);
                    aux.erase(a);
                    int sum = input[j][a];
                    distance_matrix_key k = pair<int, set<int>>(a, aux);
                    int sto = d.find(k)->second;
                    if (sum != INT_MAX && sto != INT_MAX)
                    {
                        sum += d.find(k)->second;
                        if (acum > sum)
                        {
                            acum = sum;
                        }
                    }
                }
                distance_matrix_key k = pair<int, set<int>>(j, c);
                d.insert(pair<distance_matrix_key, int>(k, acum));
            }
        }
    }
    set<int> s;
    for (int i = 1; i < input.size(); i++)
    {
        s.insert(i);
    }
    int acum = INT_MAX;
    for (int a : s)
    {
        set<int> aux(s);
        aux.erase(a);
        int sum = input[0][a];
        distance_matrix_key k = pair<int, set<int>>(a, aux);
        int sto = d.find(k)->second;
        if (sum != INT_MAX && sto != INT_MAX)
        {
            sum += d.find(k)->second;
            if (acum > sum)
            {
                acum = sum;
            }
        }
    }
    return acum;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> i;
    i.resize(n, INT_MAX);
    matrix v;
    v.resize(n, i);
    for (int i = 0; i < v.size(); i++)
    {
        v[i][i] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        char x, y;
        int w;
        cin >> x >> y >> w;
        v[x - 65][y - 65] = w;
        v[y - 65][x - 65] = w;
    }
    int min = traveller(v);
    if (min != INT_MAX)
    {
        cout << min << endl;
    }
    else
    {
        cout << "INF" << endl;
    }
}