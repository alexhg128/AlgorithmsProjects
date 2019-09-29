/**
 * Alejandro Hahn
 * 
 * Proyecto F
 **/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Railroads
{
    vector<int> first;
    vector<int> second;
    vector<int> mix;
    int size;
};

bool Verify(Railroads input)
{
    int x = input.first.size() - 1;
    int y = x;
    bool reboot = false;
    stack<int> prev;
    stack<int> prevY;
    while(true){
        if(x == 0 && y == 0)
        {
            return true;
        }
        if (reboot)
        {
            if(prev.size() == 0)
            {
                return false;
            }
            x = prev.top();
            prev.pop();
            y = prevY.top();
            prevY.pop();
            reboot = false;
            y--;
        }
        if(input.first[x] == input.mix[x + y])
        {
            prev.push(x);
            prevY.push(y);
            x--;
        }
        else if (input.second[y] == input.mix[x + y])
        {
            y--;
        }
        else
        {
            reboot = true;
        }
    }
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
        Railroads r;
        r.size = n1 + n2;
        r.first.push_back(-1);
        r.second.push_back(-1);
        r.mix.push_back(-1);
        for (int i = 0; i < n1; i++)
        {
            int x;
            cin >> x;
            r.first.push_back(x);
        }
        for (int i = 0; i < n2; i++)
        {
            int x;
            cin >> x;
            r.second.push_back(x);
        }
        for (int i = 0; i < n1 + n2; i++)
        {
            int x;
            cin >> x;
            r.mix.push_back(x);
        }
        
        cout << (Verify(r) ? "possible" : "not possible") << endl;
    }
}