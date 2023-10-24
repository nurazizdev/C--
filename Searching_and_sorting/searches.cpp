#include <bits/stdc++.h>
using namespace std;

//   binary search

//   mid = (left + right) / 2;
//   if( shart(mid) ) left = mid + 1;
//   else right = mid;

//   mid = (left + right + 1) / 2;
//   if( shart(mid) ) left = mid;
//   else right = mid - 1;

int binary_search1(vector<int> arr, int n , int x){
    int a = 0 , b = n - 1 , k;
    while(a <= b){
        k = (a + b) / 2;
        if(arr[k] == x){
            return k;
        }
        if(arr[k] > x) b = k - 1;
        else a = k + 1;
    }
    return -1;
    // only for sorted arrays
}

int binary_search2(vector<int> arr, int n , int x){
    int k = 0;
    for(int b = n / 2 ; b >= 1 ; b /= 2)
        while(k + b < n && arr[k + b] <= x) k += b;
    if(arr[k] == x) return k;
    return -1;
    // only for sorted arrays
}   
