#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int nums[] = {2,7,11,15};
    int target = 9;

    int n = 4;

    unordered_map<int,int> mp;


    for(int i=0; i<n; i++)
    {
        int need = target - nums[i];


        if(mp.find(need) != mp.end())
        {
            cout << "Answer: ";
            cout << mp[need] << " " << i;
            break;
        }


        mp[nums[i]] = i;
    }


    return 0;
}