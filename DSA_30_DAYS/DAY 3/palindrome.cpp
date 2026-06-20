#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int st = 0;
    int end = s.length() - 1;

    while (st < end) {

        // skip non-alphanumeric from left
        if (!isalnum(s[st])) {
            st++;
            continue;
        }

        // skip non-alphanumeric from right
        if (!isalnum(s[end])) {
            end--;
            continue;
        }

        // compare characters (case-insensitive)
        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        st++;
        end--;
    }

    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    if (isPalindrome(s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}