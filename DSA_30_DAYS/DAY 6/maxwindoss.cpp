#include <bits/stdc++.h>
using namespace std;


string minWindow(string s, string t) {

    vector<int> need(26, 0);
    vector<int> window(26, 0);


    // Store frequency of characters required from t
    for(char ch : t) {
        need[ch - 'A']++;
    }


    int left = 0;
    int right = 0;

    int required = t.length();
    int formed = 0;


    int minLength = INT_MAX;
    string answer = "";


    while(right < s.length()) {


        // Add current character into window
        char ch = s[right];

        window[ch - 'A']++;


        // If current character count satisfies requirement
        if(window[ch - 'A'] <= need[ch - 'A']) {
            formed++;
        }



        // Window is valid
        while(formed == required) {


            int currentLength = right - left + 1;


            // Update smallest window
            if(currentLength < minLength) {

                minLength = currentLength;

                answer = s.substr(left, currentLength);
            }



            // Remove left character
            char leftChar = s[left];

            window[leftChar - 'A']--;


            if(window[leftChar - 'A'] < need[leftChar - 'A']) {
                formed--;
            }


            left++;
        }


        right++;
    }


    return answer;
}



int main() {


    string s = "ADOBECODEBANC";
    string t = "ABC";


    string result = minWindow(s, t);


    cout << "Minimum Window: " << result;


    return 0;
}