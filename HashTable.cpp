#include <iostream>
#include <vector>
#include <unordered_map>
// #include <bits/stdc++.h>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        
};


// v1 = 3 4 5
// v2 = 1 4 5

bool itemInCommon(vector<int> vect1, vector<int> vect2)
{
    unordered_map<int, bool> map;

    for(auto item: vect1)
    {
        map[item] = true; //OR => map.insert({item, true});
    }

    for(auto item:vect2)
    {
        if(map[item] == true)
        {
            return true;
        }
    }
    return false;
}

// nums: {1, 2, 3, 4, 4, 5, 5, 6, 7, 8}

// {4, 5}



vector<int> findDuplicates(const vector<int>& nums)
{
    unordered_map<int, int> myMap;
    for(auto i:nums)
    {
        if(myMap.find(i) != myMap.end())
        {
            myMap[i] +=1;
        }
        else
        {
            myMap[i] = 0;
        }
    }
    vector<int> result;
    for(auto j : myMap)
    {
        if(j.second > 0)
        {
            result.push_back(j.first);
        }
    }
    result = vector<int>(result.rbegin(), result.rend());
    return result;
}

unordered_map<char, int> myMap1;

// input_string: "programming"
// result = 'p'

// input_string: "truetalent"
// result 'r'
char firstNonRepeatingChar(const string& input_string)
{
    unordered_map<char, int> myMap;
    for(auto i: input_string)
    {
        myMap[i]++;
    }
    for(auto j : input_string)
    {
        if(myMap[j] == 1)
        {
            return j;
        }
    }
    return '\0';
}

// strings: {"eat", "tea", "tan", "ate", "nat", "bat"}
// {
//    {"eat", "tea", "ate"},
//    {"tan", "nat"},
//    {"bat"}
// }

vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    unordered_map<string, vector<string>> anagramGroups;
 
    for (const string& str : strings) {
        string canonical = str;
        sort(canonical.begin(), canonical.end());
 
        anagramGroups[canonical].push_back(str);
    }
 
    vector<vector<string>> result;
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }
 
    return result;
}

vector<int> twoSum(const vector<int>& nums, int target)
{
    unordered_map<int, int> myMap;

    vector<int> result;
    for(int i =0; i < nums.size(); i++)
    {
        if(myMap.find(target- nums[i]) == myMap.end())
        {
            myMap[nums[i]] = i;
        }
        else
        {
            result.push_back(myMap[target-i]);
            result.push_back(i);
            return result;
        }
    }
    return result;
}

// nums: {1, 2, 3, 4, 5}
// target: 9
// result = {1, 3}
vector<int> subarraySum(const vector<int>& nums, int target)
{
    unordered_map<int, int> sumIndex;
    sumIndex[0] = -1;
    int currentSum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(sumIndex.find(currentSum-target) != sumIndex.end())
        {
            return {sumIndex[currentSum-target], i};
        }
        else
        {
            sumIndex[currentSum] = i;
        }
    }
    return {};
}

// arr1{1, 2, 3};
// arr2{4, 5, 6}
// target = 8
//result = {{2, 6}, {3, 5}}

vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) 
{
    unordered_set<int> mySet;
    for(auto item:arr1)
    {
        mySet.insert(item);
    }
    
    vector<vector<int>> result;
    for(int i = 0; i < arr2.size(); i++)
    {
        auto it = mySet.find(target - arr2[i]);
        if( it!= mySet.end())
        {
            result.push_back({*it, i});
        }
    }
    return result;
}

// {2, 1, 6, 9, 4, 3}
// {1, 2, 3, 4}
// length 4

int longestConsecutiveSequence(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;
 
    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;
 
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }
 
            longestStreak = max(longestStreak, currentStreak);
        }
    }
 
    return longestStreak;
}


int main() {
    
    vector<int> nums{2, 1, 6, 9, 4, 3};
    // cout << longestConsecutiveSequence(nums) << endl;

    return 0;
}

