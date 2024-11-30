#include <iostream>
#include <vector>
using namespace std;

// Display elements of input vector
void display_vector(const vector<int> &v)
{
    for(int i=0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout <<endl;
}

// 0 1 2 3 4 
// 4 0 1 2 3
void right_rotate(vector<int> &v)
{
    int last_element = v[v.size()-1];

    for(int i = v.size()-1; i > 0; i--)
    {
        v[i] = v[i-1];
    }
    v[0] = last_element;
} 

// 0 1 2 3 4
// 1 2 3 4 0
void left_rotate(vector<int> &v)
{
    int first_element = v[0];
    for(int i=0; i < v.size(); i++)
    {
        v[i] = v[i+1];
    }
    v[v.size() - 1] = first_element;
}

// Right rotation with steps

// 0 1 2 3 4
// 3 4 0 1 2

void right_rotates(vector<int> &v, int times)
{
    times %= v.size();

    while (times--)
     right_rotate(v);
}

// 4 0 1 2 3
// retur val 1
// new vector 4 0 2 3
int pop(vector<int> &v, int idx)
{
    if(idx < 0 || idx >=v.size())
    {
        throw out_of_range("Index out of range"); 
    }
    int ret_val = v[idx];

    for(int i = idx +1; i < v.size(); i++)
    {
        v[i-1] = v[i];
    }
    v.pop_back();
    return ret_val;
}



int main()
{

    vector<int> v{0, 1, 2, 3, 4};

    // display_vector(v);
    // right_rotate(v);
    // left_rotate(v);
    // right_rotates(v, 2);
    // vector<int> v1{4, 0, 1, 2, 3};
    // cout << pop(v1, 2) << endl;;
    // display_vector(v1);
    return 0;
}