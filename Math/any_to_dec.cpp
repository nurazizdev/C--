#include <bits/stdc++.h>
using namespace std;

int any_to_dec(string s , int base){
    int x = 0;
    for(char c : s){
        int it = (c >= '0' && c <= '9') ? (c - 48) : (c - 55);
        x = x * base + it;
    }
    return x;
    // cout << any_to_dec(s , k) << " yoki " << stoi(s, nullptr, k);
}