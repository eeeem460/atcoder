#include <bits/stdc++.h>
using namespace std;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/dp/tasks/dp_e


int main() {
    int n, W; cin >> n >> W;
    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    vector<vector<int>> dp(n+1, vector<int>(100001, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (j - v[i] >= 0) chmin(dp[i][j], dp[i-1][j - v[i]] + w[i]);
            chmin(dp[i][j], dp[i-1][j]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100000; i++) {
        if (dp[n][i] <= W) chmax(ans, i);
    }
    cout << ans << endl;
}
