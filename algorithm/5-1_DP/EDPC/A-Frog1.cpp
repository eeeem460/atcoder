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


// https://atcoder.jp/contests/dp/tasks/dp_a


int main() {
    int n; cin >> n;
    vector<int> h(n); for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (i + 1 < n) chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        if (i + 2 < n) chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }

    cout << dp[n-1] << endl;
}
