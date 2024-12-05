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

/*
Input:

myList: [3, 7, 2, 9, 5]

Output:

[9, 2]

*/

vector<int> findMaxMin(vector<int>& myList)
{
    int max = myList[0];
    int min = myList[0];

    for(int i=0; i < myList.size(); i++)
    {
        if(myList[i] >= max)
            max = myList[i];

        if(myList[i] <= min)
            min = myList[i];
    }
    return vector<int>{max, min};
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

    // removeElement(vect, 3);

    vector<int> maxMin{3, 7, 2, 9, 5};
    auto result = findMaxMin(maxMin);
    display_vector(result);

    return 0;
}