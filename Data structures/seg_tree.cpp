#include <bits/stdc++.h>
using namespace std;

vector<int> tree ;
vector<int> a;
 
int merge(int l , int r){
    return max(l,r);
}
 
void build(int v , int l , int r){
    if(l == r){
        tree[v] = a[l - 1];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v , l , m);
    build(2 * v + 1, m + 1, r);
 
    tree[v] = merge(tree[2 *v] , tree[2 * v + 1]);
}
 
void update(int v , int l , int r , int id , int new_val){
    if(l == r){
        tree[v] = new_val;
        return;
    }
    int m = (l + r) / 2;
    if(id <= m) update(2 * v, l, m, id , new_val);
    else update(2 * v + 1, m + 1 , r , id , new_val);
 
    tree[v] = merge(tree[2 *v] , tree[2 * v + 1]);
}
 
int get(int v, int l , int r , int L , int R){
    if(l == L && r == R) return tree[v];
    int m = (l + r) / 2;
    if(R <= m) return get(2 * v , l , m , L , R);
    if(m < L) return get(2 * v + 1, m + 1 , r , L , R);
 
    return merge(get(v * 2 , l , m , L , m) , get(v * 2 + 1, m + 1 , r , m + 1 , R));
}
 
signed main(){
    int n;
    cin >> n;
    a.resize(n);
    tree.resize(4 * n);
    for(int &x : a) cin >> x;
 
    build(1 , 1 , n);
 
    int m , l , r;
    char type;
    cin >> m;
    for(int i = 0 ; i < m; i++) {
        cin >> type >> l >> r;
        if(type == 'u') update(1 , 1 , n , l , r);
        else cout << get(1 , 1 , n , l , r) << ' ';
    }
}