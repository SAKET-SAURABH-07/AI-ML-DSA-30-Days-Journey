#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1};
    int n = 7;

    int currentSum = 0;
    int maximumSum = 0;


    for(int i=0;i<n;i++)
    {
        currentSum += arr[i];


        if(currentSum < 0)
        {
            currentSum = 0;
        }


        maximumSum = max(maximumSum,currentSum);
    }


    cout << maximumSum;

    return 0;
}