#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


void display(stack<char> &stk) 
{
    string str{};

    while(!stk.empty())
    {
        str.push_back(stk.top());
        stk.pop();
    }
    cout << str << endl;
}

// "abc d efg xy"
// "cba d gfe, yx"
string reverse_subwords(string line)
{
    stack<char> stk{};
    string result;
    line.push_back(' '); // last to be formed.
    // store the incoming string in a stack
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] != ' ')
        {
            stk.push(line[i]);
        }
        else
        {
            while(!stk.empty())
            {
                result.push_back(stk.top());
                stk.pop();
            }
            result.push_back(' ');
        }
    }

    return result;
}

int reverse_num(int number)
{
    std::stack<int> sd;
    int result = 1;
    while (number > 0)
    {
        int digit = number%10;
        number /= 10;
        sd.push(digit);
    }
    int tens =1;
    while (!sd.empty())
    {
        int digit = sd.top();
        sd.pop();
        number = digit * tens + number;
        tens*=10;

    }
    return number;
    
}   

bool isValid(string str)
{
    stack<char> stk;
    // store all char in stack
    for(auto item : str)
    {
        if(item == '(')
        {
            stk.push(item);
        }
        else if(item == ')')
        {
            if(stk.size() <1 || stk.top() != '(')
            {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}

// abbaca
// result = ca
string removeDuplicates(string s) 
{
    stack<char> stk;
    string result;
    for(auto item:s)
    {
        if(stk.empty())
        {
            stk.push(item);
        }
        else if(stk.top() != item)
        {
            stk.push(item);
        }
        else
        {
            stk.pop();
        }
    }
    while(!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    result = string(result.rbegin(), result.rend());
    return result;
}


vector<int> asteroidCollision(vector<int> asteroids) 
{
    stack<int> collision;
    vector<int> result;
    if(collision.empty())
    {
        collision.push(asteroids[0]);
    }
    int item =1;
    while(!collision.empty() && item < asteroids.size())
    {

        if((asteroids[item] > 0 && collision.top() > 0) ||
            (asteroids[item] < 0 && collision.top() < 0))
        {
            collision.push(asteroids[item]);
            item++;
        }
        else
        {
            if(abs(asteroids[item]) > abs(collision.top()))
            {
                collision.pop();
                collision.push(asteroids[item]);
            }
            else if(abs(asteroids[item]) == abs(collision.top()))
            {
                collision.pop();
            }
            else
            {
                item ++;
            }
        } 
    }


    while (!collision.empty())
    {
        result.push_back(collision.top());
        collision.pop();
    }
    result = vector<int>(result.rbegin(), result.rend());
    return result;

}

int main()
{
    vector<int> asteroids{5, 10, -5};
    auto result = asteroidCollision(asteroids);

    for(auto item:result)
        cout << item << " ";
    cout << endl;
    return 0;
}