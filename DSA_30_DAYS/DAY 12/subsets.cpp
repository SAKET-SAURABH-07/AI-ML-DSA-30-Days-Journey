#include <iostream>
#include <vector>
using namespace std;

void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans)
{
    if(index == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    // Include current element
    temp.push_back(nums[index]);
    solve(index + 1, nums, temp, ans);

    // Backtrack
    temp.pop_back();

    // Exclude current element
    solve(index + 1, nums, temp, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, nums, temp, ans);

    cout << "Subsets are:\n";

    for(auto subset : ans)
    {
        cout << "{ ";

        for(auto x : subset)
        {
            cout << x << " ";
        }

        cout << "}\n";
    }

    return 0;
}