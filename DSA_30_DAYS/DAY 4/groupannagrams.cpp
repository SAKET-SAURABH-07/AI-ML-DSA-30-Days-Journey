#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main()
{
    vector<string> words =
    {
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat"
    };


    unordered_map<string, vector<string>> mp;


    for(int i=0; i<words.size(); i++)
    {
        string key = words[i];


        sort(key.begin(), key.end());


        mp[key].push_back(words[i]);
    }



    for(auto group : mp)
    {
        for(string word : group.second)
        {
            cout << word << " ";
        }

        cout << endl;
    }


    return 0;
}