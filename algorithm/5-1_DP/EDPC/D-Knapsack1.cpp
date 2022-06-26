#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/dp/tasks/dp_d


int main() {
    int n, W; cin >> n >> W;
    vector<int> w(n+1), v(n+1); for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(n+1, vector<ll>(W+1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            chmax(dp[i][j], dp[i-1][j]);
            if (j - w[i] >= 0) chmax(dp[i][j], dp[i-1][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][W] << endl;
}
