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


// https://atcoder.jp/contests/dp/tasks/dp_b


int main() {
    int n, k; cin >> n >> k;
    vector<int> h(n); for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j < n) chmin(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
        }
    }   

    cout << dp[n-1] << endl;
}
