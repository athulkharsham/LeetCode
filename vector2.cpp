#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//Input:
//nums: [3, 2, 3, 6, 3, 4, 5, 3]
//val: 3
void removeElement(vector<int>& nums, int val)
{
    int count=0;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] != val)
        {
           nums[count] = nums[i];
           count ++;
        }
    }
    nums.resize(count);
}


// Display elements of input vector
void display_vector(const vector<int> &v)
{
    for(int i=0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout <<endl;
}

int main()
{
    vector<int> vect{3, 2, 3, 6, 3, 4, 5, 3};

    // display_vector(vect);

    removeElement(vect, 3);
    display_vector(vect);

    return 0;
}