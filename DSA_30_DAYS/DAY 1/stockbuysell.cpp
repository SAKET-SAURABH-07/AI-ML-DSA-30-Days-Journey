#include <iostream>
using namespace std;

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};

    int n = 6;


    int minimumPrice = prices[0];
    int maximumProfit = 0;


    for(int i = 1; i < n; i++)
    {
        // Find the lowest buying price
        if(prices[i] < minimumPrice)
        {
            minimumPrice = prices[i];
        }


        // Calculate profit if we sell today
        int profit = prices[i] - minimumPrice;


        // Store maximum profit
        if(profit > maximumProfit)
        {
            maximumProfit = profit;
        }
    }


    cout << "Maximum Profit = " << maximumProfit;


    return 0;
}