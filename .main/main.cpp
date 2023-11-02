#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define str string
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin() , x.end()
#define setpr(x) cout << fixed << setprecision(x) 
#define endl '\n'
 
const int inf = INT_MAX;
const ld eps = 1e-9 , pi = acos(-1.0);
const ll mod = 1e9 + 7; // 998244353;
const int dx[4]{1 , 0 , -1 , 0} , dy[4]{0 , 1 , 0 , -1};

struct stack{
    vector<int> s , sgcd; 
    void push(int x){
        s.push_back(x);
        sgcd.push_back(sgcd.empty() ? x : ::gcd(sgcd.back() , x));
    }
    int pop(){
        int res = s.back();
        s.pop_back();
        sgcd.pop_back();
        return res;
    }
    bool empty(){
        return s.empty();
    }
    int gcd(){
        return sgcd.empty() ? 0 : sgcd.back();
    }
};

::stack s1 , s2;

void add(int x){
    s2.push(x);
}

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good(){
    int g = gcd(s1.gcd(), s2.gcd());
    return g == 1;
}

void solution(){
    int n , res = LLONG_MAX; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    for(int r = 0 , l = 0 ; r < n ; r ++){
        add(a[r]);
        while(good()){
            remove();
            l++;
        }
        if(l != 0)
        res = min(res , r - l + 1);
    }
    if(res == LLONG_MAX) cout << -1;
    else cout << res + 1;
}
 
signed main(){
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1; //cin >> t;
    while(t --) solution();
}