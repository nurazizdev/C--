#include <bits/stdc++.h>
using namespace std;

using rmq1d_test = vector<vector<int>> ;
using rmq2d_test = vector<vector<rmq1d_test>>;

vector<int> bn;
 
rmq1d_test MIN(rmq1d_test &a, rmq1d_test &b){
    rmq1d_test c = a;
    for(int i = 0 ; i < c.size() ; i++)
        for(int j = 0 ; j < c[i].size() ; j++)
            c[i][j] = min(c[i][j], b[i][j]);
    return c;
}
 
rmq1d_test rmq1d(vector<int> &a){
    int n = a.size();   
    rmq1d_test dp(bn[n] + 1);
    dp[0].resize(n);
    for(int i = 0 ; i < n ; i++) dp[0][i] = a[i];
    for(int i = 1 , k; i < dp.size() ; i++){
        dp[i].resize(n - (1 << i) + 1);
        k = 1 << (i - 1);
        for(int j = 0 ; j < dp[i].size() ; j++)
            dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j + k]);
    }
    return dp;  
}
 
rmq2d_test rmq2d(vector<vector<int>> &a){
    int n = a.size();
    rmq2d_test dp(bn[n] + 1);
    dp[0].resize(n);
    for(int i = 0 ; i < n ; i++) dp[0][i] = rmq1d(a[i]);
    for(int i = 1 , k; i < dp.size() ; i++){
        dp[i].resize(n - (1 << i) + 1);
        k = 1 << (i - 1);
        for(int j = 0 ; j < dp[i].size() ; j++)
            dp[i][j] = MIN(dp[i - 1][j], dp[i - 1][j + k]);
    }
    return dp;  
}
 
signed main(){
    int n , m , k;
    cin >> n >> m >> k;
    rmq1d_test a(n,vector<int>(m));
    bn.resize(max(n,m)+1);
    for(int i = 2 ; i < bn.size(); i++) bn[i] = bn[i >> 1] + 1;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> a[i][j];
    rmq2d_test rmq = rmq2d(a);
    int x1 , y1 , x2 , y2 , u , q ;
    for(int i = 0 ; i < k; i++ ){
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        q = bn[x2 - x1 +1];
        u = bn[y2 - y1 +1];
        cout << min({rmq[q][x1][u][y1] , rmq[q][x1][u][y2 - (1 << u) + 1] ,
                            rmq[q][x2 - (1 << q) + 1][u][y1] , 
                    rmq[q][x2 - (1 << q) + 1][u][y2 - (1 << u) + 1]}) << endl;
    }
}