#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[n] = {6, 2, 9, 7, 5};
    int maxArea = 0;
    for(int i = 0 ; i < n ; i++){

        for(int j = i + 1 ; j < n ; j++){
            int  w = j - i;
            int h = min(arr[i], arr[j]);
            int area = w * h;
            maxArea = max(maxArea, area);
        }

    }
    cout << maxArea << endl;
}