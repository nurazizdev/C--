#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define str string
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define all(x) x.begin() , x.end()
#define setpr(x) cout << fixed << setprecision(x) 
#define endl '\n'
 
const int inf = INT_MAX;
const ld eps = 1e-9 , pi = acos(-1.0);
const ll mod = 1e9 + 7; // 998244353;
const int dx[4]{1 , 0 , -1 , 0} , dy[4]{0 , 1 , 0 , -1};

// int binpow(int a, int b, int m) {
//     a %= m;
//     int res = 1;
//     while (b > 0) {
//         if (b & 1) res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

// str dec_to_any(int n , int p){
//     str s = "";
//     do{
//         int r = n % p;
//         int it = (r < 10) ? 48 : 55;
//         s = char(r + it) + s;
//         n = (n - r) / p;
//     }while(n);
//     return s;
// }

// int any_to_dec(str s , int p){
//     return stoi(s , nullptr , p);
// }

// double area(int x1 , int y1 , int x2 , int y2 , int x3 , int y3){
//     return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
// }



// vector<int> pref_function(str s){
//     int n = s.size();
//     vector<int> p(n);
//     for(int i = 1 ; i < n ; i ++){
//         int j = p[i - 1];
//         while(j > 0 && s[i] != s[j]) j = p[j - 1];
//         if(s[i] == s[j]) j ++;
//         p[i] = j;
//     }
//     return p;
// }



// vector<int> z_function(str s){
//     int n = s.size();
//     vector<int> z(n);
//     for(int i = 1 , l = 0 , r = 0 ; i < n ; i ++){
//         if(i <= r) z[i] = min(z[i - l] , r - i + 1);
//         while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] ++;
//         if(i + z[i] - 1 > r) l = i , r = i + z[i] - 1;
//     }
//     return z;
// }



// vector<int> manakerd1(str s){
//     int n = s.size();
//     vector<int> d(n);
//     for(int i = 0 , r = -1 , j = 0 ; j < n ; j ++){
//         if(j <= r) d[j] = min(d[2 * i - j] , r - j + 1);
//         while(j - d[j] >= 0 && j + d[j] < n &&
//             s[j - d[j]] == s[j + d[j]]) d[j]++;
//         if(d[j] + j - 1 > r) i = j , r = d[j] + j - 1;
//     }
//     return d;
// }



// vector<int> manakerd2(str s){
//     int n = s.size();
//     vector<int> d(n);
//     for(int i = 0 , r = -1 , j = 0 ; j < n ; j ++){
//         if(j<=r) d[j] = min(d[2 * i - j] , r - j + 1);
//         while(j - d[j] - 1 >= 0 && j + d[j] < n &&
//             s[j - d[j] - 1] == s[j + d[j]]) d[j]++;
//         if(d[j] + j - 1 > r) i = j , r = d[j] + j - 1;
//     }
//     return d;
// }



// int hash(str s, int x){
//     int n = s.size();
//     int res = 0 , p = 1;
//     for (int i = 0 ; i < n ; i ++){
//         res += (s[i] - '0') * p % mod;
//         p = p * x % mod;
//     }
//     return res % mod;
// }



// vector<int> suffix_array(str s){
//     int n = s.size();
//     vector<pair<pair<int , int> , int>> a(n);
//     vector<int> c(n);
//     for(int i = 0 ; i < n ; i ++)
//         a[i] = {{s[i] , s[i]} , i};
//     auto func = [&](){
//         sort(all(a));
//         int classes = 0;
//         c[a[0].second] = classes;
//         for(int i = 1 ; i < n ; i ++){
//             if(a[i].first != a[i - 1].first) classes++;
//             c[a[i].second] = classes;
//         }
//     };
//     func();
//     for(int h = 0 ; (1 << h) < n ; h ++){
//         for(int i = 0 ; i < n ; i ++)
//             a[i] = {{c[i] , c[(i + (1 << h)) % n]} , i};
//         func();
//     }
//     for(int i = 0 ; i < n ; i ++) c[i] = a[i].second;
//     return c;
// } 




//     int n; cin >> n;
//     vector<int> a(n) , bn(n + 1);

//     for(int &x : a) cin >> x;
//     for(int i = 2 ; i <= n ; i ++) bn[i] = bn[i >> 1] + 1;

//     vector<vector<int>> dp(bn[n] + 1);
//     dp[0] = a;
//     for(int i = 1 , k; i < dp.size() ; i ++){
//         dp[i].resize(n - (1 << i) + 1);
//         k = 1 << (i - 1);
//         for(int j = 0 ; j < dp[i].size() ; j ++)
//             dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j + k]); 
//     }

//     int q; cin >> q;
//     for(int i = 0 , l , r , k; i < q ; i ++){
//         cin >> l >> r; l --; r --;
//         k = bn[r - l + 1];
//         cout << min(dp[k][l] , dp[k][r - (1 << k) + 1]) << ' ';
//     }



// in --> sqrt_decomposition.cpp



// vector<int> t;

// void add(int i , int delta){
//     for(;i < t.size(); i = i | (i + 1))
//         t[i] += delta;
// }

// int rsq(int i){
//     long long res = 0;
//     for(;i >= 0 ; i = (i & (i + 1)) - 1)
//         res += t[i];
//     return res;
// }

// int get(int l , int r){
//     return rsq(r) - rsq(l - 1);
// }



// int n;
// vector<vector<int>> g;
// vector<int> dist;

// void bfs(int v){
//     queue<int> q;
//     auto add = [&](int i , int p){
//         if(dist[i] == -1){
//             dist[i] = p;
//             q.push(i);
//         }
//     };
//     add(v , 0);
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         for(int v : g[u]){
//             add(v , dist[u] + 1);
//         }
//     }
// }



// struct way{
//     int v , u , w;
// };

// void solution(){
//     int n , m;
//     cin >> n >> m;
//     vector<way> dp(m);
//     vector<int> res(n + 1, inf);
//     res[1] = 0;
//     for(auto &way : dp) cin >> way.v >> way.u >> way.w;
//     for(int i = 1 ; i < n ; i ++)
//         for(auto edge : dp)
//             if(res[edge.v] != 30000 && res[edge.u] > res[edge.v] + edge.w)
//                 res[edge.u] = res[edge.v] + edge.w;
// }   



// void dijskstre(){
//     vector<int> dist(n , inf);
//     set<pair<int , int>> st;
//     auto add = [&](int v , int h){
//         if(dist[v] > h){
//             st.erase({dist[v] , v});
//             dist[v] = h;
//             st.insert({dist[v] , v});
//         }
//     };
//     add(s, 0);
//     while(!st.empty()){
//         auto [v , a] = *st.begin();
//         st.erase(st.begin());
//         for(auto [b , V] : g[a])
//             add(b , V + v);
//     }
// }



// void karkas(){
//     set<pair<int , int>> st;
//     vector<int> h(n , inf);
//     auto add = [&](int j , int k){
//         if(!used[j] && h[j] > k){
//             st.erase({h[j] , j});
//             h[j] = k;
//             st.insert({h[j] , j});
//         }
//     };
//     int res = 0;
//     add(0 , 0);
//     used[0] = true;
//     while(!st.empty()){
//         auto [w , a] = *st.begin();
//         st.erase(st.begin());
//         used[a] = true;
//         res += w;
//         for(auto [b , w] : g[a]) add(b , w);
//     }
// }




// void make_set (int v) {
// 	parent[v] = v;
// 	rank[v] = 0;
// }
 
// int find_set (int v) {
// 	if (v == parent[v])
// 		return v;
// 	return parent[v] = find_set (parent[v]);
// }
 
// void union_sets (int a, int b) {
// 	a = find_set (a);
// 	b = find_set (b);
// 	if (a != b) {
// 		if (rank[a] < rank[b])
// 			swap (a, b);
// 		parent[b] = a;
// 		if (rank[a] == rank[b])
// 			++rank[a];
// 	}
// }





// int n;
// vector<int> adj[maxn];
// int subtree_size[maxn];

// int get_subtree_size(int node, int parent = -1) {
// 	int &res = subtree_size[node];
// 	res = 1;
// 	for (int i : adj[node]) {
// 		if (i == parent) { continue };
// 		res += get_subtree_size(i, node);
// 	}
// 	return res;
// }

// int get_centroid(int node, int parent = -1) {
// 	for (int i : adj[node]) {
// 		if (i == parent) { continue };

// 		if (subtree_size[i] * 2 > n) { return get_centroid(i, node); }
// 	}
// 	return node;
// }

// int main() {
// 	cin >> n;
// 	for (int i = 0; i < n - 1; i++) {
// 		int a, b;
// 		cin >> a >> b;
// 		a--;
// 		b--;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}

// 	get_subtree_size(0);
// 	cout << get_centroid(0) + 1 << endl;
// }





// struct stack{
//     vector<int> s , sgcd; 
//     void push(int x){
//         s.push_back(x);
//         sgcd.push_back(sgcd.empty() ? x : ::gcd(sgcd.back() , x));
//     }
//     int pop(){
//         int res = s.back();
//         s.pop_back();
//         sgcd.pop_back();
//         return res;
//     }
//     bool empty(){
//         return s.empty();
//     }
//     int gcd(){
//         return sgcd.empty() ? 0 : sgcd.back();
//     }
// };
 
// ::stack s1 , s2;
 
// void add(int x){
//     s2.push(x);
// }
 
// void remove(){
//     if(s1.empty()){
//         while(!s2.empty()){
//             s1.push(s2.pop());
//         }
//     }
//     s1.pop();
// }
 
// bool good(){
//     int g = gcd(s1.gcd(), s2.gcd());
//     return g == 1;
// }
 
// void solution(){
//     int n , res = LLONG_MAX; cin >> n;
//     vector<int> a(n);
//     for(int &x : a) cin >> x;
//     for(int r = 0 , l = 0 ; r < n ; r ++){
//         add(a[r]);
//         while(good()){
//             remove();
//             l++;
//         }
//         if(l != 0)
//         res = min(res , r - l + 1);
//     }
//     if(res == LLONG_MAX) cout << -1;
//     else cout << res + 1;
// }


// int k;
// multiset<int> up , low;
 
// void ins(int val){
//     int x = *low.rbegin();
//     if(val > x){
//         up.insert(val);
//         if(up.size() > k / 2){
//             low.insert(*up.begin());
//             up.erase(up.find(*up.begin()));
//         }
//     }
//     else{
//         low.insert(val);
//         if(low.size() > (k + 1) / 2){
//             up.insert(*low.rbegin());
//             low.erase(low.find(*low.rbegin()));
//         }
//     }
// }
 
// void era(int val){
//     if(up.find(val) != up.end()) up.erase(up.find(val));
//     else low.erase(low.find(val));
//     if(low.empty()){
//         low.insert(*up.begin());
//         up.erase(up.find(*up.begin()));
//     }
// }
 
// void solution(){
//     int n; cin >> n >> k;
//     vector<int> a(n);
//     for(int &x : a) cin >> x;
//     low.insert(a[0]);
//     for(int i = 1 ; i < k ; i ++) ins(a[i]);
//     cout << *low.rbegin() << " ";
//     for(int i = k ; i < n ; i ++){
//         if(k == 1){
//             ins(a[i]);
//             era(a[i - k]);
//         }
//         else{
//             era(a[i - k]);
//             ins(a[i]);
//         }
//         cout << *low.rbegin() << " ";
//     }
// }

void solution(){
    
}  
 
signed main(){
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1; // cin >> t;
    while(t --) solution();
}   