#include <bits/stdc++.h>
using namespace std;

string dec_to_any(long long n , int base){
    string s = "";
    do{
        int r = n % base ;
        int it = (r < 10) ? 48 : 55;
        s = char(r + it) + s;
        n = (n - r) / base;
    }while(n);
    return s;
}    