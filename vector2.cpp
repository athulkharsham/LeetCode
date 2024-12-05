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


string findLongestString(vector<string>& stringList)
{
    string longestString = "";

    for(const string &str : stringList)
    {
        if(str.length() > longestString.length())
        {
            longestString = str;
        }
    }
    return longestString;
}


/*
Input:
nums: [1,1,2,2,2,3,4,4]
Output:
5
Modified nums:
[1,2,3,4,X,X,X,X] (where X can be any number since it's beyond the new length)
*/

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() < 1)
    {
        return 0;
    }

    int writePinter = 1;

    for(int readPointer =1; readPointer < nums.size(); readPointer++)
    {
        if(nums[readPointer] != nums[readPointer -1])
        {
            nums[writePinter] = nums[readPointer];
            writePinter++;
        }
    }
    return writePinter; 
}

int main()
{
    vector<int> vect{3, 2, 3, 6, 3, 4, 5, 3};

    // display_vector(vect);

    // removeElement(vect, 3);

    // vector<int> maxMin{3, 7, 2, 9, 5};
    // auto result = findMaxMin(maxMin);


    // display_vector(result);

    return 0;
}