#include <bits/stdc++.h>
using namespace std;
 
signed main(){
    int n; cin >> n;
    vector<int> a(n) , bn(n + 1);

    for(int &x : a) cin >> x;
    for(int i = 2 ; i <= n ; i ++) bn[i] = bn[i >> 1] + 1;

    vector<vector<int>> dp(bn[n] + 1);
    dp[0] = a;
    for(int i = 1 , k; i < dp.size() ; i ++){
        dp[i].resize(n - (1 << i) + 1);
        k = 1 << (i - 1);
        for(int j = 0 ; j < dp[i].size() ; j ++)
            dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j + k]); 
    }

    int q; cin >> q;
    for(int i = 0 , l , r , k; i < q ; i ++){
        cin >> l >> r; l --; r --;
        k = bn[r - l + 1];
        cout << min(dp[k][l] , dp[k][r - (1 << k) + 1]) << ' ';
    }
}