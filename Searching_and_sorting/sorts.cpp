#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &a , int l , int r){
    vector<int> cnt(r - l + 1);
    for(int x : a) cnt[x - l] ++;
    for(int val = l , i = 0 , k = 0 ; val <= r ; val ++ , i ++)
        for(int j = 0 ; j < cnt[i] ; j ++)
            a[k ++] = val;
}

random_device rnd;
void quick_sort(vector<int> &a,int L,int R){
    if(R - L < 1) return;
    int pivot = a[rnd() % (R - L + 1) + L];
    int l = L , r = R;
    while(l <= r){
        while(a[l] < pivot) l ++;
        while(a[r] > pivot) r --;
        if(l <= r)
            swap(a[l ++] , a[r --]);
    }
    quick_sort(a , L , r);
    quick_sort(a , l , R);
}

void heap(vector<int> &a , int i , int n){
    int mx;
    while(true){
        mx = i;
        if(2 * i <= n && a[2 * i] > a[mx]) mx = 2 * i ;
        if(2 * i + 1 <= n && a[2 * i + 1] > a[mx]) mx = 2 * i + 1 ;
        if(mx != i) swap(a[i] , a[mx]) , i = mx;
        else break;
    }
}
 
void heap_sort(vector<int> &a ,int n){
    for(int i = n ; i >= 1 ; i --) heap(a , i , n);
    for(int i = n ; i >= 1 ; i --)
        swap(a[i] , a[1]),
        heap(a , 1 , i - 1);
}

void merge_sort(vector<int> &a, int l , int r){
    if(r - l < 2) return;
    int m = (l + r) / 2;
    merge_sort(a , l , m);
    merge_sort(a , m , r);
 
    int n = r - l , u = l , v = m;
    vector<int> t(n);
    for(int i = 0 ; i < n ; i ++){
        if(u == m)
            t[i] = a[v ++];
        else if(v == r)
            t[i] = a[u++];
        else if(a[u] > a[v])
            t[i] = a[v ++];
        else
            t[i] = a[u++];
    }
    for(int i = 0; i < n ; i ++) a[i + l] = t[i];
    //inplace_merge(a.begin()+l,a.begin()+m,a.begin()+r);
}
