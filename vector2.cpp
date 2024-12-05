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
// rotate for k =2
// {1, 2, 3, 4, 5, 6}
// reverse first part until k
// {4, 3, 2, 1, 5, 6}
// reverse part from rotation to end
// {4, 3, 2, 1, 6, 5}
// reverse entire array
// {5, 6, 1, 2 , 3, 4}

void rotate(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return;
    }
    k = k % nums.size();

    // reverse until k
    for(int start=0, end=nums.size()-k-1; start < end; start++, end--)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // reverse from k to end
    for(int start =k, end = nums.size()-1; start < end; start++, end--)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // reverse whole array
    for(int start =k, end = nums.size()-1; start < end; start++, end--)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

}

/*
Input:
nums: [-2,1,-3,4,-1,2,1,-5,4]
Output:
6
*/

int maxSubarray(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
 
    int maxSum = nums[0];
    int currentSum = nums[0];
 
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
 
    return maxSum;
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