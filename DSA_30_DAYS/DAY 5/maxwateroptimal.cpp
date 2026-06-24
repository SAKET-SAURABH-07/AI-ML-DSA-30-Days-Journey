#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[n] = {6, 2, 9, 7, 5};
    int maxArea = 0;
    int lp = 0;
    int rp = n - 1;
    while( lp < rp){
        int w = rp - lp;
        int h = min(arr[lp], arr[rp]);
        int area = w * h;
        maxArea = max(maxArea, area);
        if(arr[lp] < arr[rp]){
            lp++;
        }else{
            rp--;
        }
    }
    cout << maxArea << endl;
}