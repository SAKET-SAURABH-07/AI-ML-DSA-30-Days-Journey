#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char, int> m;
    queue<int> q;

    int firstUniqChar(string s) {

        for (int i = 0; i < s.size(); i++) {

            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }

            m[s[i]]++;

            // Remove indices whose characters are no longer unique
            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        if (q.empty()) {
            return -1;
        }

        return q.front();
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter the string: ";
    cin >> s;

    int index = obj.firstUniqChar(s);

    if (index == -1) {
        cout << "No unique character found." << endl;
    } else {
        cout << "First unique character: " << s[index] << endl;
        cout << "Index: " << index << endl;
    }

    return 0;
}