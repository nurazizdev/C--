#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void add(int i , int delta){
    for(;i < t.size(); i = i | (i + 1))
        t[i] += delta;
}

int rsq(int i){
    long long res = 0;
    for(;i >= 0 ; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

int get(int l , int r){
    return rsq(r) - rsq(l - 1);
}