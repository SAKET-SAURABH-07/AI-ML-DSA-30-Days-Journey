#include <iostream>
using namespace std;

int main() {

    int nums[] = {1, 1, 2, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int slow = 0;

    for(int fast = 1; fast < n; fast++) {

        if(nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }

    int k = slow + 1;

    cout << "Number of unique elements: " << k << endl;

    cout << "Modified array: ";

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}