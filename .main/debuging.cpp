#define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define str string
#define ld long double
#define ll long long
#define ull unsigned long long
#define endl '\n'
    
const ld eps = 1e-9;
const ll inf = 1e18 , MOD = 1e9 + 7;
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int x = 10; 

void prints_line(){
    dbg(x);
	x = 5000;
	dbg(x); 
}
#include "debugging.h"

void prints_vector(){
    vector<int> arr{1, 2, 3, 4};
	cout << arr << endl;  // just feed it into cout like any other variable
}

void usaco2(){
    assert(false);
	cout << "OK" << endl;
}   

void solution(){
    int n;
    cin >> n;
    cerr << n;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t --) solution();
    return 0;
}