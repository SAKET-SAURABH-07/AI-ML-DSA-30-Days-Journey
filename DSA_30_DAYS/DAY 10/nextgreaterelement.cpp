#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> s;
        unordered_map<int, int> mp;

        int n = nums2.size();

        // Find Next Greater Element for every element in nums2
        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            if (s.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> ans;

        // Build answer for nums1
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n1, n2;

    cout << "Enter size of nums1: ";
    cin >> n1;

    vector<int> nums1(n1);

    cout << "Enter elements of nums1:\n";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "\nEnter size of nums2: ";
    cin >> n2;

    vector<int> nums2(n2);

    cout << "Enter elements of nums2:\n";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "\nNext Greater Elements:\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}