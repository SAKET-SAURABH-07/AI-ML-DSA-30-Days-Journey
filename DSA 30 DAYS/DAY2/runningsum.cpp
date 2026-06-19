#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
        arr[i] = sum;
    }

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}