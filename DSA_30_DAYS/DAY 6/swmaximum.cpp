#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    deque<int> dq;   // stores indices
    vector<int> res;


    // First window
    for (int i = 0; i < k; i++) {

        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }


    // Store maximum of first window
    res.push_back(nums[dq.front()]);


    // Process remaining windows
    for (int i = k; i < nums.size(); i++) {


        // Remove elements which are outside current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }


        // Remove smaller elements
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }


        // Add current element
        dq.push_back(i);


        // Maximum of current window
        res.push_back(nums[dq.front()]);
    }


    return res;
}


int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;


    vector<int> answer = maxSlidingWindow(nums, k);


    cout << "Maximum in every window: ";

    for (int x : answer) {
        cout << x << " ";
    }


    return 0;
}