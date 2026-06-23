#include <iostream>
#include <unordered_map>

using namespace std;


int main()
{
    string s = "leetcode";


    unordered_map<char,int> freq;


    // Step 1: Count frequency

    for(int i=0; i<s.length(); i++)
    {
        freq[s[i]]++;
    }



    // Step 2: Find first character with count 1

    for(int i=0; i<s.length(); i++)
    {
        if(freq[s[i]] == 1)
        {
            cout << "First unique character: ";
            cout << s[i];
            break;
        }
    }


    return 0;
}