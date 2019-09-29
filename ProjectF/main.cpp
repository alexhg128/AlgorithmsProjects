/**
 * Alejandro Hahn
 * 
 * Proyecto F
 **/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool equals(deque<int> d1, deque<int> d2)
{
    if(d1.size() != d2.size())
    {
        return false;
    }
    for (int i = 0; i < d1.size(); i++)
    {
        if(d1[i] != d2[i])
        {
            return false;
        }
    }
    return true;
}

bool verify(deque<int> railroad1, deque<int> railroad2, deque<int> sequence)
{
    deque<int> pending;
    for (int train : sequence)
    {
        if (!railroad1.empty() && !railroad2.empty() && railroad1.front() == train && railroad2.front() == train)
        {
            pending.push_back(train);
            railroad1.pop_front();
            railroad2.pop_front();
        }
        else if (!pending.empty() && !railroad1.empty() && railroad1.front() == train && pending.front() == train)
        {
            railroad1.pop_front();
        }
        else if (!pending.empty() && !railroad2.empty() && railroad2.front() == train && pending.front() == train)
        {
            railroad2.pop_front();
        }
        else if (!railroad1.empty() && railroad1.front() == train)
        {
            railroad1.pop_front();
            if (!pending.empty())
            {
                for (int i = pending.size() - 1; i >= 0; i--)
                {
                    railroad2.push_front(pending[i]);
                }
                pending.clear();
            }
        }
        else if (!railroad2.empty() && railroad2.front() == train)
        {
            railroad2.pop_front();
            if (!pending.empty())
            {
                for (int i = pending.size() - 1; i >= 0; i--)
                {
                    railroad1.push_front(pending[i]);
                }
                pending.clear();
            }
        }
        else if(!pending.empty() && pending.front() == train)
        {
            pending.pop_front();
        }
        else if (!pending.empty())
        {
            deque<int> d1(pending);
            deque<int> d2(pending);
            deque<int> d3(pending);
            bool success = false;
            int i = 0;
            int j = 0;
            int k = d1.size();
            while(j != k) {
                bool x = true;
                for (int e = j + 1; e < k; e++)
                {
                    if(d1[e] != d1[e - j - 1])
                    {
                        x = false;
                        break;
                    }
                }
                if(x)
                {
                    for(int e = 0; e < j + 1; e++)
                    {
                        d2.pop_front();
                    }
                    for(int e = j + 1; e < k; e++)
                    {
                        d3.pop_front();
                    }
                    pending.clear();
                    success = true;
                    if(d2.front() == train && d3.front() == train)
                    {
                        pending.push_back(train);
                    }
                    else if (d2.front() == train)
                    {
                        d2.pop_front();
                    }
                    else if (d3.front() == train)
                    {
                        d3.pop_front();
                    }
                    else
                    {
                        return false;
                    }
                    for (int e = d2.size() - 1; e >= 0; e--)
                    {
                        railroad1.push_front(d2[e]);
                    }
                    for (int e = d3.size() - 1; e >= 0; e--)
                    {
                        railroad2.push_front(d3[e]);
                    }
                    break;
                }
                j++;
            }
            
            if (!success)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
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
        deque<int> railroad1;
        deque<int> railroad2;
        deque<int> sequence;
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
} 