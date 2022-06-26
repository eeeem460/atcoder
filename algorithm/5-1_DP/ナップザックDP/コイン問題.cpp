#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja


int main() {
    int n, m; cin >> n >> m;
    vector<int> c(m); for (int i = 0; i < m; i++) cin >> c[i];

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - c[j] >= 0) chmin(dp[i], dp[i - c[j]] + 1);
        }
    }

    cout << dp[n] << endl;
}
