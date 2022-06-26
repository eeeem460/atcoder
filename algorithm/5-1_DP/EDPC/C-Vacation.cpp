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


// https://atcoder.jp/contests/dp/tasks/dp_c


int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = max(dp[i-1][(j+1) % 3] + a[i][j], dp[i-1][(j+2) % 3] + a[i][j]);
        }
    }

    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;
}
