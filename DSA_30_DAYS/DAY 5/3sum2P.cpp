#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int nums[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(nums) / sizeof(nums[0]);

    // Sorting array
    sort(nums, nums + n);


    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;


    for(int i = 0; i < n; i++) {

        // Skip duplicate values for i
        if(i > 0 && nums[i] == nums[i-1])
            continue;


        int j = i + 1;
        int k = n - 1;


        while(j < k) {

            int sum = nums[i] + nums[j] + nums[k];


            if(sum < 0) {

                j++;   // Need a bigger value

            }
            else if(sum > 0) {

                k--;   // Need a smaller value

            }
            else {

                cout << "Triplet: ["
                     << nums[i] << ", "
                     << nums[j] << ", "
                     << nums[k] << "]"
                     << endl;


                j++;
                k--;


                // Skip duplicate left values
                while(j < k && nums[j] == nums[j-1]) {
                    j++;
                }
            }
        }
    }


    return 0;
}