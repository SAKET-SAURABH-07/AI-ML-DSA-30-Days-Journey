#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {

    if (target <= nums[0])
        return 0;

    for (int j = 0, k = 1; k < nums.size(); j++, k++) {

        if (target == nums[j])
            return j;

        if (target == nums[k])
            return k;

        if (target > nums[j] && target < nums[k])
            return k;
    }

    return nums.size();
}

int main() {

    vector<int> nums = {1, 3, 5, 6};

    int target;
    cout << "Enter target: ";
    cin >> target;

    int ans = searchInsert(nums, target);

    cout << "Insert Position: " << ans << endl;

    return 0;
}