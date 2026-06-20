#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s = "listen";
    string t = "silent";

    bool isAnagram = true; // assume true, prove otherwise

    if (s.length() != t.length())
    {
        isAnagram = false;
    }
    else
    {
        unordered_map<char, int> freq;

        // Step 1: count characters in s
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            freq[c] = freq[c] + 1;
        }

        // Step 2: subtract characters using t
        for (int i = 0; i < t.length(); i++)
        {
            char c = t[i];
            freq[c] = freq[c] - 1;
        }

        // Step 3: check every entry in the map
        for (pair<char, int> entry : freq)
        {
            char letter = entry.first;
            int count = entry.second;

            if (count != 0)
            {
                isAnagram = false;
            }
        }
    }

    if (isAnagram == true)
        cout << "true";
    else
        cout << "false";

    return 0;
}