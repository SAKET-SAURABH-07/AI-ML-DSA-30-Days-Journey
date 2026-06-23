#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2,3,-2,4};
    int n = 4;

    int maxProduct = arr[0];


    for(int i = 0; i < n; i++)
    {
        int product = 1;

        for(int j = i; j < n; j++)
        {
            product = product * arr[j];

            if(product > maxProduct)
            {
                maxProduct = product;
            }
        }
    }


    cout << maxProduct;

    return 0;
}