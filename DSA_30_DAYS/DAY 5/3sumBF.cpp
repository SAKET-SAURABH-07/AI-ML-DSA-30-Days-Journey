#include <iostream>
using namespace std;

int main() {

    int nums[] = {-4,-1,-1,0,1,2};
    int n = 6;

    for(int i= 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            for(int k = j+1 ; k < n ; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    cout << "Triplet found: " << nums[i] << ", " << nums[j] << ", " << nums[k] << endl;
                }
            }

        }
    }
}