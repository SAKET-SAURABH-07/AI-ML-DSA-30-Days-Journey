#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int nums[] = {2, 7, 11, 15};

    int n = 4;          
    int target = 9;


    unordered_map<int,int> mp;


    for(int i = 0; i < n; i++)
    {
        int current = nums[i];

        int need = target - current;


        
        if(mp.find(need) != mp.end())
        {
            cout << "Indexes are: ";
            cout << mp[need] << " and " << i;
            return 0;
        }


        
        mp[current] = i;
    }


    cout << "No pair found";

    return 0;
}