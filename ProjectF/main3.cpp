/**
 * Alejandro Hahn
 * 
 * Proyecto F
 **/

#include <iostream>
#include <deque>

using namespace std;

bool verify(deque<int> railroad1, deque<int> railroad2, deque<int> sequence)
{
    for (int train : sequence)
    {
        if(!railroad1.empty() && railroad1.front() == train)
        {
            railroad1.pop_front();
        }
        if(!railroad2.empty() && railroad2.front() == train)
        {
            railroad2.pop_front();
        }
    }
    if (railroad1.empty() && railroad2.empty())
    {
        return true;
    }
    else
    {
        return false;
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