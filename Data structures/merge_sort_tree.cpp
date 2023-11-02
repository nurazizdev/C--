#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> a;

vector<int> merge(vector<int> x , vector<int> y){
    vector<int> res;
    int n = x.size() , m = y.size();
    int i = 0 , j = 0;
    while(i < n && j < m){
        if(x[i] < y[j]){
            res.push_back(x[i]);
            i ++;
        }
        else{
            res.push_back(y[j]);
            j ++;
        }
    }
    while(i < n) res.push_back(x[i ++]);
    while(j < m) res.push_back(y[j ++]);
    return res;
}

void build(int v , int l , int r){
    if(l == r){
        tree[v].push_back(a[l - 1]);
        return;
    }
    int m = (l + r) >> 1;
    build(v << 1 , l , m);
    build(v << 1 | 1 , m + 1 , r);
    tree[v] = merge(tree[v << 1] , tree[v << 1 | 1]);
}

vector<int> get(int v , int l , int r , int L , int R , int k){
    if(l > R || r < L) return vector<int>();
    if(L <= l && R >= r){
        return tree[v];
    }
    int m = (l + r) >> 1;
    vector<int> bu1 = get(v << 1 , l , m , L , R , k);
    vector<int> bu2 = get(v << 1 | 1 , m + 1 , r , L , R , k);
    return merge(bu1 , bu2);
}