#include <bits/stdc++.h>
using namespace std;

#define int long long
 
const int inf = LLONG_MAX;

vector<int> a , sum , mn , ad , up;
int len , n;
 
int get(int i){
    int id = i / len;
    if(up[id] == -1) return a[i] + ad[id];
    else return up[id] + ad[id];
};

inline int first_id(int id){
    return id * len;
};
inline int last_id(int id){
    return min(n - 1 , first_id(id) + len - 1);
};

void update(int id , int l , int r , int new_val){
    if(up[id] != -1){
        for(int i = first_id(id) ; i <= last_id(id) ; i++) a[i] = up[id];
        up[id] = -1; 
    }
    new_val = new_val - ad[id];
    for(int i = l ; i <= r ; i++) a[i] = new_val;
    sum[id] = ad[id] * (last_id(id) - first_id(id) + 1);
    mn[id] = inf; 
    for(int i = first_id(id) ; i <= last_id(id) ; i++) {
        sum[id] += a[i];
        mn[id] = min(mn[id] , a[i]);
    }
    mn[id] += ad[id];
}

void update(int l , int r , int new_val){
    int lid = l / len , rid = r / len;
    if(lid == rid){
        if(l == first_id(lid) && r == last_id(rid)){
            up[lid] = new_val;
            ad[lid] = 0;
            sum[lid] = new_val * (r - l + 1);
            mn[lid] = new_val;
        }
        update(lid , l , r , new_val);
        return ;
    }
    if(l != first_id(lid)){
        update(lid , l , last_id(lid) , new_val);
        lid ++;
    }
    if(r != last_id(rid)){
        update(rid , first_id(rid) , r , new_val);
        rid --;
    }
    for(int i = lid ; i <= rid ; i++){
        up[i] = new_val;  
        ad[i] = 0;
        mn[i] = new_val;
        sum[i] = new_val * (last_id(i) - first_id(i) + 1); 
    }
};

void add(int id , int l , int r , int x){
    if(up[id] != -1){
        for(int i = first_id(id) ; i <= last_id(id) ; i++) a[i] = up[id];
        up[id] = -1; 
    } 
    for(int i = l ; i <= r ; i++) a[i] += x;
    sum[id] += x * (r - l + 1);
    mn[id] = inf; 
    for(int i = first_id(id) ; i <= last_id(id) ; i++) {
         mn[id] = min(mn[id] , a[i]);
    }
    mn[id] += ad[id];
}

void add(int l , int r , int add_val){
    int lid = l / len , rid = r / len;
    if(lid == rid){
        if(l == first_id(lid) && r == last_id(rid)){
            ad[lid] += add_val;
            sum[lid] += add_val * (r - l + 1);
            mn[lid] += add_val;
            return ;
        }
        add(lid , l , r , add_val);
        return;
    }
    if(l != first_id(lid)){
        add(lid , l , last_id(lid) , add_val);
        lid ++;
    }
    if(r != last_id(rid)){
        add(rid , first_id(rid) , r , add_val);
        rid --;
    }
    for(int i = lid ; i <= rid ; i++){
        ad[i] += add_val;
        sum[i] += add_val * (last_id(i) - first_id(i) + 1);
        mn[i] += add_val;
    }
};

int rsq(int id , int l , int r){
    if(up[id] != -1) return (r - l + 1) * (up[id] + ad[id]);
    int h = 0;
    for(int i = l ; i <= r ; i ++) h += a[i];
    return h + ad[id] * (r - l + 1);
}

int rsq(int l , int r){
    int lid = l / len , rid = r / len ;
    if(lid == rid){
        if(l == first_id(lid) && r == last_id(rid))
            return sum[lid];
        return rsq(lid , l , r);
    }
    int h = 0;
    if(l != first_id(lid)){
        h += rsq(lid , l , last_id(lid));
        lid ++;
    }
    if(r != last_id(rid)){
        h += rsq(rid , first_id(rid) , r);
        rid --;
    }
    for(int i = lid ; i <= rid ; i++) h += sum[i];
    return h;
};

int rmq(int id , int l , int r){
    if(up[id] != -1) return up[id] + ad[id];
    int h = inf;
    for(int i = l ; i <= r ; i++) h = min(h , a[i]);
    return h + ad[id];
}

int rmq(int l , int r){
    int lid = l / len , rid = r / len ;
    if(lid == rid){
        if((l == first_id(lid) && r == last_id(rid)) || up[lid] != -1)
            return mn[lid];
        return rmq(lid , l , r);
    }
    int h = inf;
    if(l != first_id(lid)){
        h = min(h , rmq(lid , l , last_id(lid)));
        lid ++;
    }
    if(r != last_id(rid)){
        h = min(h , rmq(rid , first_id(rid) , r));
        rid --;
    }
    for(int i = lid ; i <= rid ; i++) h = min(h , mn[i]);
    return h;
};

signed main(){
    cin >> n;
    len = (int) sqrt(n); 
    int LEN = (n + len - 1) / len;
    a.resize(n);
    ad.resize(LEN);
    up.resize(LEN , -1);
    sum.resize(LEN);
    mn.resize(LEN , inf);
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
        sum[i / len] += a[i];
        mn[i / len] = min(mn[i / len] , a[i]);
    }
    int q , l , r , x;
    string satr;
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        cin >> satr;
        if(satr == "add"){
            cin >> l >> r >> x;
            add(l - 1, r - 1, x);
        }
        else if(satr == "update"){
            cin >> l >> r >> x;
            update(l - 1, r - 1, x);
        }
        else if(satr == "rsq"){
            cin >> l >> r;
            cout << rsq(l - 1, r - 1) << endl;
        }
        else if(satr == "rmq"){
            cin >> l >> r;
            cout << rmq(l - 1, r - 1) << endl;
        }
        else{
            cin >> x;
            cout << get(x - 1) << endl;
        }
    }
}