#include <bits/stdc++.h>
using namespace std;


int longestRepeatingCharacter(string s, int k) {

    int n = s.length();
    int ans = 0;


    // Start point of substring
    for(int i = 0; i < n; i++) {

        vector<int> freq(26, 0);

        int maxFreq = 0;


        // End point of substring
        for(int j = i; j < n; j++) {


            // Count current character
            freq[s[j] - 'A']++;


            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[j] - 'A']);


            // Current substring length
            int length = j - i + 1;


            // Required replacements
            int replacements = length - maxFreq;


            if(replacements <= k) {
                ans = max(ans, length);
            }
        }
    }


    return ans;
}



int main() {

    string s = "AABABBA";
    int k = 1;


    cout << longestRepeatingCharacter(s, k);

    return 0;
}