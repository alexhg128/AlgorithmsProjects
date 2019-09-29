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
#include <string>
#include <cmath>

using namespace std;

typedef std::vector<std::vector<double>> matrix;
typedef std::map<pair<int, set<int>>, double> distance_matrix;
typedef pair<int, set<int>> distance_matrix_key;

struct traveller_result {
    bool exists;
    double distance;
    vector<int> path;
};

struct city {
    string label;
    int id;
    double x;
    double y;
};

vector<int> comb_in;
vector<int> comb_util;
vector<set<int>> comb_out;

void combinate(int offset, int k) {
	if (k == 0) {
		set<int> s;
		for (int x : comb_util)
		{
			s.insert(x);
		}
		comb_out.push_back(s);
		return;
	}
	for (int i = offset; i <= comb_in.size() - k; i++) {
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

traveller_result traveller(matrix input)
{
	distance_matrix d;
    distance_matrix n;
	for (int i = 0; i < input.size() - 1; i++)
	{
		for (int j = 1; j < input.size(); j++)
		{
			if (i == 0)
			{
				set<int> s;
				distance_matrix_key key = pair<int, set<int>>(j, s);
				d.insert(pair<distance_matrix_key, double>(key, input[0][j]));
				n.insert(pair<distance_matrix_key, int>(key, 0));
				continue;
			}
			vector<set<int>> comb(combinate(j, i, input.size()));
			for (set<int> c : comb)
			{
				double acum = INT_MAX;
                int node = *c.begin();
				for (int a : c)
				{
					set<int> aux(c);
					aux.erase(a);
					double sum = input[j][a];
					distance_matrix_key k = pair<int, set<int>>(a, aux);
					double sto = d.find(k)->second;
					if (sum != INT_MAX && sto != INT_MAX)
					{
						sum += d.find(k)->second;
						if (acum > sum)
						{
                            node = a;
							acum = sum;
						}
					}
				}
				distance_matrix_key k = pair<int, set<int>>(j, c);
				d.insert(pair<distance_matrix_key, double>(k, acum));
				n.insert(pair<distance_matrix_key, int>(k, node));
			}
		}
	}
	set<int> s;
	for (int i = 1; i < input.size(); i++)
	{
		s.insert(i);
	}
	double acum = INT_MAX;
    int node = *s.begin();
    set<int> lastSet;
	for (int a : s)
	{
		set<int> aux(s);
		aux.erase(a);
		double sum = input[0][a];
		distance_matrix_key k = pair<int, set<int>>(a, aux);
		double sto = d.find(k)->second;
		if (sum != INT_MAX && sto != INT_MAX)
		{
			sum += d.find(k)->second;
			if (acum > sum)
			{
				acum = sum;
                node = a;
                lastSet = aux;
			}
		}
	}
    traveller_result res;
    res.distance = acum;
    res.exists = acum != INT_MAX;
    res.path.push_back(0);
    res.path.push_back(node);
    for(int i = input.size() - 2; i > 0; i++)
    {
        distance_matrix_key k = pair<int, set<int>>(node, lastSet);
		int sto = n.find(k)->second;
        res.path.push_back(sto);
        lastSet.erase(sto);
        node = sto;
    }
    res.path.push_back(0);
	return res;
}

double distance(city x, city y)
{
    return pow(pow(x.x - x.y,2) + pow(x.y - y.y,2),0.5);
}

int main()
{
	int n;
	cin >> n;
    vector<city> cities;
	vector<double> i;
	i.resize(n, INT_MAX);
	matrix v;
	v.resize(n, i);
	for (int i = 0; i < v.size(); i++)
	{
		v[i][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
        string str;
		double x, y;
		cin >> str >> x >> y;
        city ci;
        ci.label = str;
        ci.id = i;
        ci.x = x;
        ci.y = y;
	}
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                v[i][j] = distance(cities[i], cities[j]);
            }
        }
    }
	traveller_result res = traveller(v);
	if(res.exists)
    {
        for(int e : res.path)
        {
            cout << e << " ";
        }
    }
}