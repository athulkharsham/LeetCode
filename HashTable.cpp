#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

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


int main() {

    // vector<int> nums{1, 2, 3, 4, 4, 5, 5, 6, 7, 8};
    // vector<int> result = findDuplicates(nums);
    // cout << "{ ";
    // for(const auto item:result)
    // {
    //     cout << item << " ";
    // }
    // cout << "}";
    // cout << endl;
    // string input_string{"aabbcc"};
    // cout << firstNonRepeatingChar(input_string);
    string strings[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    return 0;
}
