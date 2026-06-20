#include<iostream>
using namespace std;

int main()
{
    int arr[] = {2,4,6,8,10};
    int n = 5;

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
        arr[i] = sum;
    }

    // Printing prefix sum array
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}