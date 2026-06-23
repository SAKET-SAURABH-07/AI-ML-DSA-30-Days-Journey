#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;

    int start = 0;   
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];

        // 🔴 if character already seen AND inside window
        if (mp.find(ch) != mp.end() && mp[ch] >= start) {
            start = mp[ch] + 1;   // move start right
        }

        // update last seen index
        mp[ch] = i;

        // current window size
        int windowLen = i - start + 1;

        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s);
}