/**
 * Alejandro Hahn
 * 
 * Proyecto D
 **/
#include <iostream>
#include <deque>

using namespace std;

deque<int> sol;
deque<int> soldiers;
int remaining_soldiers;
int army_size;

int remaining(int power)
{
    int pow = power;
    while(pow > 0){
        if(sol[0] <= pow)
        {
            pow -= sol[0];
            sol.pop_front();
            remaining_soldiers--;
        }
        else
        {
            sol[0] -= pow;
            return remaining_soldiers;
        }
        if(sol.empty())
        {
            sol.assign(soldiers.begin(), soldiers.end());
            remaining_soldiers = army_size;
            return army_size;
        }
    }
    return remaining_soldiers;
}

int main()
{
    int b;
    cin >> army_size >> b;
    remaining_soldiers = army_size;
    deque<int> balls;
    for(int i = 0; i < army_size; i++)
    {
        int x;
        cin >> x;
        soldiers.push_back(x);
        sol.push_back(x);
    }
    sol.assign(soldiers.begin(), soldiers.end());
    for(int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        cout << remaining(x) << endl;
    }
    return 0;
}