#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 1)
        return true;

    if (n <= 0 || n % 3 != 0)
        return false;

    return isPowerOfThree(n / 3);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfThree(n))
        cout << n << " is a Power of 3";
    else
        cout << n << " is NOT a Power of 3";

    return 0;
}